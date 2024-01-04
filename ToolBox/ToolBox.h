#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <tesseract\baseapi.h>
#include <leptonica\allheaders.h>
#include <msclr/marshal_cppstd.h>

#include <Windows.h>
#include <string>
//#include <vector>



namespace ToolBox {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	using namespace std;
	/// <summary>
	/// Summary for ToolBox
	/// </summary>
	/*SRC image */
	Mat src = imread("x28.jpg", 0), src_Licence = imread("6806955219_c992e3bdbd_b.jpg");
	Mat dst[2500];
	

	// Read the selected image using OpenCV
	


	
	UInt32 OP = 1, hist = 0, TrackBar_1 = 0, TrackBar_2 = 0, TrackBar_3 = 0;
	UInt32	TrackBar_4 = 0,TrackBar_5 = 0, freq_Flag = 0,license_flag=0;

	void DFTShow(Mat planes[2]) {
		// Show DFT
		Mat mag;
		magnitude(planes[0], planes[1], mag);
		mag = mag + 1;
		log(mag, mag);
		normalize(mag, mag, 0, 1, NORM_MINMAX);
		

		// Swap quadrants
		int cx_P = planes[0].cols / 2;
		int cy_P = planes[0].rows / 2;

		Mat p1_r(planes[0], Rect(0, 0, cx_P, cy_P));
		Mat p2_r(planes[0], Rect(cx_P, 0, cx_P, cy_P));
		Mat p3_r(planes[0], Rect(0, cy_P, cx_P, cy_P));
		Mat p4_r(planes[0], Rect(cx_P, cy_P, cx_P, cy_P));

		Mat temp;
		p1_r.copyTo(temp);
		p4_r.copyTo(p1_r);
		temp.copyTo(p4_r);
		p2_r.copyTo(temp);
		p3_r.copyTo(p2_r);
		temp.copyTo(p3_r);

		Mat p1_i(planes[1], Rect(0, 0, cx_P, cy_P));
		Mat p2_i(planes[1], Rect(cx_P, 0, cx_P, cy_P));
		Mat p3_i(planes[1], Rect(0, cy_P, cx_P, cy_P));
		Mat p4_i(planes[1], Rect(cx_P, cy_P, cx_P, cy_P));

		p1_i.copyTo(temp);
		p4_i.copyTo(p1_i);
		temp.copyTo(p4_i);
		p2_i.copyTo(temp);
		p3_i.copyTo(p2_i);
		temp.copyTo(p3_i);
	}
	public ref class ToolBox : public System::Windows::Forms::Form
	{
	public:
		ToolBox(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ToolBox()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Open_Image;



	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Button^ Reset_Image;

	private: System::Windows::Forms::Button^ Histogram;
	private: System::Windows::Forms::Button^ UNDO;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ Skewing;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ Zoom;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ Median_Filter;

	private: System::Windows::Forms::Button^ Rotation;
	public: System::Windows::Forms::TrackBar^ trackBar3;
	private:

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ Frequency;
	private: System::Windows::Forms::TrackBar^ trackBar4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ Open_License;
	private: System::Windows::Forms::Button^ Lisence;
	private: System::Windows::Forms::Button^ Noise;
	private: System::Windows::Forms::Button^ Transformation;




















	private: System::Windows::Forms::Button^ Negative;
	private: System::Windows::Forms::Button^ Gray_Level;
	private: System::Windows::Forms::TextBox^ tx1;
	private: System::Windows::Forms::TextBox^ tx2;
	private: System::Windows::Forms::Button^ Gama;

	private:

	private: System::Windows::Forms::Button^ Edge_Detection;
	private: System::Windows::Forms::Button^ Log_Transformation;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ Laplacian;

	private: System::Windows::Forms::TextBox^ textBox6;
	public: System::Windows::Forms::TrackBar^ trackBar5;
	private: System::Windows::Forms::TrackBar^ trackBar6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ Blurring;
	private: System::Windows::Forms::Label^ label8;

	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TrackBar^ trackBar8;
private: System::Windows::Forms::Button^ Edge__Detection;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Button^ Threshold;
private: System::Windows::Forms::TrackBar^ trackBar7;
private: System::Windows::Forms::TextBox^ textBox8;
private: System::Windows::Forms::TextBox^ textBox9;
private: System::Windows::Forms::TrackBar^ trackBar9;


private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::Button^ Reflecting;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::RichTextBox^ richTextBox1;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::Label^ label24;
private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::Button^ Vertical_Sobel;

private: System::Windows::Forms::Button^ Horizontal_Sobel;
private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::Label^ label31;
private: System::Windows::Forms::Label^ label32;
private: System::Windows::Forms::Label^ label33;
private: System::Windows::Forms::TextBox^ textBox10;

	public:
	private:


	public:
	private:
















	protected:

	protected:


	protected:





	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ToolBox::typeid));
			this->Open_Image = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Reset_Image = (gcnew System::Windows::Forms::Button());
			this->Histogram = (gcnew System::Windows::Forms::Button());
			this->UNDO = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Skewing = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->Zoom = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Median_Filter = (gcnew System::Windows::Forms::Button());
			this->Rotation = (gcnew System::Windows::Forms::Button());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Frequency = (gcnew System::Windows::Forms::Button());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Open_License = (gcnew System::Windows::Forms::Button());
			this->Lisence = (gcnew System::Windows::Forms::Button());
			this->Noise = (gcnew System::Windows::Forms::Button());
			this->Transformation = (gcnew System::Windows::Forms::Button());
			this->Negative = (gcnew System::Windows::Forms::Button());
			this->Gray_Level = (gcnew System::Windows::Forms::Button());
			this->tx1 = (gcnew System::Windows::Forms::TextBox());
			this->tx2 = (gcnew System::Windows::Forms::TextBox());
			this->Gama = (gcnew System::Windows::Forms::Button());
			this->Edge_Detection = (gcnew System::Windows::Forms::Button());
			this->Log_Transformation = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->Laplacian = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar6 = (gcnew System::Windows::Forms::TrackBar());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Blurring = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->trackBar8 = (gcnew System::Windows::Forms::TrackBar());
			this->Edge__Detection = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->Threshold = (gcnew System::Windows::Forms::Button());
			this->trackBar7 = (gcnew System::Windows::Forms::TrackBar());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->trackBar9 = (gcnew System::Windows::Forms::TrackBar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->Reflecting = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->Vertical_Sobel = (gcnew System::Windows::Forms::Button());
			this->Horizontal_Sobel = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar9))->BeginInit();
			this->SuspendLayout();
			// 
			// Open_Image
			// 
			this->Open_Image->BackColor = System::Drawing::Color::LightGray;
			this->Open_Image->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Open_Image->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Open_Image->Location = System::Drawing::Point(13, 13);
			this->Open_Image->Name = L"Open_Image";
			this->Open_Image->Size = System::Drawing::Size(183, 38);
			this->Open_Image->TabIndex = 0;
			this->Open_Image->Text = L"Open Image";
			this->Open_Image->UseVisualStyleBackColor = false;
			this->Open_Image->Click += gcnew System::EventHandler(this, &ToolBox::button1_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Gray;
			this->label1->Location = System::Drawing::Point(981, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(475, 42);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Abdullah Abdellatif ToolBox";
			this->label1->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// Reset_Image
			// 
			this->Reset_Image->BackColor = System::Drawing::Color::LightGray;
			this->Reset_Image->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Reset_Image->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Reset_Image->Location = System::Drawing::Point(202, 13);
			this->Reset_Image->Name = L"Reset_Image";
			this->Reset_Image->Size = System::Drawing::Size(183, 38);
			this->Reset_Image->TabIndex = 0;
			this->Reset_Image->Text = L"Reset Image";
			this->Reset_Image->UseVisualStyleBackColor = false;
			this->Reset_Image->Click += gcnew System::EventHandler(this, &ToolBox::button1_Click_1);
			// 
			// Histogram
			// 
			this->Histogram->BackColor = System::Drawing::Color::LightGray;
			this->Histogram->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Histogram->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Histogram->Location = System::Drawing::Point(18, 112);
			this->Histogram->Name = L"Histogram";
			this->Histogram->Size = System::Drawing::Size(183, 37);
			this->Histogram->TabIndex = 2;
			this->Histogram->Text = L"Histogram";
			this->Histogram->UseVisualStyleBackColor = false;
			this->Histogram->Click += gcnew System::EventHandler(this, &ToolBox::button1_Click_2);
			// 
			// UNDO
			// 
			this->UNDO->BackColor = System::Drawing::Color::LightGray;
			this->UNDO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UNDO->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->UNDO->Location = System::Drawing::Point(769, 12);
			this->UNDO->Name = L"UNDO";
			this->UNDO->Size = System::Drawing::Size(183, 38);
			this->UNDO->TabIndex = 3;
			this->UNDO->Text = L"UNDO";
			this->UNDO->UseVisualStyleBackColor = false;
			this->UNDO->Click += gcnew System::EventHandler(this, &ToolBox::UNDO_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightGray;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(18, 198);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(178, 37);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Flip";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ToolBox::button1_Click_3);
			// 
			// Skewing
			// 
			this->Skewing->BackColor = System::Drawing::Color::LightGray;
			this->Skewing->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Skewing->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Skewing->Location = System::Drawing::Point(18, 284);
			this->Skewing->Name = L"Skewing";
			this->Skewing->Size = System::Drawing::Size(178, 37);
			this->Skewing->TabIndex = 5;
			this->Skewing->Text = L"Skewing";
			this->Skewing->UseVisualStyleBackColor = false;
			this->Skewing->Click += gcnew System::EventHandler(this, &ToolBox::Skewing_Click);
			// 
			// Zoom
			// 
			this->Zoom->BackColor = System::Drawing::Color::LightGray;
			this->Zoom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Zoom->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Zoom->Location = System::Drawing::Point(391, 112);
			this->Zoom->Name = L"Zoom";
			this->Zoom->Size = System::Drawing::Size(183, 37);
			this->Zoom->TabIndex = 6;
			this->Zoom->Text = L"Zoom";
			this->Zoom->UseVisualStyleBackColor = false;
			this->Zoom->Click += gcnew System::EventHandler(this, &ToolBox::Zoom_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(391, 180);
			this->trackBar1->Maximum = 600;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(183, 56);
			this->trackBar1->TabIndex = 7;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &ToolBox::trackBar1_Scroll);
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(391, 272);
			this->trackBar2->Maximum = 600;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(183, 56);
			this->trackBar2->TabIndex = 8;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &ToolBox::trackBar2_Scroll);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Gray;
			this->label2->Location = System::Drawing::Point(386, 152);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(167, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Zoom_X_Position";
			this->label2->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Gray;
			this->label3->Location = System::Drawing::Point(386, 214);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 25);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Filters";
			this->label3->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Gray;
			this->label4->Location = System::Drawing::Point(779, 408);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(139, 25);
			this->label4->TabIndex = 1;
			this->label4->Text = L"GAMA LEVEL";
			this->label4->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// Median_Filter
			// 
			this->Median_Filter->BackColor = System::Drawing::Color::LightGray;
			this->Median_Filter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Median_Filter->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Median_Filter->Location = System::Drawing::Point(580, 285);
			this->Median_Filter->Name = L"Median_Filter";
			this->Median_Filter->Size = System::Drawing::Size(183, 37);
			this->Median_Filter->TabIndex = 9;
			this->Median_Filter->Text = L"Median Filter";
			this->Median_Filter->UseVisualStyleBackColor = false;
			this->Median_Filter->Click += gcnew System::EventHandler(this, &ToolBox::Median_Filter_Click);
			// 
			// Rotation
			// 
			this->Rotation->BackColor = System::Drawing::Color::LightGray;
			this->Rotation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Rotation->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Rotation->Location = System::Drawing::Point(18, 371);
			this->Rotation->Name = L"Rotation";
			this->Rotation->Size = System::Drawing::Size(183, 37);
			this->Rotation->TabIndex = 10;
			this->Rotation->Text = L"Rotation";
			this->Rotation->UseVisualStyleBackColor = false;
			this->Rotation->Click += gcnew System::EventHandler(this, &ToolBox::Rotation_Click);
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(18, 438);
			this->trackBar3->Maximum = 360;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(183, 56);
			this->trackBar3->TabIndex = 11;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &ToolBox::trackBar3_Scroll);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Gray;
			this->label5->Location = System::Drawing::Point(28, 410);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(152, 25);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Rotation Degree";
			this->label5->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// Frequency
			// 
			this->Frequency->BackColor = System::Drawing::Color::LightGray;
			this->Frequency->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Frequency->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Frequency->Location = System::Drawing::Point(580, 371);
			this->Frequency->Name = L"Frequency";
			this->Frequency->Size = System::Drawing::Size(183, 37);
			this->Frequency->TabIndex = 12;
			this->Frequency->Text = L"Frequency";
			this->Frequency->UseVisualStyleBackColor = false;
			this->Frequency->Click += gcnew System::EventHandler(this, &ToolBox::Frequency_Click);
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(580, 439);
			this->trackBar4->Maximum = 100;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(183, 56);
			this->trackBar4->TabIndex = 13;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &ToolBox::trackBar4_Scroll);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Gray;
			this->label6->Location = System::Drawing::Point(590, 411);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(37, 25);
			this->label6->TabIndex = 1;
			this->label6->Text = L"D0";
			this->label6->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// Open_License
			// 
			this->Open_License->BackColor = System::Drawing::Color::LightGray;
			this->Open_License->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Open_License->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Open_License->Location = System::Drawing::Point(391, 12);
			this->Open_License->Name = L"Open_License";
			this->Open_License->Size = System::Drawing::Size(183, 37);
			this->Open_License->TabIndex = 14;
			this->Open_License->Text = L"Open Licence";
			this->Open_License->UseVisualStyleBackColor = false;
			this->Open_License->Click += gcnew System::EventHandler(this, &ToolBox::Open_License_Click);
			// 
			// Lisence
			// 
			this->Lisence->BackColor = System::Drawing::Color::LightGray;
			this->Lisence->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lisence->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Lisence->Location = System::Drawing::Point(958, 112);
			this->Lisence->Name = L"Lisence";
			this->Lisence->Size = System::Drawing::Size(183, 37);
			this->Lisence->TabIndex = 15;
			this->Lisence->Text = L"Lisence";
			this->Lisence->UseVisualStyleBackColor = false;
			this->Lisence->Click += gcnew System::EventHandler(this, &ToolBox::Lisence_Click);
			// 
			// Noise
			// 
			this->Noise->BackColor = System::Drawing::Color::LightGray;
			this->Noise->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Noise->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Noise->Location = System::Drawing::Point(202, 201);
			this->Noise->Name = L"Noise";
			this->Noise->Size = System::Drawing::Size(183, 37);
			this->Noise->TabIndex = 16;
			this->Noise->Text = L"Noise";
			this->Noise->UseVisualStyleBackColor = false;
			this->Noise->Click += gcnew System::EventHandler(this, &ToolBox::Noise_Click);
			// 
			// Transformation
			// 
			this->Transformation->BackColor = System::Drawing::Color::LightGray;
			this->Transformation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Transformation->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Transformation->Location = System::Drawing::Point(391, 370);
			this->Transformation->Name = L"Transformation";
			this->Transformation->Size = System::Drawing::Size(183, 38);
			this->Transformation->TabIndex = 17;
			this->Transformation->Text = L"Direct Threshold";
			this->Transformation->UseVisualStyleBackColor = false;
			this->Transformation->Click += gcnew System::EventHandler(this, &ToolBox::Transformation_Click);
			// 
			// Negative
			// 
			this->Negative->BackColor = System::Drawing::Color::LightGray;
			this->Negative->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Negative->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Negative->Location = System::Drawing::Point(201, 112);
			this->Negative->Name = L"Negative";
			this->Negative->Size = System::Drawing::Size(183, 37);
			this->Negative->TabIndex = 24;
			this->Negative->Text = L"Negative";
			this->Negative->UseVisualStyleBackColor = false;
			this->Negative->Click += gcnew System::EventHandler(this, &ToolBox::Negative_Click);
			// 
			// Gray_Level
			// 
			this->Gray_Level->BackColor = System::Drawing::Color::LightGray;
			this->Gray_Level->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Gray_Level->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Gray_Level->Location = System::Drawing::Point(202, 377);
			this->Gray_Level->Name = L"Gray_Level";
			this->Gray_Level->Size = System::Drawing::Size(183, 37);
			this->Gray_Level->TabIndex = 25;
			this->Gray_Level->Text = L"Gray Level";
			this->Gray_Level->UseVisualStyleBackColor = false;
			this->Gray_Level->Click += gcnew System::EventHandler(this, &ToolBox::Gray_Level_Click);
			// 
			// tx1
			// 
			this->tx1->BackColor = System::Drawing::Color::LightBlue;
			this->tx1->Location = System::Drawing::Point(241, 445);
			this->tx1->Name = L"tx1";
			this->tx1->Size = System::Drawing::Size(100, 22);
			this->tx1->TabIndex = 18;
			this->tx1->Text = L"10";
			// 
			// tx2
			// 
			this->tx2->BackColor = System::Drawing::Color::LightBlue;
			this->tx2->Location = System::Drawing::Point(241, 469);
			this->tx2->Name = L"tx2";
			this->tx2->Size = System::Drawing::Size(100, 22);
			this->tx2->TabIndex = 20;
			this->tx2->Text = L"10";
			// 
			// Gama
			// 
			this->Gama->BackColor = System::Drawing::Color::LightGray;
			this->Gama->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Gama->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Gama->Location = System::Drawing::Point(769, 370);
			this->Gama->Name = L"Gama";
			this->Gama->Size = System::Drawing::Size(183, 37);
			this->Gama->TabIndex = 26;
			this->Gama->Text = L"Gama";
			this->Gama->UseVisualStyleBackColor = false;
			this->Gama->Click += gcnew System::EventHandler(this, &ToolBox::Gama_Click);
			// 
			// Edge_Detection
			// 
			this->Edge_Detection->BackColor = System::Drawing::Color::LightGray;
			this->Edge_Detection->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Edge_Detection->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Edge_Detection->Location = System::Drawing::Point(580, 112);
			this->Edge_Detection->Name = L"Edge_Detection";
			this->Edge_Detection->Size = System::Drawing::Size(183, 37);
			this->Edge_Detection->TabIndex = 27;
			this->Edge_Detection->Text = L"Bit Plane";
			this->Edge_Detection->UseVisualStyleBackColor = false;
			this->Edge_Detection->Click += gcnew System::EventHandler(this, &ToolBox::Edge_Detection_Click);
			// 
			// Log_Transformation
			// 
			this->Log_Transformation->BackColor = System::Drawing::Color::LightGray;
			this->Log_Transformation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Log_Transformation->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Log_Transformation->Location = System::Drawing::Point(963, 198);
			this->Log_Transformation->Name = L"Log_Transformation";
			this->Log_Transformation->Size = System::Drawing::Size(178, 37);
			this->Log_Transformation->TabIndex = 28;
			this->Log_Transformation->Text = L"Log Transformation";
			this->Log_Transformation->UseVisualStyleBackColor = false;
			this->Log_Transformation->Click += gcnew System::EventHandler(this, &ToolBox::Log_Transformation_Click);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::LightBlue;
			this->textBox3->Location = System::Drawing::Point(595, 473);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 18;
			this->textBox3->Text = L"10";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::LightBlue;
			this->textBox1->Location = System::Drawing::Point(405, 217);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(105, 22);
			this->textBox1->TabIndex = 18;
			this->textBox1->Text = L"10";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ToolBox::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::LightBlue;
			this->textBox2->Location = System::Drawing::Point(33, 479);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 18;
			this->textBox2->Text = L"10";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &ToolBox::textBox2_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::LightBlue;
			this->textBox4->Location = System::Drawing::Point(405, 306);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(105, 22);
			this->textBox4->TabIndex = 18;
			this->textBox4->Text = L"10";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &ToolBox::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::LightBlue;
			this->textBox5->Location = System::Drawing::Point(784, 477);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 18;
			this->textBox5->Text = L"10";
			// 
			// Laplacian
			// 
			this->Laplacian->BackColor = System::Drawing::Color::LightGray;
			this->Laplacian->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Laplacian->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Laplacian->Location = System::Drawing::Point(958, 284);
			this->Laplacian->Name = L"Laplacian";
			this->Laplacian->Size = System::Drawing::Size(183, 38);
			this->Laplacian->TabIndex = 29;
			this->Laplacian->Text = L"Laplacian";
			this->Laplacian->UseVisualStyleBackColor = false;
			this->Laplacian->Click += gcnew System::EventHandler(this, &ToolBox::Laplacian_Click);
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::LightBlue;
			this->textBox6->Location = System::Drawing::Point(593, 221);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 22);
			this->textBox6->TabIndex = 18;
			this->textBox6->Text = L"10";
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &ToolBox::textBox6_TextChanged);
			// 
			// trackBar5
			// 
			this->trackBar5->Location = System::Drawing::Point(769, 436);
			this->trackBar5->Maximum = 360;
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(183, 56);
			this->trackBar5->TabIndex = 11;
			this->trackBar5->Scroll += gcnew System::EventHandler(this, &ToolBox::trackBar5_Scroll);
			// 
			// trackBar6
			// 
			this->trackBar6->Location = System::Drawing::Point(580, 178);
			this->trackBar6->Maximum = 250;
			this->trackBar6->Name = L"trackBar6";
			this->trackBar6->Size = System::Drawing::Size(183, 56);
			this->trackBar6->TabIndex = 31;
			this->trackBar6->Scroll += gcnew System::EventHandler(this, &ToolBox::trackBar6_Scroll);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Gray;
			this->label7->Location = System::Drawing::Point(973, 416);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(100, 25);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Threshold";
			this->label7->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// Blurring
			// 
			this->Blurring->BackColor = System::Drawing::Color::LightGray;
			this->Blurring->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Blurring->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Blurring->Location = System::Drawing::Point(769, 112);
			this->Blurring->Name = L"Blurring";
			this->Blurring->Size = System::Drawing::Size(183, 37);
			this->Blurring->TabIndex = 32;
			this->Blurring->Text = L"Blurring";
			this->Blurring->UseVisualStyleBackColor = false;
			this->Blurring->Click += gcnew System::EventHandler(this, &ToolBox::Blurring_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Gray;
			this->label8->Location = System::Drawing::Point(13, 84);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(187, 25);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Image contrast Filter";
			this->label8->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::LightBlue;
			this->textBox7->Location = System::Drawing::Point(793, 214);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 22);
			this->textBox7->TabIndex = 18;
			this->textBox7->Text = L"10";
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &ToolBox::textBox1_TextChanged);
			// 
			// trackBar8
			// 
			this->trackBar8->Location = System::Drawing::Point(774, 180);
			this->trackBar8->Name = L"trackBar8";
			this->trackBar8->Size = System::Drawing::Size(178, 56);
			this->trackBar8->TabIndex = 33;
			this->trackBar8->Scroll += gcnew System::EventHandler(this, &ToolBox::trackBar8_Scroll);
			// 
			// Edge__Detection
			// 
			this->Edge__Detection->BackColor = System::Drawing::Color::LightGray;
			this->Edge__Detection->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Edge__Detection->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Edge__Detection->Location = System::Drawing::Point(769, 284);
			this->Edge__Detection->Name = L"Edge__Detection";
			this->Edge__Detection->Size = System::Drawing::Size(183, 37);
			this->Edge__Detection->TabIndex = 34;
			this->Edge__Detection->Text = L"Edge Detection";
			this->Edge__Detection->UseVisualStyleBackColor = false;
			this->Edge__Detection->Click += gcnew System::EventHandler(this, &ToolBox::Edge__Detection_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Gray;
			this->label9->Location = System::Drawing::Point(958, 256);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(197, 25);
			this->label9->TabIndex = 1;
			this->label9->Text = L"Three edge detection";
			this->label9->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// Threshold
			// 
			this->Threshold->BackColor = System::Drawing::Color::LightGray;
			this->Threshold->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Threshold->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Threshold->Location = System::Drawing::Point(963, 370);
			this->Threshold->Name = L"Threshold";
			this->Threshold->Size = System::Drawing::Size(178, 37);
			this->Threshold->TabIndex = 35;
			this->Threshold->Text = L"Threshold";
			this->Threshold->UseVisualStyleBackColor = false;
			this->Threshold->Click += gcnew System::EventHandler(this, &ToolBox::Threshold_Click);
			// 
			// trackBar7
			// 
			this->trackBar7->Location = System::Drawing::Point(963, 439);
			this->trackBar7->Maximum = 255;
			this->trackBar7->Name = L"trackBar7";
			this->trackBar7->Size = System::Drawing::Size(178, 56);
			this->trackBar7->TabIndex = 36;
			this->trackBar7->Scroll += gcnew System::EventHandler(this, &ToolBox::trackBar7_Scroll);
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::Color::LightBlue;
			this->textBox8->Location = System::Drawing::Point(988, 472);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 22);
			this->textBox8->TabIndex = 37;
			this->textBox8->Text = L"10";
			// 
			// textBox9
			// 
			this->textBox9->BackColor = System::Drawing::Color::LightBlue;
			this->textBox9->Location = System::Drawing::Point(403, 473);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 22);
			this->textBox9->TabIndex = 38;
			this->textBox9->Text = L"10";
			// 
			// trackBar9
			// 
			this->trackBar9->Location = System::Drawing::Point(391, 430);
			this->trackBar9->Name = L"trackBar9";
			this->trackBar9->Size = System::Drawing::Size(183, 56);
			this->trackBar9->TabIndex = 39;
			this->trackBar9->Scroll += gcnew System::EventHandler(this, &ToolBox::trackBar9_Scroll);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Gray;
			this->label10->Location = System::Drawing::Point(588, 152);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(89, 25);
			this->label10->TabIndex = 1;
			this->label10->Text = L"Bit Plane";
			this->label10->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Gray;
			this->label11->Location = System::Drawing::Point(398, 411);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(156, 25);
			this->label11->TabIndex = 1;
			this->label11->Text = L"Threshold Value";
			this->label11->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// Reflecting
			// 
			this->Reflecting->BackColor = System::Drawing::Color::LightGray;
			this->Reflecting->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Reflecting->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Reflecting->Location = System::Drawing::Point(202, 284);
			this->Reflecting->Name = L"Reflecting";
			this->Reflecting->Size = System::Drawing::Size(182, 37);
			this->Reflecting->TabIndex = 40;
			this->Reflecting->Text = L"Reflecting";
			this->Reflecting->UseVisualStyleBackColor = false;
			this->Reflecting->Click += gcnew System::EventHandler(this, &ToolBox::Reflecting_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LightGray;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Location = System::Drawing::Point(580, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(183, 36);
			this->button2->TabIndex = 41;
			this->button2->Text = L"REDO";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &ToolBox::button2_Click_1);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(-10, 530);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(1578, 180);
			this->richTextBox1->TabIndex = 42;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &ToolBox::richTextBox1_TextChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Gray;
			this->label12->Location = System::Drawing::Point(198, 84);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(185, 25);
			this->label12->TabIndex = 1;
			this->label12->Text = L"Reverse colors filter\'";
			this->label12->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Gray;
			this->label13->Location = System::Drawing::Point(389, 84);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(196, 25);
			this->label13->TabIndex = 1;
			this->label13->Text = L"Zooming 2x using x,y";
			this->label13->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::Gray;
			this->label14->Location = System::Drawing::Point(581, 84);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(182, 25);
			this->label14->TabIndex = 1;
			this->label14->Text = L"Slicing the bit range";
			this->label14->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::Gray;
			this->label15->Location = System::Drawing::Point(770, 84);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(153, 25);
			this->label15->TabIndex = 1;
			this->label15->Text = L"Blur and smooth";
			this->label15->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::Transparent;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::Gray;
			this->label16->Location = System::Drawing::Point(958, 84);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(123, 25);
			this->label16->TabIndex = 1;
			this->label16->Text = L"Find License";
			this->label16->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::Color::Transparent;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::Gray;
			this->label17->Location = System::Drawing::Point(13, 170);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(144, 25);
			this->label17->TabIndex = 1;
			this->label17->Text = L"Flip UP DOWN";
			this->label17->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::Color::Transparent;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::Color::Gray;
			this->label18->Location = System::Drawing::Point(211, 170);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(109, 25);
			this->label18->TabIndex = 1;
			this->label18->Text = L"ADD Noise";
			this->label18->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::Color::Transparent;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::Gray;
			this->label19->Location = System::Drawing::Point(24, 256);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(176, 25);
			this->label19->TabIndex = 1;
			this->label19->Text = L"Bending with angle";
			this->label19->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->BackColor = System::Drawing::Color::Transparent;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::Gray;
			this->label20->Location = System::Drawing::Point(206, 256);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(88, 25);
			this->label20->TabIndex = 1;
			this->label20->Text = L"Mirroring";
			this->label20->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->BackColor = System::Drawing::Color::Transparent;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::Color::Gray;
			this->label21->Location = System::Drawing::Point(400, 244);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(166, 25);
			this->label21->TabIndex = 1;
			this->label21->Text = L"Zoom_Y_Position";
			this->label21->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->BackColor = System::Drawing::Color::Transparent;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::Color::Gray;
			this->label22->Location = System::Drawing::Point(13, 343);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(160, 25);
			this->label22->TabIndex = 1;
			this->label22->Text = L"Rotate by degree";
			this->label22->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->BackColor = System::Drawing::Color::Transparent;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::Color::Gray;
			this->label23->Location = System::Drawing::Point(206, 343);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(167, 25);
			this->label23->TabIndex = 1;
			this->label23->Text = L"Select level range";
			this->label23->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->BackColor = System::Drawing::Color::Transparent;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::Color::Gray;
			this->label24->Location = System::Drawing::Point(386, 343);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(194, 25);
			this->label24->TabIndex = 1;
			this->label24->Text = L"Threshold using func";
			this->label24->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->BackColor = System::Drawing::Color::Transparent;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::Color::Gray;
			this->label25->Location = System::Drawing::Point(581, 343);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(139, 25);
			this->label25->TabIndex = 1;
			this->label25->Text = L"Freq pass filter";
			this->label25->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->BackColor = System::Drawing::Color::Transparent;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::Color::Gray;
			this->label26->Location = System::Drawing::Point(769, 342);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(192, 25);
			this->label26->TabIndex = 1;
			this->label26->Text = L"Correction using eqn";
			this->label26->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->BackColor = System::Drawing::Color::Transparent;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->ForeColor = System::Drawing::Color::Gray;
			this->label27->Location = System::Drawing::Point(958, 342);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(159, 25);
			this->label27->TabIndex = 1;
			this->label27->Text = L"Highlight Objects";
			this->label27->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->BackColor = System::Drawing::Color::Transparent;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->ForeColor = System::Drawing::Color::Gray;
			this->label28->Location = System::Drawing::Point(958, 170);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(104, 25);
			this->label28->TabIndex = 1;
			this->label28->Text = L"Brightness";
			this->label28->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->BackColor = System::Drawing::Color::Transparent;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->ForeColor = System::Drawing::Color::Gray;
			this->label29->Location = System::Drawing::Point(572, 256);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(171, 25);
			this->label29->TabIndex = 1;
			this->label29->Text = L"Fixes Salt & Pepper";
			this->label29->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->BackColor = System::Drawing::Color::Transparent;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->ForeColor = System::Drawing::Color::Gray;
			this->label30->Location = System::Drawing::Point(770, 256);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(142, 25);
			this->label30->TabIndex = 1;
			this->label30->Text = L"Edge detection";
			this->label30->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// Vertical_Sobel
			// 
			this->Vertical_Sobel->BackColor = System::Drawing::Color::LightGray;
			this->Vertical_Sobel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Vertical_Sobel->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Vertical_Sobel->Location = System::Drawing::Point(1216, 159);
			this->Vertical_Sobel->Name = L"Vertical_Sobel";
			this->Vertical_Sobel->Size = System::Drawing::Size(178, 37);
			this->Vertical_Sobel->TabIndex = 43;
			this->Vertical_Sobel->Text = L"Vertical Sobel";
			this->Vertical_Sobel->UseVisualStyleBackColor = false;
			this->Vertical_Sobel->Click += gcnew System::EventHandler(this, &ToolBox::Vertical_Sobel_Click);
			// 
			// Horizontal_Sobel
			// 
			this->Horizontal_Sobel->BackColor = System::Drawing::Color::LightGray;
			this->Horizontal_Sobel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Horizontal_Sobel->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Horizontal_Sobel->Location = System::Drawing::Point(1216, 256);
			this->Horizontal_Sobel->Name = L"Horizontal_Sobel";
			this->Horizontal_Sobel->Size = System::Drawing::Size(178, 33);
			this->Horizontal_Sobel->TabIndex = 44;
			this->Horizontal_Sobel->Text = L"Horizontal Sobel";
			this->Horizontal_Sobel->UseVisualStyleBackColor = false;
			this->Horizontal_Sobel->Click += gcnew System::EventHandler(this, &ToolBox::Horizontal_Sobel_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LightGray;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button4->Location = System::Drawing::Point(1216, 342);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(178, 37);
			this->button4->TabIndex = 45;
			this->button4->Text = L"HORIZ & VERT Sobel";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &ToolBox::button4_Click);
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->BackColor = System::Drawing::Color::Transparent;
			this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->ForeColor = System::Drawing::Color::Gray;
			this->label31->Location = System::Drawing::Point(1220, 131);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(135, 25);
			this->label31->TabIndex = 1;
			this->label31->Text = L"Vertical Sharp";
			this->label31->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->BackColor = System::Drawing::Color::Transparent;
			this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->ForeColor = System::Drawing::Color::Gray;
			this->label32->Location = System::Drawing::Point(1220, 228);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(157, 25);
			this->label32->TabIndex = 1;
			this->label32->Text = L"Horizontal Sharp";
			this->label32->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->BackColor = System::Drawing::Color::Transparent;
			this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label33->ForeColor = System::Drawing::Color::Gray;
			this->label33->Location = System::Drawing::Point(1220, 314);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(149, 25);
			this->label33->TabIndex = 1;
			this->label33->Text = L"Combine Sharp";
			this->label33->Click += gcnew System::EventHandler(this, &ToolBox::label1_Click);
			// 
			// textBox10
			// 
			this->textBox10->BackColor = System::Drawing::Color::LightBlue;
			this->textBox10->Location = System::Drawing::Point(13, 59);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(100, 22);
			this->textBox10->TabIndex = 20;
			this->textBox10->Text = L"\"\"";
			this->textBox10->TextChanged += gcnew System::EventHandler(this, &ToolBox::textBox10_TextChanged);
			// 
			// ToolBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1492, 687);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->Horizontal_Sobel);
			this->Controls->Add(this->Vertical_Sobel);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->Reflecting);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->trackBar7);
			this->Controls->Add(this->Threshold);
			this->Controls->Add(this->Edge__Detection);
			this->Controls->Add(this->Blurring);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->trackBar6);
			this->Controls->Add(this->Laplacian);
			this->Controls->Add(this->Log_Transformation);
			this->Controls->Add(this->Edge_Detection);
			this->Controls->Add(this->Gama);
			this->Controls->Add(this->Gray_Level);
			this->Controls->Add(this->Negative);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->tx2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->tx1);
			this->Controls->Add(this->Transformation);
			this->Controls->Add(this->Noise);
			this->Controls->Add(this->Lisence);
			this->Controls->Add(this->Open_License);
			this->Controls->Add(this->trackBar4);
			this->Controls->Add(this->Frequency);
			this->Controls->Add(this->trackBar5);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->Rotation);
			this->Controls->Add(this->Median_Filter);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->Zoom);
			this->Controls->Add(this->Skewing);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->UNDO);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->Histogram);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Reset_Image);
			this->Controls->Add(this->Open_Image);
			this->Controls->Add(this->trackBar8);
			this->Controls->Add(this->trackBar9);
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Name = L"ToolBox";
			this->Text = L"Abdullah Abdellatif TOOLBOX";
			this->Load += gcnew System::EventHandler(this, &ToolBox::ToolBox_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar9))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ToolBox_Load(System::Object^ sender, System::EventArgs^ e) {
	/*this->BackColor = Color::FromArgb(31, 32, 36);
	Open_Image->BackColor = Color::FromArgb(37, 78, 117);  // A blue shade similar to GPT-3's blue
	Close_Image->BackColor = Color::FromArgb(37, 78, 117);
	Reset_Image->BackColor = Color::FromArgb(37, 78, 117);
	Close_Form->BackColor = Color::FromArgb(37, 78, 117);*/
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		license_flag = 0;
		// Get the string from the textbox
		// Inside a method or event handler in your Windows Forms application
		System::String^ userInput = textBox10->Text;

		// Convert the String to a standard C++ string
		std::string userInputString = msclr::interop::marshal_as<std::string>(userInput);

		// Load the image using OpenCV
		Mat image = imread(userInputString);

		// Check if the image was successfully loaded
		if (!image.empty())
		{
			// Assuming 'src' is a Mat variable declared earlier
			src = image.clone();
		}
		namedWindow("Image", 0);
		imshow("Image", src);

		for (int i = 0; i < 2500; ++i) {
			dst[i] = src.clone(); // Use clone() to create a copy
		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click_2(System::Object^ sender, System::EventArgs^ e) {
	/*	Histogram Equalization	*/
	
	if(hist == 0){
		OP++;
	equalizeHist(dst[(OP - 1)], dst[OP]);

	imshow("Image", dst[OP]);
	hist=1;
	}
}
private: System::Void UNDO_Click(System::Object^ sender, System::EventArgs^ e) {
	if (OP != 0) {
		/*UNDO*/
		OP--;
		imshow("Image", dst[OP]);
		hist = 0;
		
	}
}
private: System::Void button1_Click_3(System::Object^ sender, System::EventArgs^ e) {
	/*Image Flip*/
	OP++;
	flip(dst[(OP-1)], dst[OP],0);
	
	imshow("Image", dst[OP]);
	hist = 0;
}
private: System::Void Skewing_Click(System::Object^ sender, System::EventArgs^ e) {
	/*Skewing*/

	OP++;
	Point2f S_point[3];
	Point2f E_point[3];
	S_point[0] = Point2f(0, 0);
	S_point[1] = Point2f(dst[(OP - 1)].cols - 1, 0);
	S_point[2] = Point2f(100, dst[(OP - 1)].rows - 1);
	E_point[0] = Point2f(0, 0);
	E_point[1] = Point2f(dst[(OP - 1)].cols - 1, 0);
	E_point[2] = Point2f(0, dst[(OP - 1)].rows - 1);
	Mat sm = getAffineTransform(S_point, E_point);
	warpAffine(dst[(OP - 1)], dst[OP], sm, dst[(OP - 1)].size());

	imshow("Image", dst[OP]);
	
	
}
private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
	TrackBar_2 = Convert::ToInt32(trackBar2->Value);
	int val3 = trackBar2->Value;
	textBox4->Text = val3.ToString();

}

private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	TrackBar_1 = Convert::ToInt32(trackBar1->Value);
	int val2 = trackBar1->Value;
	textBox1->Text = val2.ToString();
}

