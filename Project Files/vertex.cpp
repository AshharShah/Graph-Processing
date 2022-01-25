#include "vertex.h"

int vertex::minDegree = 1;
int vertex::maxDegree = 0;
string vertex::minDegreeVertex = " x ";
string vertex::maxDegreeVertex = " y ";

void vertex::printInner()
{
    neighbor* t = edge;
    while (t != nullptr)
    {
        cout << "( " << name << " " << t->weight << " " << t->origin->name << " )" << endl;
        t = t->edge;
    }
}

void vertex::insertVertex(vertex* n, double w)
{
    ++neighborCount;
    neighbor* newN = new neighbor(n, w);
    newN->edge = edge;
    edge = newN;
    ++degree;
    if (degree <= minDegree)
    {
        minDegree = degree;
        minDegreeVertex = name;
    }
    else if (degree > maxDegree)
    {
        maxDegree = degree;
        maxDegreeVertex = name;
    }
}