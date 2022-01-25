#pragma once
#include <iostream>
#include <string>
#include "MyForm2.h"
#include "vertex.h"
#include "adjList.h"
#include <msclr\marshal_cppstd.h>
#include <SDL.h>
int x = 0;
string minN;
string maxN;
int deg = 0;
int specNode;
string allN;

namespace projectcs221 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(int n, string min, string max, adjList& l)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			x = n;
			minN = min;
			maxN = max;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ dis_graph;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox9;





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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dis_graph = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(55, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(448, 34);
			this->label1->TabIndex = 0;
			this->label1->Text = L"CS221-Data Structures Project";
			// 
			// dis_graph
			// 
			this->dis_graph->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dis_graph->ForeColor = System::Drawing::Color::Black;
			this->dis_graph->Location = System::Drawing::Point(1132, 32);
			this->dis_graph->Name = L"dis_graph";
			this->dis_graph->Size = System::Drawing::Size(172, 62);
			this->dis_graph->TabIndex = 1;
			this->dis_graph->Text = L"Display Graph";
			this->dis_graph->UseVisualStyleBackColor = true;
			this->dis_graph->Click += gcnew System::EventHandler(this, &MyForm::dis_graph_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(209, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(282, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Total Number Of Nodes: ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(594, 115);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(107, 22);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"XXXX";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(757, 112);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 28);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Click Here";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(37, 497);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(217, 64);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Made By:\r\nKhizar Ali Shah (2020196)\r\nMuhammad Ashhar Shah (2020478)\r\nHarris Abdul"
				L"lah (2020159)\r\n";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(757, 165);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(98, 28);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Click Here";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(594, 168);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(107, 22);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"XXXX";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(209, 169);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(270, 29);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Node With Min Degree: ";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(757, 217);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(98, 28);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Click Here";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(594, 220);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(107, 22);
			this->textBox3->TabIndex = 10;
			this->textBox3->Text = L"XXXX";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(209, 221);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(275, 29);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Node With Max Degree: ";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(757, 264);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(98, 28);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Click Here";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(594, 267);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(107, 22);
			this->textBox4->TabIndex = 13;
			this->textBox4->Text = L"XXXX";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(209, 268);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(259, 29);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Show Degree of Node:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(420, 487);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(218, 29);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Show Neighbours: ";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(644, 494);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(107, 22);
			this->textBox5->TabIndex = 16;
			this->textBox5->Text = L"XXXX";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(777, 491);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(98, 28);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Click Here";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(922, 491);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(411, 252);
			this->textBox6->TabIndex = 18;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::Black;
			this->button6->Location = System::Drawing::Point(1132, 142);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(172, 62);
			this->button6->TabIndex = 19;
			this->button6->Text = L"Display Adj List";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(878, 276);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(151, 16);
			this->label8->TabIndex = 20;
			this->label8->Text = L"(0 means does not exist)";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(209, 314);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(340, 29);
			this->label10->TabIndex = 21;
			this->label10->Text = L"Enter Source Vertex For MST: ";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(593, 318);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(107, 22);
			this->textBox7->TabIndex = 22;
			this->textBox7->Text = L"XXXX";
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox7_TextChanged);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(757, 315);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(98, 28);
			this->button7->TabIndex = 23;
			this->button7->Text = L"Show MST";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(757, 367);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(98, 67);
			this->button8->TabIndex = 26;
			this->button8->Text = L"Show Path";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(593, 370);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(107, 22);
			this->textBox8->TabIndex = 25;
			this->textBox8->Text = L"Source";
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox8_TextChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(209, 366);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(268, 29);
			this->label9->TabIndex = 24;
			this->label9->Text = L"Calculate Shortest Path:";
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click_1);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(593, 412);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(107, 22);
			this->textBox9->TabIndex = 27;
			this->textBox9->Text = L"Destination";
			this->textBox9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox9_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSeaGreen;
			this->ClientSize = System::Drawing::Size(1345, 755);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dis_graph);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"CS221 Project";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dis_graph_Click(System::Object^ sender, System::EventArgs^ e) {
		adjList::showGraph();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = System::Convert::ToString(x);
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox2->Text = gcnew String(minN.c_str());
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	
	textBox3->Text = gcnew String(maxN.c_str());
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ managed = textBox4->Text;
	std::string unmanaged = msclr::interop::marshal_as<std::string>(managed);

		specNode = adjList::getDegreeOfVertex(unmanaged);

		textBox4->Text = System::Convert::ToString(specNode);

}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ managed2 = textBox5->Text;
	std::string unmanaged2 = msclr::interop::marshal_as<std::string>(managed2);
	allN = adjList::showAllNeighbors(unmanaged2);

	textBox6->Text = gcnew String(allN.c_str());
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ managed2 = textBox7->Text;
	std::string unmanaged2 = msclr::interop::marshal_as<std::string>(managed2);
	adjList::createMST(unmanaged2);
}
private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ m2 = textBox8->Text;
	std::string m2x = msclr::interop::marshal_as<std::string>(m2);
	System::String^ m1 = textBox9->Text;
	std::string m1x = msclr::interop::marshal_as<std::string>(m1);
	adjList::dijkstra(m2x, m1x);
}
private: System::Void textBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