private: System::Void Zoom_Click(System::Object^ sender, System::EventArgs^ e) {
	/*Image zoom*/
	OP++;

	Mat zoom = dst[(OP - 1)](Rect(TrackBar_1, TrackBar_2, dst[(OP - 1)].cols / 2, dst[(OP - 1)].rows / 2));

	// Create a new Mat with double the size
	Mat zoomedMat;
	zoomedMat.create(zoom.rows * 2, zoom.cols * 2, zoom.type());

	// Resize the region to the new Mat
	resize(zoom, zoomedMat, zoomedMat.size(), 0, 0, INTER_LINEAR);

	// Copy the zoomed region back to the original Mat
	zoomedMat.copyTo(dst[OP]);

	imshow("Image", dst[OP]);

}
	   


private: System::Void Median_Filter_Click(System::Object^ sender, System::EventArgs^ e) {
	/*Median*/
	OP++;
	medianBlur(dst[(OP-1)], dst[OP], 11);
	imshow("Image", dst[OP]);
}
private: System::Void Rotation_Click(System::Object^ sender, System::EventArgs^ e) {
	/*	Image rotation	*/
	
	OP++;
	TrackBar_3 = Convert::ToInt32(trackBar3->Value);
	Mat R = getRotationMatrix2D(Point2f(dst[(OP - 1)].cols / 2, dst[(OP - 1)].rows / 2), TrackBar_3, 1);
	warpAffine(dst[(OP - 1)], dst[OP], R, dst[(OP - 1)].size());
	imshow("Image", dst[OP]);

}

