#pragma once

#include "Iron.h"
#include <cliext/vector> 

using namespace System;
using namespace System::Xml;
using namespace cliext;
using namespace System::Windows::Forms;
using namespace System::Data::SQLite;
using namespace System::Data;
using namespace System::Text;

ref class VectorI {
public:
	VectorI();
	VectorI(String^, bool, String^);
	String^ getInfoText(DataGridView^, String^);
	DataTable^ getInfo(String^, String^);
	DataTable^ AddRow(String^, String^, String^, String^, String^, String^);
	void DelRow(int);
	DataTable^ getRowId();
	void AllDelRow(String^);
	DataTable^ ShowTable(String^);
	DataTable^ AddRecord(DataGridView^);
	DataTable^ UpdateRecord(DataGridView^, String^);
	DataTable^ Search(DataGridView^, String^, String^, String^);
	vector<String^>^ getTableName();
	String^ getLastCommandUpdate();
	String^ getNameRowColumn();
private:
	String^ LastCommandUpdate;
	vector<String^>^ tableName;
	String^ fileName;
	String^ tableChoose;
	String^ NameRowColumn;
};

VectorI::VectorI() {
	fileName = "";
	tableChoose = "";
	NameRowColumn = "";
}

String^ VectorI::getNameRowColumn() { return NameRowColumn; }

VectorI::VectorI(String^ fileName, bool show, String^ tableChoose) {
	NameRowColumn = "";
	this->fileName = fileName;
	this->tableChoose = tableChoose;
	if (show)
		getInfo(this->fileName, tableChoose);
}

String ^ VectorI::getInfoText(DataGridView^ mytable, String^ nameTable) {
	String^ info = "";
	if (mytable->Rows->Count > 0)
	info += "~~~~~~~~~~~~~~~~~~~~~~~~~";
	for (int j = 0; j < mytable->Rows->Count; j++)
	{
			for (int i = 0; i < mytable->ColumnCount; i++)
				info += "\r\n" + mytable->Columns[i]->HeaderText->ToString() + " = " + mytable->Rows[j]->Cells[i]->Value->ToString();
			info += "\r\n~~~~~~~~~~~~~~~~~~~~~~~~~";
	}
	return info;
}

