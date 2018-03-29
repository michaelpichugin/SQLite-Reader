#pragma once
#include "Vector.h"
#include "About.h"
#include "Browser.h"
namespace AlloyDB {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			fileName = "";
			tableChoose = "";
			onecell = "";
			NameRowColumn = "";
			CurrentRowIndex = "";
			saveExportFile = "";
			logItoe = 0;
			timeStartProgramm = Convert::ToString(DateTime::Now);
			timeCloseProgramm = "";
		}
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
				delete components;
			if (textBox11->Text != "" && logItoe == 0)
			{
				IO::Directory::CreateDirectory("log");
				timeCloseProgramm = Convert::ToString(DateTime::Now);
				IO::File::AppendAllText("log\\log.txt", "\r\n\t\t��������� ������� � " + timeStartProgramm + "\r\n\r\n" + textBox11->Text + timeCloseProgramm + " -> ��������� �������.\r\n");
				logItoe++;
			}
		}
	private: String^ fileName; //���� �� �������� ���� ������
	private: String^ tableChoose; //�������� ��������� �������
	private: String^ onecell; //�������� �� ������ � ���������� ��
	private: String^ CurrentRowIndex; //������ ��������� ������
	private: vector<String^>^ Log_UpRec_Old_Value; //������ ������ ������ �� � ��������������
	private: String^ NameRowColumn; //�������� � ���� �������� ������� ����������� �� ���������� ��
	private: String^ saveExportFile; //���� �� ���������� ����������������� ����� (.html �������)
	private: int logItoe; //������� ��� ���� �� ��������� ������
	private: String^ timeStartProgramm; //����� ������� ��������� (������������ ��� �������)
	private: String^ timeCloseProgramm; //����� �������� ��������� (������������ ��� ��������)
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������������ToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����������htmlToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������ToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::ToolStripPanel^  BottomToolStripPanel;
	private: System::Windows::Forms::ToolStripPanel^  TopToolStripPanel;
	private: System::Windows::Forms::ToolStripPanel^  RightToolStripPanel;
	private: System::Windows::Forms::ToolStripPanel^  LeftToolStripPanel;
	private: System::Windows::Forms::ToolStripContentPanel^  ContentPanel;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->��������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->��������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BottomToolStripPanel = (gcnew System::Windows::Forms::ToolStripPanel());
			this->TopToolStripPanel = (gcnew System::Windows::Forms::ToolStripPanel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������htmlToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->�����ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RightToolStripPanel = (gcnew System::Windows::Forms::ToolStripPanel());
			this->LeftToolStripPanel = (gcnew System::Windows::Forms::ToolStripPanel());
			this->ContentPanel = (gcnew System::Windows::Forms::ToolStripContentPanel());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage4->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"SQLite database files (*.db)|*.db|SQLite database files (*.sqlite)|*.sqlite|SQLit"
				L"e database files (*.sqlite3)|*.sqlite3|SQLite database files (*.db3)|*.db3";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->��������������ToolStripMenuItem,
					this->toolStripMenuItem2, this->��������������������������ToolStripMenuItem, this->toolStripMenuItem3, this->��������������������ToolStripMenuItem,
					this->����������������ToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(293, 104);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->ShortcutKeyDisplayString = L"";
			this->��������������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Q));
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(292, 22);
			this->��������������ToolStripMenuItem->Text = L"�������� ������";
			this->��������������ToolStripMenuItem->ToolTipText = L"��������� ������ ������� � ����� �������.";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������������ToolStripMenuItem_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(289, 6);
			// 
			// ��������������������������ToolStripMenuItem
			// 
			this->��������������������������ToolStripMenuItem->Name = L"��������������������������ToolStripMenuItem";
			this->��������������������������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::W));
			this->��������������������������ToolStripMenuItem->Size = System::Drawing::Size(292, 22);
			this->��������������������������ToolStripMenuItem->Text = L"������������� ������� ������";
			this->��������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������������������������ToolStripMenuItem_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(289, 6);
			// 
			// ��������������������ToolStripMenuItem
			// 
			this->��������������������ToolStripMenuItem->Name = L"��������������������ToolStripMenuItem";
			this->��������������������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::E));
			this->��������������������ToolStripMenuItem->Size = System::Drawing::Size(292, 22);
			this->��������������������ToolStripMenuItem->Text = L"������� ������� ������";
			this->��������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������������������ToolStripMenuItem_Click);
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(292, 22);
			this->����������������ToolStripMenuItem->Text = L"������� ��� ������";
			this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::����������������ToolStripMenuItem_Click);
			// 
			// BottomToolStripPanel
			// 
			this->BottomToolStripPanel->Location = System::Drawing::Point(0, 0);
			this->BottomToolStripPanel->Name = L"BottomToolStripPanel";
			this->BottomToolStripPanel->Orientation = System::Windows::Forms::Orientation::Horizontal;
			this->BottomToolStripPanel->RowMargin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->BottomToolStripPanel->Size = System::Drawing::Size(0, 0);
			// 
			// TopToolStripPanel
			// 
			this->TopToolStripPanel->Location = System::Drawing::Point(0, 0);
			this->TopToolStripPanel->Name = L"TopToolStripPanel";
			this->TopToolStripPanel->Orientation = System::Windows::Forms::Orientation::Horizontal;
			this->TopToolStripPanel->RowMargin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->TopToolStripPanel->Size = System::Drawing::Size(0, 0);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem,
					this->�������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(819, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->�������ToolStripMenuItem,
					this->�����ToolStripMenuItem, this->�������ToolStripMenuItem, this->toolStripMenuItem4, this->�����ToolStripMenuItem1
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(234, 22);
			this->�������ToolStripMenuItem->Text = L"������� ���� ������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(231, 6);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->�����������htmlToolStripMenuItem });
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(234, 22);
			this->�������ToolStripMenuItem->Text = L"������� ������� �������";
			// 
			// �����������htmlToolStripMenuItem
			// 
			this->�����������htmlToolStripMenuItem->Name = L"�����������htmlToolStripMenuItem";
			this->�����������htmlToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::E));
			this->�����������htmlToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->�����������htmlToolStripMenuItem->Text = L"���-�������� (.html)";
			this->�����������htmlToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����������htmlToolStripMenuItem_Click);
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(231, 6);
			// 
			// �����ToolStripMenuItem1
			// 
			this->�����ToolStripMenuItem1->Name = L"�����ToolStripMenuItem1";
			this->�����ToolStripMenuItem1->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->�����ToolStripMenuItem1->Size = System::Drawing::Size(234, 22);
			this->�����ToolStripMenuItem1->Text = L"�����";
			this->�����ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::�����ToolStripMenuItem1_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->����������ToolStripMenuItem });
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F1));
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(195, 22);
			this->����������ToolStripMenuItem->Text = L"� ���������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::����������ToolStripMenuItem_Click_1);
			// 
			// RightToolStripPanel
			// 
			this->RightToolStripPanel->Location = System::Drawing::Point(0, 0);
			this->RightToolStripPanel->Name = L"RightToolStripPanel";
			this->RightToolStripPanel->Orientation = System::Windows::Forms::Orientation::Horizontal;
			this->RightToolStripPanel->RowMargin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->RightToolStripPanel->Size = System::Drawing::Size(0, 0);
			// 
			// LeftToolStripPanel
			// 
			this->LeftToolStripPanel->Location = System::Drawing::Point(0, 0);
			this->LeftToolStripPanel->Name = L"LeftToolStripPanel";
			this->LeftToolStripPanel->Orientation = System::Windows::Forms::Orientation::Horizontal;
			this->LeftToolStripPanel->RowMargin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->LeftToolStripPanel->Size = System::Drawing::Size(0, 0);
			// 
			// ContentPanel
			// 
			this->ContentPanel->AutoScroll = true;
			this->ContentPanel->Size = System::Drawing::Size(819, 413);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(12, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(795, 347);
			this->tabControl1->TabIndex = 6;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox3);
			this->tabPage1->Controls->Add(this->groupBox5);
			this->tabPage1->Controls->Add(this->textBox8);
			this->tabPage1->Controls->Add(this->button9);
			this->tabPage1->Controls->Add(this->button8);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->comboBox1);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(787, 321);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"�������� ��";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Controls->Add(this->dataGridView2);
			this->groupBox3->Controls->Add(this->button10);
			this->groupBox3->Location = System::Drawing::Point(6, 194);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(775, 121);
			this->groupBox3->TabIndex = 16;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"��������� ������";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Location = System::Drawing::Point(512, 90);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView2->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(6, 19);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(763, 65);
			this->dataGridView2->TabIndex = 0;
			// 
			// button10
			// 
			this->button10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button10->Location = System::Drawing::Point(623, 90);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(146, 23);
			this->button10->TabIndex = 1;
			this->button10->Text = L"��������� ���������";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox5->Controls->Add(this->checkBox1);
			this->groupBox5->Controls->Add(this->button14);
			this->groupBox5->Controls->Add(this->textBox10);
			this->groupBox5->Controls->Add(this->label10);
			this->groupBox5->Controls->Add(this->label9);
			this->groupBox5->Controls->Add(this->comboBox2);
			this->groupBox5->Location = System::Drawing::Point(6, 35);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(775, 47);
			this->groupBox5->TabIndex = 15;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"����� � �������";
			// 
			// checkBox1
			// 
			this->checkBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(532, 18);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(125, 17);
			this->checkBox1->TabIndex = 19;
			this->checkBox1->Text = L"������ ����������";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button14->Location = System::Drawing::Point(682, 14);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(87, 23);
			this->button14->TabIndex = 18;
			this->button14->Text = L"������";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// textBox10
			// 
			this->textBox10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox10->Location = System::Drawing::Point(369, 16);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(137, 20);
			this->textBox10->TabIndex = 17;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(261, 19);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(102, 13);
			this->label10->TabIndex = 16;
			this->label10->Text = L"������� ��������:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 19);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(104, 13);
			this->label9->TabIndex = 15;
			this->label9->Text = L"�������� �������:";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(116, 16);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 14;
			this->comboBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::comboBox2_KeyPress);
			// 
			// textBox8
			// 
			this->textBox8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox8->BackColor = System::Drawing::Color::WhiteSmoke;
			this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox8->Enabled = false;
			this->textBox8->Location = System::Drawing::Point(6, 88);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox8->Size = System::Drawing::Size(775, 100);
			this->textBox8->TabIndex = 12;
			this->textBox8->Visible = false;
			// 
			// button9
			// 
			this->button9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button9->Location = System::Drawing::Point(419, 6);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(118, 23);
			this->button9->TabIndex = 11;
			this->button9->Text = L"�������� �������";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button8
			// 
			this->button8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->Location = System::Drawing::Point(543, 6);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(120, 23);
			this->button8->TabIndex = 10;
			this->button8->Text = L"������� ��� ������";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(300, 6);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(113, 23);
			this->button4->TabIndex = 9;
			this->button4->Text = L"�������� �������";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(112, 11);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(55, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"�������:";
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(173, 8);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::comboBox1_KeyPress);
			// 
			// button3
			// 
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Location = System::Drawing::Point(6, 6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"������� ��";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ContextMenuStrip = this->contextMenuStrip1;
			this->dataGridView1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->dataGridView1->Location = System::Drawing::Point(6, 88);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(775, 100);
			this->dataGridView1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(669, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"������� ������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->textBox11);
			this->tabPage4->Controls->Add(this->button17);
			this->tabPage4->Controls->Add(this->button15);
			this->tabPage4->Controls->Add(this->button16);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(787, 321);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"��� ��������";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// textBox11
			// 
			this->textBox11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox11->BackColor = System::Drawing::Color::WhiteSmoke;
			this->textBox11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox11->Cursor = System::Windows::Forms::Cursors::Default;
			this->textBox11->Location = System::Drawing::Point(3, 3);
			this->textBox11->MaxLength = 1000000;
			this->textBox11->Multiline = true;
			this->textBox11->Name = L"textBox11";
			this->textBox11->ReadOnly = true;
			this->textBox11->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox11->Size = System::Drawing::Size(781, 310);
			this->textBox11->TabIndex = 4;
			// 
			// button17
			// 
			this->button17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button17->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button17->Location = System::Drawing::Point(3, 319);
			this->button17->Margin = System::Windows::Forms::Padding(3, 3, 3, 30);
			this->button17->MaximumSize = System::Drawing::Size(211, 23);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(211, 23);
			this->button17->TabIndex = 3;
			this->button17->Text = L"�������� ���";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button15
			// 
			this->button15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button15->Location = System::Drawing::Point(573, 319);
			this->button15->MaximumSize = System::Drawing::Size(211, 23);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(211, 23);
			this->button15->TabIndex = 1;
			this->button15->Text = L"��������� ���";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button16->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button16->Location = System::Drawing::Point(220, 319);
			this->button16->MaximumSize = System::Drawing::Size(347, 23);
			this->button16->MinimumSize = System::Drawing::Size(165, 23);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(347, 23);
			this->button16->TabIndex = 2;
			this->button16->Text = L"����������� � ����� ������";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(819, 386);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(835, 425);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SQLite Browser | ��";
			this->contextMenuStrip1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: void OpenBD() {
	try {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			fileName = openFileDialog1->FileName; // ������ ���� � �����
			this->Text = "SQLite Browser | �� � " + fileName; // ������ �������� ����
			textBox11->Text += Convert::ToString(DateTime::Now) + " -> ������� �� � " + fileName + "\r\n"; // ���������� � ���

			comboBox1->Items->Clear(); // ������� ���. ������ ������
			comboBox1->Text = ""; // ������ ��� ���. ������ ������ ����� ""

			dataGridView1->Columns->Clear(); // ������� ������� � ������� 1 

			VectorI^ temp = gcnew VectorI();
			DataTable ^table = temp->getInfo(fileName, ""); //��������� ��������� �������
			NameRowColumn = temp->getNameRowColumn();

			if (table != nullptr) // ���� ���������� ������� �� �����
			{
				dataGridView1->DataSource = table; // ���������� � 

				comboBox2->Items->Clear(); // ������� ���. ������ ��� ������
				comboBox2->Text = ""; // ����������� ������ �������� � ���. ������

				for (int i = 0; i < dataGridView1->Columns->Count; ++i)
					// ��������� ���������� �������� ���. ������ ��� ������
					comboBox2->Items->Add(dataGridView1->Columns[i]->HeaderText);
			}
			else
				MessageBox::Show("������� �����.", "�������� ...");

			delete table; //������� ��������� �������

			button4->Enabled = true; // �������� ������ "�������� �������"

			vector<String^>^ NameTable = gcnew vector<String^>; // ������ �������� ������

			if (temp->getTableName()->size() != 0) // ���� ������������ ������ �� ����
				NameTable = temp->getTableName(); // ����������� ��� ������ � NameTable
			else
				return; // ����� ������� OpenBD ���������

			comboBox1->Items->Clear(); // ������� ���������� ������ ������

			for (int i = 0; i < NameTable->size(); i++) // ��������� ���. ������ ���������� �� NameTable
				comboBox1->Items->Add(NameTable->at(i));

			delete temp; // ������� ��������� ������ VectorI

			tableChoose = NameTable->at(0); // ���������� �������� ������� ��� ID = 0
			comboBox1->Text = NameTable->at(0); // �������� � ���. ������ ������ �������

			delete NameTable; //������� ������ �������� ������
		}
	}
	catch (Exception ^ errors)
	{
		MessageBox::Show(errors->ToString(), "Error Open BD");
		return;
	}
}

//������� ���������� ����� ������
private: void AddRow() {
	if (fileName != "" && comboBox1->Items->Count != 0)
	{
		VectorI^ temp = gcnew VectorI(fileName, false, tableChoose);
		dataGridView1->DataSource = temp->AddRecord(dataGridView1);
		delete temp;
		textBox11->Text += Convert::ToString(DateTime::Now) + " -> ��������� ����� ������ � ������� - " + comboBox1->Text + ".\r\n";
	}
	else
	{
		if (comboBox1->Items->Count == 0)
		{
			MessageBox::Show("������ �� �������.", "������ ...");
			return;
		}
		MessageBox::Show("���� ������ �� �������, �������� �� �������.", "������ ...");
	}
}

//������� ����������� ��������� ������
private: void Log_DelRow() {
	vector<String^>^ dataRecord = gcnew vector<String^>();
	for (int i = 0; i < dataGridView1->ColumnCount; i++)
		dataRecord->push_back(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[i]->Value->ToString());
	String^ dataString = "";
	for (int i = 0; i < dataRecord->size(); i++)
		if (i == 0)
			dataString += "'" + dataRecord->at(i) + "'";
		else
			dataString += ", " + "'" + dataRecord->at(i) + "'";
	delete dataRecord;
	textBox11->Text += Convert::ToString(DateTime::Now) + " -> ������ �� ������� � " + comboBox1->Text + ", ���������� � ���� (" + dataString + ") �������.\r\n";
}

//������� �������� ��������� ������
private: void DelRow() {
	if (fileName != "" && dataGridView1->Rows->Count > 0 && comboBox1->Items->Count != 0)
	{
		VectorI^ temp = gcnew VectorI(fileName, false, tableChoose);
		Log_DelRow();
		temp->DelRow(Convert::ToInt32(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value->ToString())); // ������ ������ �� idrow
		dataGridView1->Rows->RemoveAt(dataGridView1->CurrentCell->RowIndex);
		delete temp;
	}
	else
	{
		if (comboBox1->Items->Count == 0)
		{
			MessageBox::Show("������ �� �������.", "������ ...");
			return;
		}
		if (fileName == "")
			MessageBox::Show("���� ������ �� �������, ������� �� �������.", "������ ...");
		else
			MessageBox::Show("������� �� �������, ����� ����.", "������ ...");
	}
}

//������� �������� ���� �����
private: void AllDelRow() {
	if (fileName != "" && dataGridView1->Rows->Count > 0 && comboBox1->Items->Count != 0)
	{
		auto MeBox = MessageBox::Show("�� ������������� ������ ������� ��� ������?", "�������������� ...", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		switch (MeBox)
		{
		case System::Windows::Forms::DialogResult::No:
			return;
		case System::Windows::Forms::DialogResult::Yes:
			VectorI^ temp = gcnew VectorI(fileName, false, tableChoose);
			temp->AllDelRow(tableChoose);
			dataGridView1->DataSource = temp->ShowTable(tableChoose);
			delete temp;
			textBox11->Text += Convert::ToString(DateTime::Now) + " -> ��� ������ ������� � " + comboBox1->Text + ", �������!\r\n";
			break;
		}
	}
	else
	{
		if (comboBox1->Items->Count == 0)
		{
			MessageBox::Show("������ �� �������.", "������ ...");
			return;
		}
		if (fileName == "")
		{
			MessageBox::Show("���� ������ �� �������, ������� �� �������.", "������ ...");
			textBox11->Text += Convert::ToString(DateTime::Now) + " -> ���� ������ �� �������, ������� ��� ������ �� �������.\r\n";
		}
		else
		{
			MessageBox::Show("������� �� �������, ����� ����.", "������ ...");
			textBox11->Text += Convert::ToString(DateTime::Now) + " -> ������� ��� ������ ������� � " + comboBox1->Text + ", �� �������, ����� ����.\r\n";
		}
	}
}

private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenBD();
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenBD();
}

private: System::Void �����ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	DelRow();
}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	if (comboBox1->Items->Count > 0)
	{
		dataGridView1->Visible = true;
		dataGridView1->Enabled = true;
		button9->Text = "�������� �������";
		textBox8->Enabled = false;
		textBox8->Visible = false;

		dataGridView2->Columns->Clear();
		tableChoose = comboBox1->Text;
		textBox11->Text += Convert::ToString(DateTime::Now) + " -> ������� ������� � " + comboBox1->Text + ".\r\n";

		VectorI^ temp = gcnew VectorI(fileName, false, tableChoose);
		if (temp->ShowTable(comboBox1->Text) != nullptr)
		{
			dataGridView1->DataSource = temp->ShowTable(comboBox1->Text);
			NameRowColumn = temp->getNameRowColumn();
			comboBox2->Items->Clear();
			comboBox2->Text = "";
			for (int i = 0; i < dataGridView1->Columns->Count; ++i)
				comboBox2->Items->Add(dataGridView1->Columns[i]->HeaderText);
			delete temp;
		}
		else
		{
			delete temp;
			return;
		}
	}
	else
		MessageBox::Show("������ ��� ����������� �� �������.", "������ ...");
}

