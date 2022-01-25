#pragma once
#include "MyForm2.h"
#include "vertex.h"
#include "adjList.h"
#include <iostream>
#include <SDL.h>
#undef main

using namespace std;

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(int argc, char* args[]) {

	adjList l;
	int totalNodes = adjList::getTotalVertices();
	int minDegree = vertex::getMinDegree();
	int maxDegree = vertex::getMaxDegree();
	string minNode = vertex::getMinDegreeVertex();
	string maxNode = vertex::getMaxDegreeVertex();

	l.printList();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	projectcs221::MyForm form(totalNodes, minNode, maxNode, l);
	Application::Run(% form);
	
	system("PAUSE");
}