DataTable ^ VectorI::getInfo(String ^ fileName, String^ tableChoose) {
	


	this->fileName = fileName;

	SQLiteConnection^ db;
	SQLiteCommand^ cmdRowID;
	SQLiteCommand^ cmdSelect;
	vector<String^>^ NameTable; // Вектор названий таблиц
	DataTable^ nulltable; //Невидимая таблица данных (NULL)
	DataColumn^ nullcolumn; //Столбец таблицы (NULL)
	DataRow^ nullrow; //Строка таблицы (NULL)
	SQLiteDataReader^ readerRow;
	vector<String^>^ cellDataRow;
	SQLiteDataReader^ reader;
	DataTable ^table; //Невидимая таблица данных
	DataColumn ^column; //Столбец таблицы
	DataRow ^row; //Строка таблицы
	vector<String^>^ nameColumns;
	vector<String^>^ nameColumnsPlus;
	try
	{
		db = gcnew SQLiteConnection();
		db->ConnectionString = "Data Source=\"" + fileName + "\""; // Настройки подключения к БД
		db->SetPassword("123");
		db->Open(); // Открываем БД
		try
		{
			cmdRowID = db->CreateCommand(); // Создаём экземпляр для работы с БД
			cmdSelect = db->CreateCommand(); // Создаём экземпляр для работы с БД

			NameTable = gcnew vector<String^>;
			if (getTableName()->size() != 0) // Если возвращаемый вектор не пуст
				NameTable = getTableName(); // Копируем все данные в NameTable
			else // Иначе выводим в таблицу Столбец - NULL, с ячейкой - Таблиц не найдено
			{
				MessageBox::Show("Таблиц в базе данных не найдено", "Ошибка ...");
				nulltable = gcnew DataTable();
				nullcolumn = gcnew DataColumn("NULL", String::typeid);
				nulltable->Columns->Add(nullcolumn);
				nullrow = nulltable->NewRow();
				nullrow["NULL"] = "Таблиц не найдено";
				nulltable->Rows->Add(nullrow);
				return nulltable;
			}

			if (tableChoose == "") // Если таблица для вывода не выбиралась
			{
				cmdRowID->CommandText = "SELECT `_rowid_` FROM `" + NameTable->at(0) + "` ORDER BY `_rowid_` ASC LIMIT 0, 200000000;";
				cmdSelect->CommandText = "SELECT * FROM " + NameTable->at(0) + ";"; // Выводим 1
			}
			else
			{
				cmdRowID->CommandText = "SELECT `_rowid_` FROM `" + tableChoose + "` ORDER BY `_rowid_` ASC LIMIT 0, 200000000;";
				cmdSelect->CommandText = "SELECT * FROM " + tableChoose + ";"; // Выводим выбранную
			}

			///////////////////////////////////THE START - Находим _rowid_ - THE START///////////////////////////////

			readerRow = cmdRowID->ExecuteReader(); // Создаём экземляр для чтения таблицы

			//Название столбца _rowid_
			String^ NameColumnRowID = readerRow->GetName(0);
			
			//Передаем значение в глобальную переменную
			NameRowColumn = NameColumnRowID;
			
			//Вектор данных столбца _rowid_
			cellDataRow = gcnew vector<String^>();

			//Заполняем данными вектор cellDataRow
			while (readerRow->Read())
				for (int i = 0; i < readerRow->FieldCount; i++) 
					 cellDataRow->push_back(readerRow->GetValue(i)->ToString());
			
			///////////////////////////////////THE END - Находим _rowid_ - THE END///////////////////////////////////

			reader = cmdSelect->ExecuteReader(); // Создаём экземляр для чтения таблицы
		
			//В table будем записывать итоговый результат
			//Создаем таблицу данных
			table = gcnew DataTable();

			//Вектор названий столбцов
			nameColumns = gcnew vector<String^>();

			//Заполним вектор данными о столбцах
			for (int i = 0; i < reader->FieldCount; i++)
				nameColumns->push_back(reader->GetName(i));

			bool checkColumn = false;
			//Проверим на дубликат названия столбцов
			for (int i = 0; i < nameColumns->size(); ++i)
				if (NameColumnRowID == nameColumns->at(i))
					checkColumn = true;

			//Вектор столбцов + NameColumnRowID (переменная)
			nameColumnsPlus = gcnew vector<String^>();

			//Заполним данные о столбцах
			if (checkColumn)
				for (int i = 0; i < reader->FieldCount; i++) {
					column = gcnew DataColumn(reader->GetName(i), String::typeid);
					table->Columns->Add(column);
				}
			else
			{
				//Если дубликатов столбцов нет, создадим новый вектор с доп. названием NameColumnRowID
				nameColumnsPlus->push_back(NameColumnRowID);
				for (int i = 0; i < nameColumns->size(); ++i)
					nameColumnsPlus->push_back(nameColumns->at(i));

				for (int i = 0; i < nameColumnsPlus->size(); i++) {
					column = gcnew DataColumn(nameColumnsPlus->at(i), String::typeid);
					table->Columns->Add(column);
				}
			}
			
			//Заполняем строчки и добавляем в таблицу
			int j = 0; //Счётчик для cellDataRow
			while (reader->Read()) {
				row = table->NewRow();
				if (checkColumn)
					for (int i = 0; i < reader->FieldCount; i++)
						row[nameColumns->at(i)] = reader->GetValue(i)->ToString();
				else
					for (int i = 0; i < nameColumnsPlus->size(); i++)
						if (i == 0)
						{
							row[nameColumnsPlus->at(0)] = cellDataRow->at(j);
							j++;
						}
						else row[nameColumnsPlus->at(i)] = reader->GetValue(i - 1)->ToString();
				table->Rows->Add(row);
			}

			//Выводим результат
			return table;
		}
		catch (Exception ^e)
		{
			MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
			this->fileName = "";
			DataTable ^ErrorV = gcnew DataTable();
			return ErrorV;
		}
	}
	catch (Exception ^e)
	{
		MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
		this->fileName = "";
		DataTable ^ErrorV = gcnew DataTable();
		return ErrorV;
	}
	finally
	{
		delete	(IDisposable^)db,
				(IDisposable^)cmdSelect,
				(IDisposable^)cmdRowID,
				(IDisposable^)NameTable,
				(IDisposable^)nulltable,
				(IDisposable^)nullcolumn,
				nullrow,
				(IDisposable^)readerRow,
				(IDisposable^)cellDataRow,
				(IDisposable^)reader,
				(IDisposable^)table,
				(IDisposable^)column,
				row,
				(IDisposable^)nameColumns,
				(IDisposable^)nameColumnsPlus;
	}
}

