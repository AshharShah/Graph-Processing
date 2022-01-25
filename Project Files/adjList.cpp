#include <queue>
#include <fstream>
#include <iostream>
//#include <SDL2/SDL.h>
#include <SDL.h>
#include <math.h>
#include "adjList.h"
#include "vertex.h"
#define PI 3.14159
#define WIDTH 1420
#define HEIGHT 800
#define CENTER_X0 WIDTH/2
#define CENTER_Y0 HEIGHT/2
using namespace std;

//clang++ -std=c++17 main.cpp adjList.cpp vertex.cpp -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2 -o prog
//clang++ -std=c++17 main.cpp adjList.cpp vertex.cpp -F/Library/Frameworks -framework SDL2 -o prog

int adjList::totalVertices = 0;
vertex* adjList::tempHead = nullptr;
double vertex::theta = 0;
double radius = 250;
double incrementInRadians = 0.008 * 4;
double VERTICES_PER_CIRCLE = (2 * PI) / incrementInRadians;
double incrementRadius = -50;
vertex* adjList::head = nullptr;

void adjList::dijkstra(string source, string destination)
{
    vertex* temp = head;
    vertex* sV, * dV;
    bool aDone, bDone;
    aDone = bDone = false;
    while (temp != nullptr)
    {
        if (temp->name == source)
        {
            sV = temp;
            aDone = true;
        }
        else if (temp->name == destination)
        {
            bDone = true;
            dV = temp;
        }

        if (aDone && bDone) break;

        temp = temp->next;
    }

    adjList::setKeyValues();
    sV->keyValue = 0;

    priority_queue <vertex*, vector<vertex*>, myComparator> pq;
    vertex* v = head;
    while (v != nullptr)
    {
        pq.push(v);
        v->inMinHeap = true;
        v = v->next;
    }

    vertex* u;

    while (!pq.empty())
    {
        u = pq.top();
        pq.pop();
        u->inMinHeap = false;
        neighbor* nb = u->edge;
        while (nb)
        {
            if (nb->origin->inMinHeap)
            {
                if (nb->origin->keyValue > u->keyValue + nb->weight)
                {
                    nb->origin->keyValue = u->keyValue + nb->weight;
                    nb->origin->parent = u;
                }
            }
            nb = nb->edge;
        }
    }

    adjList::showShortestPath(dV);
}

void adjList::showShortestPath(vertex* dV)
{
    SDL_Window* window = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized: " <<
            SDL_GetError();
    }
    else
    {
        std::cout << "SDL video system is ready to go\n";
    }

    window = SDL_CreateWindow("C++ SDL2 Window", 20, 20, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Rect rectangle;
    rectangle.w = 4;
    rectangle.h = 4;

    bool gameIsRunning = true;

    while (gameIsRunning)
    {
        SDL_Event event;

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
        cout << "Path: ";

        while (dV != nullptr)
        {
            rectangle.x = dV->x;
            rectangle.y = dV->y;
            cout << dV->name << " ";
            SDL_RenderDrawRect(renderer, &rectangle);
            //neighbor* nb = dV->edge;
            // while (nb)
            // {
            //     SDL_RenderDrawLine(renderer, temp->x, temp->y, nb->origin->x, nb->origin->y);
            //     nb = nb->edge;
            // }
            if (dV->parent != nullptr)
            {
                SDL_RenderDrawLine(renderer, dV->x, dV->y, dV->parent->x, dV->parent->y);
            }
            dV = dV->parent;
        }

        SDL_RenderPresent(renderer);

        bool close = false;

        while (!close)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT) {
                    gameIsRunning = false;
                    close = true;
                }
            }
        }
    }
}

void adjList::showMST(vertex* last)
{
    SDL_Window* window = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized: " <<
            SDL_GetError();
    }
    else {
        std::cout << "SDL video system is ready to go\n";
    }

    window = SDL_CreateWindow("C++ SDL2 Window", 20, 20, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Rect rectangle;
    rectangle.w = 4;
    rectangle.h = 4;

    bool gameIsRunning = true;

    while (gameIsRunning)
    {
        SDL_Event event;

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);

        //vertex* last = head;
        last = head;
        while (last != nullptr)
        {
            rectangle.x = last->x;
            rectangle.y = last->y;
            SDL_RenderDrawRect(renderer, &rectangle);
            if (last->parent != nullptr)
            {
                SDL_RenderDrawLine(renderer, last->x, last->y, last->parent->x, last->parent->y);
            }

            //last = last->next;
            last = last->next;
        }

        SDL_RenderPresent(renderer);

        bool close = false;

        while (!close)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT) {
                    gameIsRunning = false;
                    close = true;
                }
            }
        }
    }
}

