#pragma once
#include <iostream>
#include "vertex.h"
using namespace std;

class adjList
{
private:
    static vertex* head;
    static int totalVertices;
    static vertex* tempHead;

public:
    int count;
    adjList();
    void printList();
    vertex* insertVertex(string);
    vertex* getHead() { return head; }
    void insertEdge(vertex*, vertex*, double);
    void setEdge(const int&, const int&, const int&);
    static void showGraph();
    static void setKeyValues();
    static void showMST(vertex*);
    static void createMST(string);
    static int getDegreeOfVertex(string);
    static string showAllNeighbors(string);
    static int getTotalVertices() { return totalVertices; }
    static void dijkstra(string, string);
    static void showShortestPath(vertex*);
};