DataTable ^ VectorI::AddRow(String^ material, String^ category,
	String^ content, String^ meltingtemp, String^ density, String^ structure) {
	SQLiteConnection ^db = gcnew SQLiteConnection();
	if (this->fileName != "" && material != "" && category != "" 
		&& content != "" && meltingtemp != "" && density != "" && structure != "")
	{
		try
		{
			db->ConnectionString = "Data Source=\"" + this->fileName + "\"";
			db->Open();
			DataTable ^table;
			try
			{
				SQLiteCommand ^cmdInsertValue = db->CreateCommand();
				cmdInsertValue->CommandText = "INSERT INTO iron (material, category, content, meltingtemp, density, structure) VALUES('" + material + "','" + category + "','" + content + "','" + meltingtemp + "','" + density + "','" + structure + "');";
				cmdInsertValue->ExecuteNonQuery();

				table = getInfo(fileName, "iron");
			}
			catch (Exception ^e)
			{
				MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
				DataTable ^ErrorV = gcnew DataTable();
				return ErrorV;
			}
			return table;
		}
		finally
		{
			delete(IDisposable^)db;
		}
	}
	else
	{
		if (fileName == "")
		{
			MessageBox::Show("Добавить не удалось, база данных не открыта.", "Ошибка ...");
			DataTable ^ErrorV = gcnew DataTable();
			return ErrorV;
		}
		else
		{
			MessageBox::Show("Добавить не удалось, один из параметров пуст.", "Ошибка ...");
			DataTable ^table = getInfo(fileName, "iron");
			return table;
		}
	}
}

DataTable ^ VectorI::getRowId()
{
	this->fileName = fileName;
	SQLiteConnection ^db = gcnew SQLiteConnection();
	try
	{
		db->ConnectionString = "Data Source=\"" + fileName + "\"";
		db->Open();
		try
		{
			SQLiteCommand ^cmdSelect = db->CreateCommand();

			vector<String^>^ NameTable = gcnew vector<String^>;

			if (getTableName() != nullptr)
				NameTable = getTableName();
			else
			{
				MessageBox::Show("Таблиц в базе данных не найдено", "Ошибка ...");
				DataTable^ asd = gcnew DataTable();
				DataColumn^ column = gcnew DataColumn("INFO", String::typeid);
				asd->Columns->Add(column);
				DataRow ^row;
				row = asd->NewRow();
				row["INFO"] = "Таблиц не найдено";
				asd->Rows->Add(row);
				return asd;
			}

			//Обратите внмиание, что SQL запрос оформляем как обычную строчку
			bool check = false;
			cmdSelect->CommandText = "SELECT `_rowid_` FROM `" + tableChoose + "` ORDER BY `_rowid_` ASC LIMIT 0, 200000000;";
			SQLiteDataReader ^reader = cmdSelect->ExecuteReader();

			//В table будем записывать итоговый результат
			DataTable ^table; //Невидимая таблица данных
			DataColumn ^column; //Столбец таблицы
			DataRow ^row; //Строка таблицы

						  //Создаем таблицу данных
			table = gcnew DataTable();

			//Вектор названий столбцов
			vector<String^>^ nameColumns = gcnew vector<String^>();

			//Заполним данные о столбцах
			for (int i = 0; i < reader->FieldCount; i++) {
				nameColumns->push_back(reader->GetName(i));
				column = gcnew DataColumn(reader->GetName(i), String::typeid);
				table->Columns->Add(column);
			}
			//Пробегаем по каждой записи
			while (reader->Read()) {
				//Заполняем строчку таблицы
				row = table->NewRow();
				//В каждой записи пробегаем по всем столбцам
				for (int i = 0; i < reader->FieldCount; i++) {
					//Добавлем значение столбца в row
					row[nameColumns->at(i)] = reader->GetValue(i)->ToString();
				}
				table->Rows->Add(row);
			}

			//Выводим результат
			return table;
		}
		catch (Exception ^e)
		{
			MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
			this->fileName = "";
			DataTable ^ErrorV = gcnew DataTable();
			return ErrorV;
		}
	}
	catch (Exception ^e)
	{
		MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
		this->fileName = "";
		DataTable ^ErrorV = gcnew DataTable();
		return ErrorV;
	}
	finally
	{
		delete (IDisposable^)db;
	}
}

