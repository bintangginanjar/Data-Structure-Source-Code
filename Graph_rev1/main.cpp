#include <iostream>
#include "graph.cpp"

using namespace std;

int main() {
    adrNode node;
    listNode G;
    listEdge E;

    CreateListNode(G);
    CreateListEdge(E);
        
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    InsertEdge(G, E, 'A', 'B');
    InsertEdge(G, E, 'B', 'C');
    InsertEdge(G, E, 'B', 'E');
    InsertEdge(G, E, 'B', 'D');
    InsertEdge(G, E, 'C', 'E');
    InsertEdge(G, E, 'D', 'E');
    InsertEdge(G, E, 'G', 'D');
    InsertEdge(G, E, 'E', 'F');

    PrintNeighbor(G, E, 'B');
    PrintInfoGraph(E);

    return 0;
}