private: System::Void Frequency_Click(System::Object^ sender, System::EventArgs^ e) {
	Freq_Filter();
}
	   void Freq_Filter(void) {
		   OP++;
		   
		   float sigma = 23;





		   // Expand the image to an optimal size
		   int m = getOptimalDFTSize(dst[(OP - 1)].rows), n = getOptimalDFTSize(dst[(OP - 1)].cols);
		   Mat padded;
		   copyMakeBorder(dst[(OP - 1)], padded, 0, m - dst[(OP - 1)].rows, 0, n - dst[(OP - 1)].cols, 0, Scalar(0));

		   // Make place for both complex and real values
		   padded.convertTo(padded, CV_32FC1, 1.0 / 255.0);

		   Mat planes[2] = { padded, Mat::zeros(padded.size(), CV_32FC1) };
		   Mat complexI;
		   merge(planes, 2, complexI);

		   // Make discrete Fourier transform
		   dft(complexI, complexI);

		   // Visualize DFT

		   //DFTShow(planes);
		   int cx = complexI.cols / 2;
		   int cy = complexI.rows / 2;
		   Mat p1(complexI, Rect(0, 0, cx, cy));
		   Mat p2(complexI, Rect(cx, 0, cx, cy));
		   Mat p3(complexI, Rect(0, cy, cx, cy));
		   Mat p4(complexI, Rect(cx, cy, cx, cy));
		   Mat temp;
		   p1.copyTo(temp);
		   p4.copyTo(p1);
		   temp.copyTo(p4);
		   p2.copyTo(temp);
		   p3.copyTo(p2);
		   temp.copyTo(p3);
		   int d0 = (int)Convert::ToInt32(trackBar4->Value);
		    
		   Mat Lfilter(complexI.size(), CV_32FC1);
		   
		   for (int i = 0; i < Lfilter.rows; i++)
			   for (int j = 0; j < Lfilter.cols; j++)
			   {
				   double z1 = i - Lfilter.rows / 2;
				   double z2 = j - Lfilter.cols / 2;
				   if (sqrt(pow(z1, 2) + pow(z2, 2)) <= d0)
					   Lfilter.at<float>(i, j) = 1;
				   else
					   Lfilter.at<float>(i, j) = 0;
			   }


		   split(complexI, planes);

		   // Apply filter on both real and imaginary parts
		   Mat out_r, out_i;
		   multiply(planes[0], Lfilter, out_r);
		   multiply(planes[1], Lfilter, out_i);
		   Mat plane_out[2] = { out_r, out_i };
		   Mat complex_out;
		   merge(plane_out, 2, complex_out);

		   // Take inverse
		   idft(complex_out, complex_out);
		   split(complex_out, planes);


		   magnitude(planes[0], planes[1], dst[OP]);

		   // Normalize
		   normalize(dst[OP], dst[OP], 1, 0, NORM_MINMAX);
		   //dst[OP-1] = dst[OP-2].clone();
		   imshow("Image", dst[OP]);
		   dst[OP].convertTo(dst[OP], CV_8U);
		   freq_Flag = 1;

	   }