void VectorI::DelRow(int ind)
{
	SQLiteConnection ^db = gcnew SQLiteConnection();
	if (this->fileName != "" && ind >= 0)
	{
		try
		{
			db->ConnectionString = "Data Source=\"" + this->fileName + "\"";
			db->Open();

			try
			{
				SQLiteCommand ^cmdInsertValue = db->CreateCommand();
				cmdInsertValue->CommandText = "DELETE FROM `" + tableChoose +"` WHERE `_rowid_`='" + ind + "';";
				cmdInsertValue->ExecuteNonQuery();
			}
			catch (Exception ^e)
			{
				MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception ...");
			}
		}
		finally
		{
			delete(IDisposable^)db;
		}
	}
	else
	{
		if (fileName == "")
		{
			MessageBox::Show("Удалить не удалось, база данных не открыта.", "Ошибка ...");
		}
		else
		{
			MessageBox::Show("Удалить не удалось, строка не выбрана.", "Ошибка ...");
		}
	}
}

vector<String^>^ VectorI::getTableName()
{
	SQLiteConnection ^db = gcnew SQLiteConnection();
	try
	{
		db->ConnectionString = "Data Source=\"" + fileName + "\"";
		db->Open();
		try
		{
			SQLiteCommand ^cmdSelect = db->CreateCommand();
			//Обратите внмиание, что SQL запрос оформляем как обычную строчку
			cmdSelect->CommandText = "SELECT name FROM sqlite_master WHERE type = 'table';";
			SQLiteDataReader ^reader = cmdSelect->ExecuteReader();

			//В table будем записывать итоговый результат
			DataTable ^table; //Невидимая таблица данных
			DataColumn ^column; //Столбец таблицы
			DataRow ^row; //Строка таблицы

			//Создаем таблицу данных
			table = gcnew DataTable();

			//Вектор названий столбцов
			vector<String^>^ nameColumns = gcnew vector<String^>();

			//Заполним данные о столбцах
			for (int i = 0; i < reader->FieldCount; i++) {
				nameColumns->push_back(reader->GetName(i));
				column = gcnew DataColumn(reader->GetName(i), String::typeid);
				table->Columns->Add(column);
			}
			//Пробегаем по каждой записи
			vector<String^>^ NameTable = gcnew vector<String^>;
			while (reader->Read()) {
				//Заполняем строчку таблицы
				row = table->NewRow();
				//В каждой записи пробегаем по всем столбцам
				for (int i = 0; i < reader->FieldCount; i++) {
					//Добавлем значение столбца в row
					row[nameColumns->at(i)] = reader->GetValue(i)->ToString();
					NameTable->push_back(reader->GetValue(i)->ToString());
				}
				table->Rows->Add(row);
			}

			//Выводим результат
			return NameTable;
		}
		catch (Exception ^e)
		{
			MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
			this->fileName = "";
			vector<String^>^ ErrorV = gcnew vector<String^>;
			return ErrorV;
		}
	}
	catch (Exception ^e)
	{
		MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
		this->fileName = "";
		vector<String^>^ ErrorV = gcnew vector<String^>;
		return ErrorV;
	}
	finally
	{
		delete (IDisposable^)db;
	}
}

DataTable ^ VectorI::ShowTable(String ^ tableName)
{
	return getInfo(fileName, tableName);
}

void VectorI::AllDelRow(String^ nameTable)
{
	SQLiteConnection ^db = gcnew SQLiteConnection();
	if (this->fileName != "")
	{
		try
		{
			db->ConnectionString = "Data Source=\"" + this->fileName + "\"";
			db->Open();

			try
			{
				SQLiteCommand ^cmdInsertValue = db->CreateCommand();
				cmdInsertValue->CommandText = "DELETE FROM " + nameTable + ";";
				cmdInsertValue->ExecuteNonQuery();
			}
			catch (Exception ^e)
			{
				MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception ...");
			}
		}
		finally
		{
			delete(IDisposable^)db;
		}
	}
	else
	{
		if (fileName == "")
		{
			MessageBox::Show("Удалить не удалось, база данных не открыта.", "Ошибка ...");

		}
		else
		{
			MessageBox::Show("Удалить не удалось, строк нету.", "Ошибка ...");

		}
	}
}

DataTable ^ VectorI::AddRecord(DataGridView ^ mytable)
{
	String^ info;
	String^ values;
	if (mytable->ColumnCount > 0)
	{
		if (mytable->ColumnCount == 1)
		{
			info = mytable->Columns[0]->HeaderText;
			values = "''";
		}
		else
		{
			info = mytable->Columns[1]->HeaderText;
			values = "''";
			for (int i = 2; i < mytable->ColumnCount; ++i)
			{
				info += "," + mytable->Columns[i]->HeaderText;
				values += ",''";
			}
		}
	}

	SQLiteConnection ^db = gcnew SQLiteConnection();
	if (this->fileName != "")
	{
		try
		{
			db->ConnectionString = "Data Source=\"" + this->fileName + "\"";
			db->Open();
			DataTable ^table;
			try
			{
				SQLiteCommand ^cmdInsertValue = db->CreateCommand();
				cmdInsertValue->CommandText = "INSERT INTO " + tableChoose + " (" + info + ") VALUES(" + values + ");";
				cmdInsertValue->ExecuteNonQuery();

				table = getInfo(fileName, tableChoose);
			}
			catch (Exception ^e)
			{
				MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
				DataTable ^ErrorV = gcnew DataTable();
				return ErrorV;
			}
			return table;
		}
		finally
		{
			delete(IDisposable^)db;
		}
	}
	else
	{
		MessageBox::Show("Добавить не удалось, база данных не открыта.", "Ошибка ...");
		DataTable ^ErrorV = gcnew DataTable();
		return ErrorV;
	}
}