private: System::Void comboBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	e->Handled = true;
}

private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	AllDelRow(); //������� ��� ������ �� �������
}

private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	if (comboBox1->Text != "")
	if (dataGridView1->Visible == true)
	{
		textBox11->Text += Convert::ToString(DateTime::Now) + " -> ������� � " + comboBox1->Text + ", ������������ � ���� ������.\r\n";
		dataGridView1->Visible = false;
		dataGridView1->Enabled = false;
		button9->Text = "�������� ��������";
		textBox8->Enabled = true;
		textBox8->Visible = true;
		VectorI^ tempVector = gcnew VectorI();
		textBox8->Text = tempVector->getInfoText(dataGridView1, tableChoose);
		delete tempVector;
	}
	else
	{
		textBox11->Text += Convert::ToString(DateTime::Now) + " -> ������� � " + comboBox1->Text + ", ������������ � ��������� ����.\r\n";
		textBox8->Text = "";
		dataGridView1->Visible = true;
		dataGridView1->Enabled = true;
		button9->Text = "�������� �������";
		textBox8->Enabled = false;
		textBox8->Visible = false;
	}
	else
	{
		MessageBox::Show("����������� � ���� ������ �� �������, ������� �� �������.", "������ ...");
		textBox11->Text += Convert::ToString(DateTime::Now) + " -> ����������� � ���� ������ �� �������, ������� �� �������.\r\n";
	}
}
private: System::Void ��������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	AddRow(); //��������� ����� ������ � �������
}

private: System::Void ��������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	DelRow(); //������� ��������� ������ �� �������
}

private: System::Void ����������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	AllDelRow(); //������� ��� ������ �� �������
}

private: System::Void ��������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fileName != "" && dataGridView1->Rows->Count > 0 && comboBox1->Items->Count != 0)
	{
		Log_UpRec_Old_Value = gcnew vector<String^>;
		for (int i = 0; i < dataGridView1->ColumnCount; i++)
			Log_UpRec_Old_Value->push_back(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[i]->Value->ToString());

		DataTable ^table; //��������� ������� ������
		DataColumn ^column; //������� �������
		DataRow ^row; //������ �������

		//������� ������� ������
		table = gcnew DataTable();

		//������ �������� ��������
		vector<String^>^ nameColumns = gcnew vector<String^>();

		//�������� ������ � ��������
		for (int i = 0; i < dataGridView1->Columns->Count; i++) {
			nameColumns->push_back(dataGridView1->Columns[i]->HeaderText);
			column = gcnew DataColumn(dataGridView1->Columns[i]->HeaderText, String::typeid);
			table->Columns->Add(column);
			delete column;
		}

		//��������� ������� �������
		row = table->NewRow();
		//� ������ ��������� �� ���� ��������
		for (int i = 0; i < dataGridView1->Columns->Count; i++) {
			//�������� �������� ������� � row
			row[nameColumns->at(i)] = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[i]->Value->ToString();
		}
		table->Rows->Add(row);
		delete row;

		dataGridView2->DataSource = table;
		delete table;

		onecell = dataGridView2->Rows[0]->Cells[0]->Value->ToString();
		CurrentRowIndex = Convert::ToString(dataGridView1->CurrentCell->RowIndex);
	}
	else
	{
		if (comboBox1->Items->Count == 0)
		{
			MessageBox::Show("������ �� �������.", "������ ...");
			return;
		}
		if (fileName == "")
			MessageBox::Show("���� ������ �� �������, �������� �� �������.", "������ ...");
		else
			MessageBox::Show("�������� �� �������, ����� ����.", "������ ...");
	}
}

