#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define Nil NULL

using namespace std;

typedef char infoGraph;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;
typedef struct elmQ *adrQueue;

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

struct elmQ {
    infoGraph info;
    adrQueue next;
};

struct listNode {
    adrNode first;
};

struct listEdge {
    adrEdge first;
};

struct queue {
    adrQueue head, tail;
};

struct stack {
    infoGraph T[10];
    int Top;
};

int IsStackEmpty(stack S);

void CreateStack(stack &S);

void Push(stack &S, infoGraph X);

infoGraph Pop(stack &S);

adrQueue AllocateQueue(infoGraph X);

void DeallocateQueue(adrQueue P);

bool IsQueueEmpty(queue Q);

void CreateQueue(queue &Q);

void Enqueue(queue &Q, adrQueue P);

void Dequeue(queue &Q, adrQueue &P);

void PrintQueue(queue Q);

adrNode AllocateNode (infoGraph X);

void DeallocateNode (adrNode P);

adrEdge AllocateEdge (adrNode src, adrNode dst);

void CreateListNode (listNode &G);

void CreateListEdge (listEdge &E);

void InsertNode (listNode &G, infoGraph X);

void InsertEdge (listNode &G, listEdge &E, infoGraph src, infoGraph dst);

adrNode FindNode (listNode G, infoGraph X);

queue FindNeighborNode(listNode G, listEdge E, infoGraph X);

void PrintNeighbor (listNode G, listEdge E, infoGraph X);

void PrintBFS (listNode &G, listEdge E, infoGraph X);

void PrintDFS (listNode &G, listEdge E, infoGraph X);

void PrintInfoGraph (listEdge E);

void ResetVisit(listNode &G);

#endif // GRAPH_H_INCLUDED