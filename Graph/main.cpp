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
    InsertEdge(G, E, 'A', 'C');
    InsertEdge(G, E, 'B', 'D');
    InsertEdge(G, E, 'B', 'E');
    InsertEdge(G, E, 'C', 'F');
    InsertEdge(G, E, 'C', 'G');
    InsertEdge(G, E, 'D', 'H');
    InsertEdge(G, E, 'E', 'H');
    InsertEdge(G, E, 'F', 'H');
    InsertEdge(G, E, 'G', 'H');

    PrintNeighbor(G, E, 'B');

    return 0;
}