private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fileName != "" && dataGridView1->Rows->Count > 0 && comboBox1->Items->Count != 0)
	{
		if (textBox10->Text != "" && comboBox2->Text != "")
		{
			dataGridView1->Visible = true;
			dataGridView1->Enabled = true;
			button9->Text = "�������� �������";
			textBox8->Enabled = false;
			textBox8->Visible = false;

			VectorI^ temp = gcnew VectorI();
			DataTable^ temped = gcnew DataTable();
			String^ searchsettings = "";
			if (checkBox1->Checked)
				searchsettings = "accurate";
			else
				searchsettings = "first";
			temped = temp->Search(dataGridView1, comboBox2->Text, textBox10->Text, searchsettings);
			delete temp;
			if (temped->Rows->Count > 0)
			{
				dataGridView1->DataSource = temped;
				if (checkBox1->Checked)
					textBox11->Text += Convert::ToString(DateTime::Now) + " -> �������� ����� �� ������� � " + comboBox1->Text + " � ����������� : ������ ���������� � " + comboBox2->Text + "/" + textBox10->Text + ", ������� = " + temped->Rows->Count + ".\r\n";
				else
					textBox11->Text += Convert::ToString(DateTime::Now) + " -> �������� ����� �� ������� � " + comboBox1->Text + " � ����������� : ������ ��������� � " + comboBox2->Text + "/" + textBox10->Text + ", ������� = " + temped->Rows->Count + ".\r\n";
			}
			else
			{
				MessageBox::Show("������ �� �������.", "������ ...");
				if (checkBox1->Checked)
					textBox11->Text += Convert::ToString(DateTime::Now) + " -> �������� ����� �� ������� � " + comboBox1->Text + " � ����������� : ������ ���������� � " + comboBox2->Text + "/" + textBox10->Text + ", ������ �� �������.\r\n";
				else
					textBox11->Text += Convert::ToString(DateTime::Now) + " -> �������� ����� �� ������� � " + comboBox1->Text + " � ����������� : ������ ��������� � " + comboBox2->Text + "/" + textBox10->Text + ", ������ �� �������.\r\n";
			}
			delete temped;
		}
		else
			if (comboBox2->Text == "")
				MessageBox::Show("��� ���� ����� ������, ����� ������� �������.", "������ ...");
			else
				MessageBox::Show("�������� �� ����� ���� ������, ������� ��������.", "������ ...");
	}
	else
	{
		if (comboBox1->Items->Count == 0)
		{
			MessageBox::Show("������ � ���� ������ �� �������. ����� ����������.", "������ ...");
			return;
		}
		if (fileName == "")
			MessageBox::Show("���� ������ �� �������, ����� �� �������.", "������ ...");
		else
			MessageBox::Show("����� �� �������, ����� ����.", "������ ...");
	}
}
private: System::Void comboBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	e->Handled = true;
}
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBox11->Text != "")
	{
		SaveFileDialog ^saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "��������� ����� (.txt)|*.txt";
		saveFileDialog1->FilterIndex = 1;
		saveFileDialog1->RestoreDirectory = true;
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			IO::File::WriteAllText(saveFileDialog1->FileName, textBox11->Text);
			MessageBox::Show("��� �������� ������� �������!",
				"������� ...", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		delete saveFileDialog1;
	}
	else
	{
		MessageBox::Show("��� �������� ����!",
			"������ ...", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
}
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBox11->Text != "")
		Clipboard::SetText(textBox11->Text);
	else
	{
		MessageBox::Show("��� �������� ����!",
			"������ ...", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
}
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBox11->Text != "")
		textBox11->Clear();
}
private: System::Void ����������ToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e) {
	About^ temp = gcnew About();
	temp->ShowDialog();
	delete temp;
}
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
	if (dataGridView2->Columns->Count != 0)
	{
		dataGridView2->Columns->Clear();
		delete Log_UpRec_Old_Value;
	}
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fileName != "")
	{
		if (dataGridView2->Rows->Count > 0)
		{
			dataGridView1->Visible = true;
			dataGridView1->Enabled = true;
			button9->Text = "�������� �������";
			textBox8->Enabled = false;
			textBox8->Visible = false;

			VectorI^ temp = gcnew VectorI(fileName, true, tableChoose);

			String^ dataStringOld = "";
			for (int i = 0; i < Log_UpRec_Old_Value->size(); i++)
				if (i == 0)
					dataStringOld += "'" + Log_UpRec_Old_Value->at(i) + "'";
				else
					dataStringOld += ", " + "'" + Log_UpRec_Old_Value->at(i) + "'";
			delete Log_UpRec_Old_Value;

			vector<String^>^ dataRecordNew = gcnew vector<String^>();
			for (int i = 0; i < dataGridView2->ColumnCount; i++)
				dataRecordNew->push_back(dataGridView2->Rows[dataGridView2->CurrentCell->RowIndex]->Cells[i]->Value->ToString());
			String^ dataStringNew = "";
			for (int i = 0; i < dataRecordNew->size(); i++)
				if (i == 0)
					dataStringNew += "'" + dataRecordNew->at(i) + "'";
				else
					dataStringNew += ", " + "'" + dataRecordNew->at(i) + "'";
			delete dataRecordNew;

			if (dataGridView2->Rows[0]->Cells[0]->Value->ToString() == onecell)
			{
				DataTable ^table = temp->UpdateRecord(dataGridView2, onecell);
				delete temp;
				dataGridView1->DataSource = table;
				delete table;
				dataGridView1->ClearSelection();
				dataGridView1->Rows[Convert::ToInt32(CurrentRowIndex)]->Selected = true;
				dataGridView2->Columns->Clear();
				textBox11->Text += Convert::ToString(DateTime::Now) + " -> ������ �� ������� � " + comboBox1->Text + " ���������, ���������� �� (" + dataStringOld + ") ����� (" + dataStringNew + ").\r\n";
			}
			else
			{
				MessageBox::Show("�������� ���������� ������������� �������������!\r\n�� ��� ������� ������������� �� " + dataGridView2->Columns[0]->HeaderText + " = " + onecell, "������ ...");
				dataGridView2->Rows[0]->Cells[0]->Value = onecell;
				DataTable ^table = temp->UpdateRecord(dataGridView2, onecell);
				delete temp;
				dataGridView1->DataSource = table;
				delete table;
				dataGridView1->ClearSelection();
				dataGridView1->Rows[Convert::ToInt32(CurrentRowIndex)]->Selected = true;
				dataGridView2->Columns->Clear();
				textBox11->Text += Convert::ToString(DateTime::Now) + " -> ������ �� ������� � " + comboBox1->Text + " ���������, ���������� �� (" + dataStringOld + ") ����� (" + dataStringNew + ").\r\n";
			}
		}
		else
			MessageBox::Show("� ������� �� ������� �����, �������� ������.", "������ ...");
	}
	else
		MessageBox::Show("���� ������ �� �������, �������� �� �������.", "������ ...");
}