private: System::Void Open_License_Click(System::Object^ sender, System::EventArgs^ e) {
	license_flag=1;
	namedWindow("Image", 0);
	imshow("Image", src_Licence);

	for (int i = 0; i < 2500; ++i) {
		dst[i] = src_Licence.clone(); // Use clone() to create a copy
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
}
private: System::Void Lisence_Click(System::Object^ sender, System::EventArgs^ e) {
	if (license_flag == 1) {
		OP++;


		// Convert the image to grayscale
		Mat gray;
		cvtColor(dst[OP - 1], gray, COLOR_BGR2GRAY);

		// Apply Gaussian blur to reduce noise
		GaussianBlur(gray, gray, cv::Size(5, 5), 0);

		// Apply edge detection using Canny
		Mat edges;
		Canny(gray, edges, 150, 300);

		// Find contours in the edges image
		vector<vector<cv::Point>> contours;
		findContours(edges, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

		// Filter out contours that are not likely to be license plates
		vector<vector<cv::Point>> licensePlateContours;
		for (const auto& contour : contours) {
			// Convert the contour to a convex hull to simplify
			vector<cv::Point> convexHull;
			cv::convexHull(contour, convexHull);
			double area = contourArea(convexHull);
			if (area > 1000 && area < 50000) {
				licensePlateContours.push_back(convexHull);
			}
		}

		// Draw the contours on the original image
		dst[OP] = dst[OP - 1].clone();
		drawContours(dst[OP], licensePlateContours, -1, Scalar(0, 255, 0), 2);

		// Display the result
		imshow("Image", dst[OP]);
		/*Convert to grayscale, apply Gaussian blur and Canny edge detection.
		Find contours, filter likely license plates based on area.
		Draw contours on the original image, displaying the result 
		with highlighted potential license plates using OpenCV.*/
	}
}
private: System::Void Noise_Click(System::Object^ sender, System::EventArgs^ e) {
	OP++;
	double noiseRatio = 0.02; // Adjust the noise ratio according to your preference
	Mat noise = Mat::zeros(dst[OP-1].size(), dst[OP - 1].type());
	randu(noise, 0, 255);

	Mat salt = noise > 255 * (1 - noiseRatio);
	Mat pepper = noise < 255 * noiseRatio;
	dst[OP] = dst[OP - 1].clone();
	dst[OP].setTo(255, salt);
	dst[OP].setTo(0, pepper);

	namedWindow("Image", 0);
	imshow("Image", dst[OP]);

}
private: System::Void Transformation_Click(System::Object^ sender, System::EventArgs^ e) {
	OP++;
	// Perform scaling
	double scale_x = (double)(trackBar9->Value) ;
	

	threshold(dst[OP - 1], dst[OP], 100, 255, THRESH_BINARY);


		imshow("Image", dst[OP]);
	
}
private: System::Void Negative_Click(System::Object^ sender, System::EventArgs^ e) {
	OP++;
	for (int i = 0; i < dst[OP-1].rows; i++)
		for (int j = 0; j < dst[OP-1].cols; j++)
			dst[OP].at<uchar>(i, j) = 255 - dst[OP-1].at<uchar>(i, j);
	imshow("Image", dst[OP]);
    

}
private: System::Void Gray_Level_Click(System::Object^ sender, System::EventArgs^ e) {
	OP++;
	// Get the range values from textBox1 and textBox2
	int rangeStart = System::Convert::ToInt32(tx1->Text);
	int rangeEnd = System::Convert::ToInt32(tx2->Text);
	if (rangeEnd >rangeStart && rangeStart >= 250 ) {
		// Perform gray level slicing based on user-defined range
		for (int i = 0; i < dst[OP - 1].rows; i++) {
			for (int j = 0; j < dst[OP - 1].cols; j++) {
				if (dst[OP - 1].at<uchar>(i, j) > rangeStart && dst[OP - 1].at<uchar>(i, j) < rangeEnd)
					dst[OP].at<uchar>(i, j) = 255;
				else
					dst[OP].at<uchar>(i, j) = dst[OP - 1].at<uchar>(i, j);
			}
		}
	}
	imshow("Image", dst[OP]);
}
private: System::Void Gama_Click(System::Object^ sender, System::EventArgs^ e) {
	OP++;
	dst[OP] = dst[OP - 1].clone();
	OP++;
	float gammaValue = (float)(trackBar5->Value) / 10.0; // Get the gamma value from the trackbar

	// Apply gamma correction to increase or decrease brightness
	Mat temp;
	dst[OP-1].convertTo(temp, CV_32F, 1.0 / 255.0); // Convert to float, and normalize intensity to range [0,1]

	dst[OP] = Mat::zeros(dst[OP - 1].size(), CV_32F); // Create an empty matrix to store the corrected image

	for (int i = 0; i < dst[OP - 1].rows; i++) {
		for (int j = 0; j < dst[OP - 1].cols; j++) {
			dst[OP].at<float>(i, j) = pow(temp.at<float>(i, j), gammaValue);
		}
	}

	normalize(dst[OP], dst[OP], 0, 1, NORM_MINMAX); // Normalize the image intensity to [0,1]
	dst[OP] = dst[OP] * 255.0; // Scale back to the 0-255 range

	dst[OP].convertTo(dst[OP - 1], CV_8U); // Convert back to an 8-bit image for display
	imshow("Image", dst[OP]);
	/*Adjust image brightness using gamma correction based on a trackbar value. Convert to float,
	apply correction, normalize, scale, and convert back for display using OpenCV.*/
}
private: System::Void Edge_Detection_Click(System::Object^ sender, System::EventArgs^ e) {
	OP++;
	// Get the range values from textBox1 and textBox2
	int NUM = System::Convert::ToInt32(textBox6->Text);
	
	
		// Perform gray level slicing based on user-defined range
		for (int i = 0; i < dst[OP - 1].rows; i++) {
			for (int j = 0; j < dst[OP - 1].cols; j++) {
				if (dst[OP - 1].at<uchar>(i, j) & 64)
					dst[OP].at<uchar>(i, j) = 255;
				else
					dst[OP].at<uchar>(i, j) = 0;
			}
			imshow("Image", dst[OP]);
			//For fun showing the scenario
			waitKey(0);
		}
	
	imshow("Image", dst[OP]);
	
}
private: System::Void Log_Transformation_Click(System::Object^ sender, System::EventArgs^ e) {
	OP++;
	dst[OP] = dst[OP - 1].clone();
	OP++;
	double alpha = 1.5;  // Increase this value for brighter transformation

	
	dst[OP - 1].convertTo(dst[OP], CV_32F);  // Convert to float for arithmetic operations

	// Increase brightness by adding a constant value
	//dst = dst * alpha;


	dst[OP - 1].convertTo(dst[OP], CV_32FC1);
	dst[OP] = dst[OP] + 1;
	log(dst[OP], dst[OP]);
	normalize(dst[OP], dst[OP], 0, 255, NORM_MINMAX);
	convertScaleAbs(dst[OP], dst[OP]);
	/*Increase image brightness by converting to float, adding a constant,
	taking the logarithm, normalizing, and converting back to unsigned char.
	Adjust the 'alpha' parameter for brightness control.
	Display the transformed image using OpenCV.*/
	
	imshow("Image", dst[OP]);

}
private: System::Void trackBar4_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int val = trackBar4->Value;
	textBox3->Text = val.ToString();
	
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	int val2 = trackBar1->Value;
	textBox1->Text = val2.ToString();
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	int val3 = trackBar2->Value;
	textBox4->Text = val3.ToString();
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	int val3 = trackBar3->Value;
	textBox2->Text = val3.ToString();
}
private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int val3 = trackBar3->Value;
	textBox2->Text = val3.ToString();
}
private: System::Void trackBar5_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int val4 = trackBar5->Value;
	textBox5->Text = val4.ToString();
}
private: System::Void x1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void Laplacian_Click(System::Object^ sender, System::EventArgs^ e) {
	////LABLCIAN
	OP++;
	Mat kernel_L = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	filter2D(dst[OP-1], dst[OP], CV_8UC1, kernel_L);
	cv::Laplacian(dst[OP], dst[OP], CV_8UC1);
	/*used in image processing to highlight regions of rapid 
	intensity change, emphasizing edges and fine details. */
	dst[OP].convertTo(dst[OP], CV_8U);
	imshow("Image", dst[OP]);
}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar6_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int val3 = trackBar6->Value;
	textBox6->Text = val3.ToString();
}
private: System::Void Blurring_Click(System::Object^ sender, System::EventArgs^ e) {
	// Apply Gaussian blur
	OP++;
	int kernelSize = Convert::ToInt32(trackBar8->Value);  // Adjust kernel size as needed
	if(kernelSize % 2 !=0){
	GaussianBlur(dst[OP - 1], dst[OP], cv::Size(kernelSize, kernelSize), 0);
	}
	else {
		kernelSize++;
		GaussianBlur(dst[OP - 1], dst[OP], cv::Size(kernelSize, kernelSize), 0);
	}

	// Optionally, you can use other blur functions like:
	// blur(dst[OP-1], dst[OP], cv::Size(kernelSize, kernelSize));
	// medianBlur(dst[OP-1], dst[OP], kernelSize);
	// bilateralFilter(dst[OP-1], dst[OP], kernelSize, kernelSize * 2, kernelSize / 2);

	// Display the result
	imshow("Image", dst[OP]);

}
private: System::Void trackBar8_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int val3 = trackBar8->Value;
	textBox7->Text = val3.ToString();
}
private: System::Void Edge__Detection_Click(System::Object^ sender, System::EventArgs^ e) {

	OP++;
	Mat  dstG;
	//////////////////////// smoothing/////////////////
	Mat kernel_G = (Mat_<float>(3, 3) << 1, 2, 1, 2, 4, 2, 1, 2, 1);
	kernel_G = kernel_G / 16;
	filter2D(dst[OP - 1], dstG, CV_8UC1, kernel_G);

	//////////////////////// edge detection/////////////////
	Mat kernel_L = (Mat_<float>(3, 3) << -1, -1, -1, -1, 8, -1, -1, -1, -1);
	filter2D(dst[OP - 1], dst[OP], CV_8UC1, kernel_L);
	imshow("Image", dst[OP]);
	
	


}
private: System::Void trackBar7_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int val33 = trackBar7->Value;
	textBox8->Text = val33.ToString();
}
private: System::Void Threshold_Click(System::Object^ sender, System::EventArgs^ e) {
	OP++;
	Mat  dstG;
	//////////////////////// smoothing/////////////////
	Mat kernel_G = (Mat_<float>(3, 3) << 1, 2, 1, 2, 4, 2, 1, 2, 1);
	kernel_G = kernel_G / 16;
	filter2D(dst[OP - 1], dstG, CV_8UC1, kernel_G);

	//////////////////////// edge detection/////////////////
	Mat kernel_L = (Mat_<float>(3, 3) << -1, -1, -1, -1, 8, -1, -1, -1, -1);
	filter2D(dst[OP - 1], dst[OP], CV_8UC1, kernel_L);

	///////////threshold based segmentation/////////
	Mat dst_T(src.rows, src.cols, CV_8UC1);
	int threshold = System::Convert::ToInt32(textBox8->Text);

	int x = 0;
	while (x < 10)
	{
		for (int r = 0; r < src.rows; r++)
		{
			for (int c = 0; c < src.cols; c++)
			{
				if (dst[OP - 1].at<uchar>(r, c) > threshold)
					dst_T.at<uchar>(r, c) = 255;
				else
					dst_T.at<uchar>(r, c) = 0;
			}
		}

		x++;

	}
	dst[OP] = dst_T.clone();

	imshow("Image", dst[OP]);
}
private: System::Void trackBar9_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int val4 = trackBar9->Value;
	textBox9->Text = val4.ToString();
}
private: System::Void trackBar10_Scroll(System::Object^ sender, System::EventArgs^ e) {
	//int val4 = trackBar10->Value;
	//textBox10->Text = val4.ToString();
}
private: System::Void Reflecting_Click(System::Object^ sender, System::EventArgs^ e) {
	/*Image Flip*/
	OP++;
	flip(dst[(OP - 1)], dst[OP], 1);

	imshow("Image", dst[OP]);
}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (OP != 0) {
		/*UNDO*/
		OP++;
		imshow("Image", dst[OP]);
		
	}
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	OP++;

	// Apply Sobel filter horizontally

	cv::Sobel(dst[OP - 1], dst[OP], CV_16S, 1, 0);
	cv::convertScaleAbs(dst[OP], dst[OP]);


	// Apply Sobel filter Vertically
	OP++;
	cv::Sobel(dst[OP - 1], dst[OP], CV_16S, 0, 1);
	cv::convertScaleAbs(dst[OP], dst[OP]);


	cv::addWeighted(dst[OP - 1], 0.5, dst[OP], 0.5, 0, dst[OP]);

	imshow("Image", dst[OP]);

}
private: System::Void Horizontal_Sobel_Click(System::Object^ sender, System::EventArgs^ e) {
	// Apply Sobel filter horizontally

	cv::Sobel(dst[OP - 1], dst[OP], CV_16S, 1, 0);
	cv::convertScaleAbs(dst[OP], dst[OP]);
	imshow("Image", dst[OP]);

	
};
private: System::Void Vertical_Sobel_Click(System::Object^ sender, System::EventArgs^ e) {

	// Apply Sobel filter Vertically
	OP++;
	cv::Sobel(dst[OP - 1], dst[OP], CV_16S, 0, 1);
	cv::convertScaleAbs(dst[OP], dst[OP]);
	imshow("Image", dst[OP]);
};
private: System::Void textBox10_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}

