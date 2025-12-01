#include <iostream>
#include "graph.h"

using namespace std;

adrNode AllocateNode (infoGraph X) {
    adrNode P = new elmNode;
    info(P) = X;
    next(P) = Nil;
    inDegree(P) = 0;
    outDegree(P) = 0;

    return P;
}

void DeallocateNode (adrNode P) {
    delete P;
}

adrEdge AllocateEdge (adrNode src, adrNode dst) {
    adrEdge P = new elmEdge;
    src(P) = src;
    dst(P) = dst;
    next(P) = Nil;

    return P;
}

adrNode FindNode (listNode G, infoGraph X) {
    adrNode Q;

    Q = first(G);

    while ((next(Q) != Nil) && (info(Q) != X)) {
        Q = next(Q);
    }

    return Q;
}

void CreateListNode (listNode &G) {
    first(G) = Nil;
}

void CreateListEdge (listEdge &E) {
    first(E) = Nil;
}

void InsertNode (listNode &G, infoGraph X) {
    adrNode P, Q;

    P = AllocateNode(X);

    if (first(G) == Nil) {
        first(G) = P;
    } else {
        Q = first(G);

        while (next(Q) != Nil) {
            Q = next(Q);
        }

        next(Q) = P;
    }
}

void InsertEdge (listNode &G, listEdge &E, infoGraph src, infoGraph dst) {
    adrNode srcNode, dstNode;
    adrEdge P, Q;

    srcNode = FindNode(G, src);
    dstNode = FindNode(G, dst);

    if ((srcNode != Nil) && (dstNode != Nil)) {
        outDegree(srcNode) = outDegree(srcNode) + 1;
        inDegree(dstNode) = inDegree(dstNode) + 1;
        
        P = AllocateEdge(srcNode, dstNode);

        if (first(E) == Nil) {
            first(E) = P;
        } else {
            Q = first(E);

            while (next(Q) != Nil) {
                Q = next(Q);
            }

            next(Q) = P;
        }
    } else {
        cout << "Node sumber atau tujuan tidak ditemukan" << endl;
    }
}

void PrintNeighbor (listNode G, listEdge E, infoGraph X) {
    adrEdge P;
    adrNode srcNode, dstNode;

    P = first(E);

    srcNode = FindNode(G, X);
    cout << "Node yang bertetangga dengan " << info(srcNode) << " adalah" << endl;
    
    while (next(P) != Nil) {
        if (src(P) == srcNode) {
            dstNode = dst(P);
            cout << "Node " << info(dstNode) << endl;
        }

        P = next(P);
    }
    
}

void PrintTopologicalSort (listNode G) {
    
}

void PrintInfoGraph (listEdge E) {
    adrEdge P;
    adrNode srcNode, dstNode;

    P = first(E);

    while (next(P) != Nil) {
        srcNode = src(P);
        dstNode = dst(P);

        cout << "Node " << info(srcNode) << " terhubung dengan node " << info(dstNode) << endl;

        P = next(P);
    }
}

void PrintBFS (listNode G, infoGraph X) {
    
}