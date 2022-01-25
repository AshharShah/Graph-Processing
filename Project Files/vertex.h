#pragma once
#include <iostream>
using namespace std;

struct neighbor;

struct vertex
{
    string name;
    neighbor* edge;
    vertex* next;
    bool drawn;
    double x, y;
    int neighborCount;
    int degree;
    int keyValue; // or distance
    vertex* parent;
    bool inMinHeap;

    static double theta;
    static int minDegree, maxDegree;
    static string maxDegreeVertex;
    static string minDegreeVertex;

    vertex(string n) { degree = 0; name = n; edge = nullptr; next = nullptr; drawn = false; neighborCount = 0; parent = nullptr; }
    string getName() { return name; }
    void insertVertex(vertex* n, double w);
    void printInner();
    static int getMinDegree() { return minDegree; }
    static int getMaxDegree() { return maxDegree; }
    static string getMaxDegreeVertex() { return maxDegreeVertex; }
    static string getMinDegreeVertex() { return minDegreeVertex; }
};

struct neighbor
{
    vertex* origin;
    neighbor* edge;
    double weight;

    neighbor(vertex* p, double w) : origin(p), weight(w) {}
};

class myComparator
{
public:
    int operator() (const vertex* v1, const vertex* v2)
    {
        return v1->keyValue > v2->keyValue;
    }
};