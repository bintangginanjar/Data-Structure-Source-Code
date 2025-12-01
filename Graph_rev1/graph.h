#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define Nil NULL
#define info(P) (P)->info
#define visited(P) (P)->visited
#define inDegree(P) (P)->inDegree
#define outDegree(P) (P)->outDegree
#define node(P) (P)->node
#define next(P) (P)->next
#define src(P) (P)->src
#define dst(P) (P)->dst
#define first(L) ((L).first)

using namespace std;

typedef char infoGraph;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;

struct elmNode {
    infoGraph info;
    bool visited;
    int inDegree;
    int outDegree;
    adrNode next;
};

struct elmEdge {
    adrNode src;
    adrNode dst;
    adrEdge next;
};

struct listNode {
    adrNode first;
};

struct listEdge {
    adrEdge first;
};

adrNode AllocateNode (infoGraph X);

void DeallocateNode (adrNode P);

adrEdge AllocateEdge (adrNode src, adrNode dst);

void CreateListNode (listNode &G);

void CreateListEdge (listEdge &E);

void InsertNode (listNode &G, infoGraph X);

void InsertEdge (listNode &G, listEdge &E, infoGraph src, infoGraph dst);

adrNode FindNode (listNode G, infoGraph X);

void CountDegree (listNode G);

void PrintNeighbor (listNode G, listEdge E, infoGraph X);

void PrintTopologicalSort (listNode G);

void PrintBFS (listNode G, infoGraph X);

void PrintInfoGraph (listEdge E);

#endif // GRAPH_H_INCLUDED