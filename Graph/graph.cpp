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

/*
adrNode FindBeforeNode (listNode G, infoGraph X) {
    adrNode P, Q;

    P = first(G);

    while (next(P) != Nil) {
        Q = P;
        P = next(P);

        if (info(P) == X) {
            return Q;
        }
    }
}
*/

/*
adrEdge FindEdge (listEdge E, infoGraph src, infoGraph dst) {

}
*/

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

/*
void DeleteNode (listNode &G, infoGraph X) {
    adrNode P, Q, Prev;

    if (first(G) == Nil) { // graph kosong
        cout << "List kosong" << endl;
    } else if (FindNode(G, X) != Nil) {
            if (P = first(G)) { // posisi node di awal list
                if (next(P) == Nil) { // satu elemen
                    first(G) = Nil;
                    DeallocateNode(P);
                } else {
                    first(G) = next(first(G));
                    next(P) = Nil;
                    DeallocateNode(P);
                }
            } else if (next(P) == Nil) { // posisi node di akhir list                
                Q = first(G);

                while (next(Q) != P) {                        
                    Q = next(Q);
                }

                next(Q) = Nil;
                DeallocateNode(P);                
            } else { // posisi node di tengah
                Prev = FindBeforeNode(G, X);

                P = next(Prev);
                next(Prev) = next(P);
                next(P) = Nil;
                DeallocateNode(P);
            }
    } else {
        cout << "Node tidak ditemukan" << endl;
    }
}
*/

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

/*
void DeleteEdge (listEdge &E, infoGraph src, infoGraph dst) {

}
*/

void CountDegree (listNode G) {
    adrNode P;
    adrEdge Q;

    P = first(G);

    while (next(P) != Nil) {
        Q = first(E);

        while (next(Q) != Nil) {

        }
    }
}

void PrintNeighbor (listNode G, listEdge E, infoGraph X) {
    adrEdge P;
    adrNode srcNode, dstNode;

    P = first(E);

    srcNode = FindNode(G, X);
    cout << info(srcNode) << endl;
    
    while (next(P) != Nil) {
        if (src(P) == srcNode) {
            dstNode = dst(P);
            cout << info(dstNode) << endl;
        }

        P = next(P);
    }
    
}

void PrintTopologicalSort (listNode G) {
    
}