void adjList::showGraph()
{
    vertex* temp = tempHead;

    SDL_Window* window = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized: " <<
            SDL_GetError();
    }
    else
    {
        std::cout << "SDL video system is ready to go\n";
    }

    window = SDL_CreateWindow("C++ SDL2 Window", 20, 20, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Rect rectangle;
    rectangle.w = 4;
    rectangle.h = 4;

    bool gameIsRunning = true;

    while (gameIsRunning)
    {
        SDL_Event event;

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);

        temp = tempHead;

        while (temp != nullptr)
        {
            rectangle.x = temp->x;
            rectangle.y = temp->y;
            SDL_RenderDrawRect(renderer, &rectangle);
            neighbor* nb = temp->edge;
            while (nb)
            {
                SDL_RenderDrawLine(renderer, temp->x, temp->y, nb->origin->x, nb->origin->y);
                nb = nb->edge;
            }
            temp = temp->next;
        }

        SDL_RenderPresent(renderer);

        bool close = false;

        while (!close)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT) {
                    gameIsRunning = false;
                    close = true;
                }
            }
        }
    }
}

adjList::adjList()
{
    count = 0;
    fstream f("PPI-I.txt", ios::in);
    string a, b;
    double w;
    vertex* aV, * bV;
    while (!f.eof() && !f.fail())
    {
        f >> a >> b >> w;
        aV = insertVertex(a);
        bV = insertVertex(b);
        insertEdge(aV, bV, w);
    }
}

vertex* adjList::insertVertex(string n)
{
    if (head == nullptr)
    {
        head = new vertex(n);
        head->x = CENTER_X0 + radius * cos(vertex::theta);
        head->y = CENTER_Y0 + radius * sin(vertex::theta);
        vertex::theta = incrementInRadians;
        ++totalVertices;
        tempHead = head;
        return head;
    }

    if (head->name == n) return head;

    vertex* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;

        if (temp->name == n) return temp;
    }

    temp->next = new vertex(n);
    temp->next->x = CENTER_X0 + radius * cos(vertex::theta);
    temp->next->y = CENTER_Y0 + radius * sin(vertex::theta);
    vertex::theta += incrementInRadians;
    ++totalVertices;

    if (vertex::theta >= 2 * PI - incrementInRadians)
    {
        radius += incrementRadius;
        vertex::theta = 0;
    }

    return temp->next;
}

void adjList::insertEdge(vertex* aV, vertex* bV, double w)
{
    if (aV == bV) return; // not considering loops

    aV->insertVertex(bV, w);
    bV->insertVertex(aV, w);
}

void adjList::printList()
{
    vertex* temp = head;
    while (temp != nullptr)
    {
        cout << temp->x << " " << temp->y << endl;
        temp->printInner();
        temp = temp->next;
    }
}

string adjList::showAllNeighbors(string n)
{
    string nb;
    vertex* temp = tempHead;

    while (temp != nullptr)
    {
        if (temp->name == n) break;
        temp = temp->next;

    }

    if (temp == nullptr)
    {
        nb = "This vertex does not exist in the graph";
        return nb;
    }

    neighbor* t = temp->edge;
    while (t != nullptr)
    {
        nb = t->origin->name + "   " + nb;
        t = t->edge;
    }

    return nb;
}

int adjList::getDegreeOfVertex(string n)
{
    vertex* temp = adjList::tempHead;

    while (temp != nullptr)
    {
        if (temp->name == n)
        {
            return temp->degree;
        }
        temp = temp->next;
    }

    return 0;
}

void adjList::createMST(string source)
{
    vertex* temp = head;

    while (temp != nullptr)
    {
        if (temp->name == source) break;

        temp = temp->next;
    }

    if (temp == nullptr)
    {
        //invalid vertex entered. Output to form textBox
        return;
    }

    adjList::setKeyValues();
    temp->keyValue = 0;

    priority_queue <vertex*, vector<vertex*>, myComparator> pq;
    vertex* v = head;
    while (v != nullptr)
    {
        pq.push(v);
        v->inMinHeap = true;
        v = v->next;
    }

    vertex* u;
    vertex* last;

    while (!pq.empty())
    {
        u = pq.top();
        u->inMinHeap = false;
        pq.pop();
        neighbor* nb = u->edge;
        while (nb != nullptr)
        {
            if (nb->origin->inMinHeap)
            {
                if (nb->origin->keyValue > nb->weight)
                {
                    nb->origin->keyValue = nb->weight;
                    nb->origin->parent = u;
                }
                last = nb->origin;
            }
            nb = nb->edge;
        }
    }

    adjList::showMST(last);
}

void adjList::setKeyValues()
{
    vertex* temp = head;
    while (temp != nullptr)
    {
        temp->keyValue = 800000; // approximation to infinity
        temp = temp->next;
    }
}