private: System::Void �����������htmlToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (fileName != "" && comboBox1->Text != "")
	{
		try {

			String^ fileColumn = "";

			for (int i = 0; i < dataGridView1->Columns->Count; i++)
			{
				if (i == 0) fileColumn = "<tr height = 20 style = 'height:15.0pt'>\r\n\r\n" +
					"<td height=20 class=xl1514972 align=left width=83 style='height:15.0pt;\r\n" +
					"width:62pt;font-size:11.0pt;color:white;font-weight:2000;text-decoration:none;\r\n" +
					"text-underline-style:none;text-line-through:none;font-family:Calibri;\r\n" +
					"border-top:.5pt solid #95B3D7;border-right:none;border-bottom:.5pt solid #95B3D7;\r\n" +
					"border-left:.5pt solid #95B3D7;background:#4F81BD;mso-pattern:#4F81BD none'>" + dataGridView1->Columns[0]->Name + "</td>\r\n\r\n";
				else
					if ((dataGridView1->Columns->Count - i) == 1) fileColumn += "<td class=xl1514972 align=left width=83 style='width:62pt;font-size:11.0pt;\r\n" +
						"color:white;font-weight:2000;text-decoration:none;text-underline-style:none;\r\n" +
						"text-line-through:none;font-family:Calibri;border-top:.5pt solid #95B3D7;\r\n" +
						"border-right:.5pt solid #95B3D7;border-bottom:.5pt solid #95B3D7;border-left:\r\n" +
						"none;background:#4F81BD;mso-pattern:#4F81BD none'>" + dataGridView1->Columns[i]->Name + "</td>\r\n\r\n </tr> \r\n\r\n";

					else fileColumn += "<td class=xl1514972 align=left width=83 style='width:62pt;font-size:11.0pt;\r\n" +
						"color:white;font-weight:2000;text-decoration:none;text-underline-style:none;\r\n" +
						"text-line-through:none;font-family:Calibri;border-top:.5pt solid #95B3D7;\r\n" +
						"border-right:none;border-bottom:.5pt solid #95B3D7;border-left:none;\r\n" +
						"background:#4F81BD;mso-pattern:#4F81BD none'>" + dataGridView1->Columns[i]->Name + "</td>\r\n\r\n";
			}

			String^ fileCells = "";
			bool boolCells = true;

			for (int j = 0; j < dataGridView1->Rows->Count; j++)
				if (boolCells)
				{
					for (int k = 0; k < dataGridView1->Columns->Count; k++)
						if (k == 0) fileCells += "<tr height = 20 style = 'height:15.0pt'>\r\n\r\n" +
							"<td height=20 class=xl1514972 align=right style='height:15.0pt;font-size:\r\n" +
							"11.0pt;color:black;font-weight:2000;text-decoration:none;text-underline-style:\r\n" +
							"none;text-line-through:none;font-family:Calibri;border-top:.5pt solid #95B3D7;\r\n" +
							"border-right:none;border-bottom:.5pt solid #95B3D7;border-left:.5pt solid #95B3D7;\r\n" +
							"background:#DCE6F1;mso-pattern:#DCE6F1 none'>" + dataGridView1->Rows[j]->Cells[0]->Value->ToString() + "</td>\r\n\r\n";
						else
							if ((dataGridView1->Columns->Count - k) == 1) fileCells += "<td class=xl1514972 align=right style='font-size:11.0pt;color:black;\r\n" +
								"font-weight:2000;text-decoration:none;text-underline-style:none;text-line-through:\r\n" +
								"none;font-family:Calibri;border-top:.5pt solid #95B3D7;border-right:.5pt solid #95B3D7;\r\n" +
								"border-bottom:.5pt solid #95B3D7;border-left:none;background:#DCE6F1;\r\n" +
								"mso-pattern:#DCE6F1 none'>" + dataGridView1->Rows[j]->Cells[k]->Value->ToString() + "</td>\r\n\r\n</tr>\r\n\r\n";
							else fileCells += "<td class=xl1514972 align=right style='font-size:11.0pt;color:black;\r\n" +
								"font-weight:2000;text-decoration:none;text-underline-style:none;text-line-through:\r\n" +
								"none;font-family:Calibri;border-top:.5pt solid #95B3D7;border-right:none;\r\n" +
								"border-bottom:.5pt solid #95B3D7;border-left:none;background:#DCE6F1;\r\n" +
								"mso-pattern:#DCE6F1 none'>" + dataGridView1->Rows[j]->Cells[k]->Value->ToString() + "</td>\r\n\r\n";
					boolCells = false;
				}
				else
				{
					for (int k = 0; k < dataGridView1->Columns->Count; k++)
						if (k == 0) fileCells += "<tr height = 20 style = 'height:15.0pt'>\r\n\r\n" +
							"<td height=20 class=xl1514972 align=right style='height:15.0pt;font-size:\r\n" +
							"11.0pt;color:black;font-weight:2000;text-decoration:none;text-underline-style:\r\n" +
							"none;text-line-through:none;font-family:Calibri;border-top:.5pt solid #95B3D7;\r\n" +
							"border-right:none;border-bottom:.5pt solid #95B3D7;border-left:.5pt solid #95B3D7'>" + dataGridView1->Rows[j]->Cells[0]->Value->ToString() + "</td>\r\n\r\n";
						else
							if ((dataGridView1->Columns->Count - k) == 1) fileCells += "<td class=xl1514972 align=right style='font-size:11.0pt;color:black;\r\n" +
								"font-weight:2000;text-decoration:none;text-underline-style:none;text-line-through:\r\n" +
								"none;font-family:Calibri;border-top:.5pt solid #95B3D7;border-right:.5pt solid #95B3D7;\r\n" +
								"border-bottom:.5pt solid #95B3D7;border-left:none'>" + dataGridView1->Rows[j]->Cells[k]->Value->ToString() + "</td>\r\n\r\n</tr>\r\n\r\n";
							else fileCells += "<td class=xl1514972 align=right style='font-size:11.0pt;color:black;\r\n" +
								"font-weight:2000;text-decoration:none;text-underline-style:none;text-line-through:\r\n" +
								"none;font-family:Calibri;border-top:.5pt solid #95B3D7;border-right:none;\r\n" +
								"border-bottom:.5pt solid #95B3D7;border-left:none'>" + dataGridView1->Rows[j]->Cells[k]->Value->ToString() + "</td>\r\n\r\n";
					boolCells = true;
				}

			SaveFileDialog ^saveFileDialog1 = gcnew SaveFileDialog();
			saveFileDialog1->Filter = "HTML (.html)|*.html";
			saveFileDialog1->FilterIndex = 1;
			saveFileDialog1->RestoreDirectory = true;
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				IO::File::WriteAllText(saveFileDialog1->FileName,
					"<html>\r\n" +
					"<body>\r\n" +
					"<head>\r\n" +
					"<meta http - equiv = Content - Type content = \"text/html; charset=utf-8\">\r\n" +
					"</head>\r\n" +
					"<div>\r\n\r\n" +

					"<table border=0 cellpadding=7 cellspacing=0>\r\n" +
					fileColumn +
					fileCells +
					"</table>\r\n" +

					"</div>\r\n" +
					"</body>\r\n" +
					"</html>");
				saveExportFile = saveFileDialog1->FileName;
				delete saveFileDialog1;
				textBox11->Text += Convert::ToString(DateTime::Now) + " -> ������� - " + comboBox1->Text + " ������� �������������� � ������� ���-�������� (.html), ���� �� ����� : " + saveExportFile + ".\r\n";
				auto MeBox = MessageBox::Show("������� �������� �������!\r\n������� ��������?",
					"������� ...", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				switch (MeBox)
				{
				case System::Windows::Forms::DialogResult::No:
					return;
				case System::Windows::Forms::DialogResult::Yes:
					textBox11->Text += Convert::ToString(DateTime::Now) + " -> ���������������� ���� (" + saveExportFile + ") ��� ������ ����� ����������� �������.\r\n";
					Browser^ temp = gcnew Browser();
					temp->Text = "����������� ������� | ���� � " + saveExportFile;
					temp->webBrowser1->Url = (gcnew System::Uri(saveExportFile, System::UriKind::Absolute));
					temp->Show();
				}
			}
			else
				delete saveFileDialog1;
		}
		catch (Exception^ errors)
		{
			MessageBox::Show(errors->ToString(),
				"������ ...", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
	}
	else
	{
		if (fileName == "")
		{
			MessageBox::Show("���� ������ �� �������.",
				"������ ...", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		else
		{
			MessageBox::Show("������ � ���� ������ ���.",
				"������ ...", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
	}
}
};
}