DataTable ^ VectorI::UpdateRecord(DataGridView ^ mytable, String^ onecell)
{
	String^ info;
	if (mytable->ColumnCount > 0)
	{
		if (mytable->ColumnCount == 1)
			info = mytable->Columns[0]->HeaderText + " = " + "'" + mytable->Rows[0]->Cells[0]->Value->ToString() + "'";
		else
		{
			info = mytable->Columns[0]->HeaderText + " = " + "'" + mytable->Rows[0]->Cells[0]->Value->ToString() + "'";
			for (int i = 1; i < mytable->ColumnCount; ++i)
				info += "," + mytable->Columns[i]->HeaderText + " = " + "'" + mytable->Rows[0]->Cells[i]->Value->ToString() + "'";
		}
	}

	SQLiteConnection ^db = gcnew SQLiteConnection();
	if (this->fileName != "")
	{
		try
		{
			db->ConnectionString = "Data Source=\"" + this->fileName + "\"";
			db->Open();
			DataTable ^table;
			try
			{
				SQLiteCommand ^cmdInsertValue = db->CreateCommand();
				cmdInsertValue->CommandText = "UPDATE " + tableChoose + " SET " + info + " WHERE " + "`_rowid_` = " + onecell + ";";
				LastCommandUpdate = "UPDATE " + tableChoose + " SET " + info + " WHERE " + "`_rowid_` = " + onecell + ";";
				cmdInsertValue->ExecuteNonQuery();

				table = getInfo(fileName, tableChoose);
			}
			catch (Exception ^e)
			{
				MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
				DataTable ^ErrorV = gcnew DataTable();
				return ErrorV;
			}
			return table;
		}
		finally
		{
			delete(IDisposable^)db;
		}
	}

	else
	{
		MessageBox::Show("Изменить не удалось, база данных не открыта.", "Ошибка ...");
		DataTable ^ErrorV = gcnew DataTable();
		return ErrorV;
	}
}

inline String ^ VectorI::getLastCommandUpdate()
{
	return LastCommandUpdate;
}

DataTable ^ VectorI::Search(DataGridView ^ mytable, String^ combo, String^ textbox, String^ searchsettings)
{
	vector<int>^ index = gcnew vector<int>;

	for (int i = 0; i < mytable->Columns->Count; ++i)
		if (combo == mytable->Columns[i]->HeaderText)
			for (int j = 0; j < mytable->Rows->Count; ++j)
				if (searchsettings == "first")
				{
					if (mytable->Rows[j]->Cells[i]->Value->ToString()->IndexOf(textbox) >= 0)
						index->push_back(j);
				}
				else
					if (textbox == mytable->Rows[j]->Cells[i]->Value->ToString())
						index->push_back(j);

	DataTable ^table; //Невидимая таблица данных
	DataColumn ^column; //Столбец таблицы
	DataRow ^row; //Строка таблицы

	//Создаем таблицу данных
	table = gcnew DataTable();

	//Вектор названий столбцов
	vector<String^>^ nameColumns = gcnew vector<String^>();

	//Заполним данные о столбцах
	for (int i = 0; i < mytable->Columns->Count; i++) {
		nameColumns->push_back(mytable->Columns[i]->HeaderText);
		column = gcnew DataColumn(mytable->Columns[i]->HeaderText, String::typeid);
		table->Columns->Add(column);
	}
	//В записи пробегаем по всем столбцам
	for (int j = 0; j < index->size(); ++j)
	{
		//Заполняем строчку таблицы
		row = table->NewRow();
		for (int i = 0; i < mytable->Columns->Count; i++) {
			//Добавлем значение столбца в row
			row[nameColumns->at(i)] = mytable->Rows[index->at(j)]->Cells[i]->Value->ToString();
		}
		table->Rows->Add(row);
	}

	return table;
}