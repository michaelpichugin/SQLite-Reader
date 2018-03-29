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
	vector<String^>^ NameTable; // ������ �������� ������
	DataTable^ nulltable; //��������� ������� ������ (NULL)
	DataColumn^ nullcolumn; //������� ������� (NULL)
	DataRow^ nullrow; //������ ������� (NULL)
	SQLiteDataReader^ readerRow;
	vector<String^>^ cellDataRow;
	SQLiteDataReader^ reader;
	DataTable ^table; //��������� ������� ������
	DataColumn ^column; //������� �������
	DataRow ^row; //������ �������
	vector<String^>^ nameColumns;
	vector<String^>^ nameColumnsPlus;
	try
	{
		db = gcnew SQLiteConnection();
		db->ConnectionString = "Data Source=\"" + fileName + "\""; // ��������� ����������� � ��
		db->SetPassword("123");
		db->Open(); // ��������� ��
		try
		{
			cmdRowID = db->CreateCommand(); // ������ ��������� ��� ������ � ��
			cmdSelect = db->CreateCommand(); // ������ ��������� ��� ������ � ��

			NameTable = gcnew vector<String^>;
			if (getTableName()->size() != 0) // ���� ������������ ������ �� ����
				NameTable = getTableName(); // �������� ��� ������ � NameTable
			else // ����� ������� � ������� ������� - NULL, � ������� - ������ �� �������
			{
				MessageBox::Show("������ � ���� ������ �� �������", "������ ...");
				nulltable = gcnew DataTable();
				nullcolumn = gcnew DataColumn("NULL", String::typeid);
				nulltable->Columns->Add(nullcolumn);
				nullrow = nulltable->NewRow();
				nullrow["NULL"] = "������ �� �������";
				nulltable->Rows->Add(nullrow);
				return nulltable;
			}

			if (tableChoose == "") // ���� ������� ��� ������ �� ����������
			{
				cmdRowID->CommandText = "SELECT `_rowid_` FROM `" + NameTable->at(0) + "` ORDER BY `_rowid_` ASC LIMIT 0, 200000000;";
				cmdSelect->CommandText = "SELECT * FROM " + NameTable->at(0) + ";"; // ������� 1
			}
			else
			{
				cmdRowID->CommandText = "SELECT `_rowid_` FROM `" + tableChoose + "` ORDER BY `_rowid_` ASC LIMIT 0, 200000000;";
				cmdSelect->CommandText = "SELECT * FROM " + tableChoose + ";"; // ������� ���������
			}

			///////////////////////////////////THE START - ������� _rowid_ - THE START///////////////////////////////

			readerRow = cmdRowID->ExecuteReader(); // ������ �������� ��� ������ �������

			//�������� ������� _rowid_
			String^ NameColumnRowID = readerRow->GetName(0);
			
			//�������� �������� � ���������� ����������
			NameRowColumn = NameColumnRowID;
			
			//������ ������ ������� _rowid_
			cellDataRow = gcnew vector<String^>();

			//��������� ������� ������ cellDataRow
			while (readerRow->Read())
				for (int i = 0; i < readerRow->FieldCount; i++) 
					 cellDataRow->push_back(readerRow->GetValue(i)->ToString());
			
			///////////////////////////////////THE END - ������� _rowid_ - THE END///////////////////////////////////

			reader = cmdSelect->ExecuteReader(); // ������ �������� ��� ������ �������
		
			//� table ����� ���������� �������� ���������
			//������� ������� ������
			table = gcnew DataTable();

			//������ �������� ��������
			nameColumns = gcnew vector<String^>();

			//�������� ������ ������� � ��������
			for (int i = 0; i < reader->FieldCount; i++)
				nameColumns->push_back(reader->GetName(i));

			bool checkColumn = false;
			//�������� �� �������� �������� ��������
			for (int i = 0; i < nameColumns->size(); ++i)
				if (NameColumnRowID == nameColumns->at(i))
					checkColumn = true;

			//������ �������� + NameColumnRowID (����������)
			nameColumnsPlus = gcnew vector<String^>();

			//�������� ������ � ��������
			if (checkColumn)
				for (int i = 0; i < reader->FieldCount; i++) {
					column = gcnew DataColumn(reader->GetName(i), String::typeid);
					table->Columns->Add(column);
				}
			else
			{
				//���� ���������� �������� ���, �������� ����� ������ � ���. ��������� NameColumnRowID
				nameColumnsPlus->push_back(NameColumnRowID);
				for (int i = 0; i < nameColumns->size(); ++i)
					nameColumnsPlus->push_back(nameColumns->at(i));

				for (int i = 0; i < nameColumnsPlus->size(); i++) {
					column = gcnew DataColumn(nameColumnsPlus->at(i), String::typeid);
					table->Columns->Add(column);
				}
			}
			
			//��������� ������� � ��������� � �������
			int j = 0; //������� ��� cellDataRow
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

			//������� ���������
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
			MessageBox::Show("�������� �� �������, ���� ������ �� �������.", "������ ...");
			DataTable ^ErrorV = gcnew DataTable();
			return ErrorV;
		}
		else
		{
			MessageBox::Show("�������� �� �������, ���� �� ���������� ����.", "������ ...");
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
				MessageBox::Show("������ � ���� ������ �� �������", "������ ...");
				DataTable^ asd = gcnew DataTable();
				DataColumn^ column = gcnew DataColumn("INFO", String::typeid);
				asd->Columns->Add(column);
				DataRow ^row;
				row = asd->NewRow();
				row["INFO"] = "������ �� �������";
				asd->Rows->Add(row);
				return asd;
			}

			//�������� ��������, ��� SQL ������ ��������� ��� ������� �������
			bool check = false;
			cmdSelect->CommandText = "SELECT `_rowid_` FROM `" + tableChoose + "` ORDER BY `_rowid_` ASC LIMIT 0, 200000000;";
			SQLiteDataReader ^reader = cmdSelect->ExecuteReader();

			//� table ����� ���������� �������� ���������
			DataTable ^table; //��������� ������� ������
			DataColumn ^column; //������� �������
			DataRow ^row; //������ �������

						  //������� ������� ������
			table = gcnew DataTable();

			//������ �������� ��������
			vector<String^>^ nameColumns = gcnew vector<String^>();

			//�������� ������ � ��������
			for (int i = 0; i < reader->FieldCount; i++) {
				nameColumns->push_back(reader->GetName(i));
				column = gcnew DataColumn(reader->GetName(i), String::typeid);
				table->Columns->Add(column);
			}
			//��������� �� ������ ������
			while (reader->Read()) {
				//��������� ������� �������
				row = table->NewRow();
				//� ������ ������ ��������� �� ���� ��������
				for (int i = 0; i < reader->FieldCount; i++) {
					//�������� �������� ������� � row
					row[nameColumns->at(i)] = reader->GetValue(i)->ToString();
				}
				table->Rows->Add(row);
			}

			//������� ���������
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
			MessageBox::Show("������� �� �������, ���� ������ �� �������.", "������ ...");
		}
		else
		{
			MessageBox::Show("������� �� �������, ������ �� �������.", "������ ...");
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
			//�������� ��������, ��� SQL ������ ��������� ��� ������� �������
			cmdSelect->CommandText = "SELECT name FROM sqlite_master WHERE type = 'table';";
			SQLiteDataReader ^reader = cmdSelect->ExecuteReader();

			//� table ����� ���������� �������� ���������
			DataTable ^table; //��������� ������� ������
			DataColumn ^column; //������� �������
			DataRow ^row; //������ �������

			//������� ������� ������
			table = gcnew DataTable();

			//������ �������� ��������
			vector<String^>^ nameColumns = gcnew vector<String^>();

			//�������� ������ � ��������
			for (int i = 0; i < reader->FieldCount; i++) {
				nameColumns->push_back(reader->GetName(i));
				column = gcnew DataColumn(reader->GetName(i), String::typeid);
				table->Columns->Add(column);
			}
			//��������� �� ������ ������
			vector<String^>^ NameTable = gcnew vector<String^>;
			while (reader->Read()) {
				//��������� ������� �������
				row = table->NewRow();
				//� ������ ������ ��������� �� ���� ��������
				for (int i = 0; i < reader->FieldCount; i++) {
					//�������� �������� ������� � row
					row[nameColumns->at(i)] = reader->GetValue(i)->ToString();
					NameTable->push_back(reader->GetValue(i)->ToString());
				}
				table->Rows->Add(row);
			}

			//������� ���������
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
			MessageBox::Show("������� �� �������, ���� ������ �� �������.", "������ ...");

		}
		else
		{
			MessageBox::Show("������� �� �������, ����� ����.", "������ ...");

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
		MessageBox::Show("�������� �� �������, ���� ������ �� �������.", "������ ...");
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
		MessageBox::Show("�������� �� �������, ���� ������ �� �������.", "������ ...");
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

	DataTable ^table; //��������� ������� ������
	DataColumn ^column; //������� �������
	DataRow ^row; //������ �������

	//������� ������� ������
	table = gcnew DataTable();

	//������ �������� ��������
	vector<String^>^ nameColumns = gcnew vector<String^>();

	//�������� ������ � ��������
	for (int i = 0; i < mytable->Columns->Count; i++) {
		nameColumns->push_back(mytable->Columns[i]->HeaderText);
		column = gcnew DataColumn(mytable->Columns[i]->HeaderText, String::typeid);
		table->Columns->Add(column);
	}
	//� ������ ��������� �� ���� ��������
	for (int j = 0; j < index->size(); ++j)
	{
		//��������� ������� �������
		row = table->NewRow();
		for (int i = 0; i < mytable->Columns->Count; i++) {
			//�������� �������� ������� � row
			row[nameColumns->at(i)] = mytable->Rows[index->at(j)]->Cells[i]->Value->ToString();
		}
		table->Rows->Add(row);
	}

	return table;
}