#include <iostream>
#include "graph.h"

using namespace std;

adrQueue AllocateQueue(infoGraph X) {
    adrQueue P = new elmQ;
    info(P) = X;
    next(P) = Nil;

    return P;
}

void DeallocateQueue(adrQueue P) {
    delete P;
}

bool IsQueueEmpty(queue Q) {
    if (head(Q) == Nil) {
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q) {
    head(Q) = Nil;
    tail(Q) = Nil;
}

void Enqueue(queue &Q, adrQueue P) {
    if (IsQueueEmpty(Q)) { /* kondisi kosong */
        head(Q) = P;
        tail(Q) = P;
    } else { /* kondisi tidak kosong */
        next(tail(Q)) = P;
        tail(Q) = P;
    }
}

adrQueue Dequeue(queue &Q) {
    adrQueue P;

    if (IsQueueEmpty(Q)) { /* kondisi kosong */
        return Nil;
    } else if (head(Q) == tail(Q)) { /* kondisi satu elemen */
        P = head(Q);
        head(Q) = Nil;        
        tail(Q) = Nil;
        next(P) = Nil;

        return P;   
    } else { /* kondisi banyak elemen */
        P = head(Q);
        head(Q) = next(P);
        next(P) = Nil;

        return P;
    }
}

void PrintQueue(queue Q) {
    adrQueue ptrQueue;

    ptrQueue = head(Q);

    while (ptrQueue != Nil) {
        cout << info(ptrQueue) << endl;

        ptrQueue = next(ptrQueue);
    }
}

adrNode AllocateNode (infoGraph X) {
    adrNode P = new elmNode;
    info(P) = X;
    next(P) = Nil;
    inDegree(P) = 0;
    outDegree(P) = 0;
    visited(P) = false;

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

queue FindNeighborNode(listNode G, listEdge E, infoGraph X) {
    queue Q;
    adrEdge P;
    adrNode srcNode, dstNode;

    P = first(E);

    srcNode = FindNode(G, X);
    CreateQueue(Q);
    //cout << "Node yang bertetangga dengan " << info(srcNode) << " adalah" << endl;
    
    while (next(P) != Nil) {
        if (src(P) == srcNode) {
            dstNode = dst(P);
            //cout << "Node " << info(dstNode) << endl;            
            Enqueue(Q, AllocateQueue(info(dstNode)));            
        }

        P = next(P);
    }

    return Q;
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

void PrintBFS (listNode &G, listEdge E, infoGraph X) {
    cout << "Mulai BFS" << endl;

    adrNode ptrNode, ptrNodeX, ptrNodeW;
    queue mainQ, neighQ;
    adrQueue xQ, wQ;

    CreateQueue(mainQ);
    CreateQueue(neighQ);
    ptrNode = FindNode(G, X);

    Enqueue(mainQ, AllocateQueue(X));

    while (!IsQueueEmpty(mainQ)) {
        xQ = Dequeue(mainQ);
        ptrNodeX = FindNode(G, info(xQ));

        if (!visited(ptrNodeX)) {
            visited(ptrNodeX) = true;

            cout << "Visit " << info(ptrNodeX) << endl;            
            neighQ = FindNeighborNode(G, E, info(ptrNodeX));
            
            //PrintQueue(neighQ);

            while (!IsQueueEmpty(neighQ)) {
                wQ = head(neighQ);

                ptrNodeW = FindNode(G, info(wQ));
                //cout << info(wQ) << endl;

                if (!visited(ptrNodeW)) {                    
                    wQ = Dequeue(neighQ);
                    Enqueue(mainQ, wQ);
                    //visited(ptrNodeW) = true;
                } else {
                    wQ = Dequeue(neighQ);
                    DeallocateQueue(wQ);
                }

                wQ = head(neighQ);
            }
        }
    }
}