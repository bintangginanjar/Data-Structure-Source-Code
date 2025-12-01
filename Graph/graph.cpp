#include <iostream>
#include "graph.h"

using namespace std;

int IsStackEmpty(stack S) {
    if (S.Top == 0) {
        return true;
    } else {
        return false;
    }
}

void CreateStack(stack &S) {
    S.Top = 0;
}

void Push(stack &S, infoGraph X) {
    S.Top = S.Top + 1;
    S.T[S.Top] = X;
}

infoGraph Pop(stack &S) {
    infoGraph X;

    X = S.T[S.Top];
    S.Top = S.Top - 1;

    return X;
}

adrQueue AllocateQueue(infoGraph X) {
    adrQueue P = new elmQ;
    P->info = X;
    P->next = Nil;

    return P;
}

void DeallocateQueue(adrQueue P) {
    delete P;
}

bool IsQueueEmpty(queue Q) {
    if (Q.head == Nil) {
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

void Enqueue(queue &Q, adrQueue P) {
    if (IsQueueEmpty(Q)) { /* kondisi kosong */
        Q.head = P;
        Q.tail = P;
    } else { /* kondisi tidak kosong */
        Q.tail->next = P;
        Q.tail = P;
    }
}

adrQueue Dequeue(queue &Q) {
    adrQueue P;

    if (IsQueueEmpty(Q)) { /* kondisi kosong */
        return Nil;
    } else if (Q.head == Q.tail) { /* kondisi satu elemen */
        P = Q.head;
        Q.head = Nil;        
        Q.tail = Nil;
        P->next = Nil;

        return P;   
    } else { /* kondisi banyak elemen */
        P = Q.head;
        Q.head = P->next;
        P->next = Nil;

        return P;
    }
}

void PrintQueue(queue Q) {
    adrQueue ptrQueue;

    ptrQueue = Q.head;

    while (ptrQueue != Nil) {
        cout << ptrQueue->info << endl;

        ptrQueue = ptrQueue->next;
    }
}

adrNode AllocateNode (infoGraph X) {
    adrNode P = new elmNode;
    P->info = X;
    P->next = Nil;
    P->inDegree = 0;
    P->outDegree = 0;
    P->visited = false;

    return P;
}

void DeallocateNode (adrNode P) {
    delete P;
}

adrEdge AllocateEdge (adrNode src, adrNode dst) {
    adrEdge P = new elmEdge;
    P->src = src;
    P->dst = dst;
    P->next = Nil;

    return P;
}

adrNode FindNode (listNode G, infoGraph X) {
    adrNode Q;

    Q = G.first;

    while ((Q->next != Nil) && (Q->info != X)) {
        Q = Q->next;
    }

    return Q;
}

void CreateListNode (listNode &G) {
    G.first = Nil;
}

void CreateListEdge (listEdge &E) {
    E.first = Nil;
}

void InsertNode (listNode &G, infoGraph X) {
    adrNode P, Q;

    P = AllocateNode(X);

    if (G.first == Nil) {
        G.first = P;
    } else {
        Q = G.first;

        while (Q->next != Nil) {
            Q = Q->next;
        }

        Q->next = P;
    }
}

void InsertEdge (listNode &G, listEdge &E, infoGraph src, infoGraph dst) {
    adrNode srcNode, dstNode;
    adrEdge P, Q;

    srcNode = FindNode(G, src);
    dstNode = FindNode(G, dst);

    if ((srcNode != Nil) && (dstNode != Nil)) {
        srcNode->outDegree = srcNode->outDegree + 1;
        dstNode->inDegree = dstNode->inDegree + 1;
        
        P = AllocateEdge(srcNode, dstNode);

        if (E.first == Nil) {
            E.first = P;
        } else {
            Q = E.first;

            while (Q->next != Nil) {
                Q = Q->next;
            }

            Q->next = P;
        }
    } else {
        cout << "Node sumber atau tujuan tidak ditemukan" << endl;
    }
}

queue FindNeighborNode(listNode G, listEdge E, infoGraph X) {
    queue Q;
    adrEdge P;
    adrNode srcNode, dstNode;

    P = E.first;

    srcNode = FindNode(G, X);
    CreateQueue(Q);
    //cout << "Node yang bertetangga dengan " << srcNode->info << " adalah" << endl;
    
    while (P != Nil) {
        if (P->src == srcNode) {
            dstNode = P->dst;
            //cout << "Node " << dstNode->info << endl;            
            Enqueue(Q, AllocateQueue(dstNode->info));            
        }

        P = P->next;
    }

    return Q;
}

void PrintNeighbor (listNode G, listEdge E, infoGraph X) {
    adrEdge P;
    adrNode srcNode, dstNode;

    P = E.first;

    srcNode = FindNode(G, X);
    cout << "Node yang bertetangga dengan " << srcNode->info << " adalah" << endl;
    
    while (P->next != Nil) {
        if (P->src == srcNode) {
            dstNode = P->dst;
            cout << "Node " << dstNode->info << endl;
        }

        P = P->next;
    }
    
}

void PrintInfoGraph (listEdge E) {
    adrEdge P;
    adrNode srcNode, dstNode;

    P = E.first;

    while (P->next != Nil) {
        srcNode = P->src;
        dstNode = P->dst;

        cout << "Node " << srcNode->info << " terhubung dengan node " << dstNode->info << endl;

        P = P->next;
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
        ptrNodeX = FindNode(G, xQ->info);

        if (!ptrNodeX->visited) {
            ptrNodeX->visited = true;

            cout << "Visit " << ptrNodeX->info << endl;            
            neighQ = FindNeighborNode(G, E, ptrNodeX->info);
            
            //PrintQueue(neighQ);

            while (!IsQueueEmpty(neighQ)) {
                wQ = neighQ.head;

                ptrNodeW = FindNode(G, wQ->info);
                //cout << wQ->info << endl;

                if (!ptrNodeW->visited) {                    
                    wQ = Dequeue(neighQ);
                    Enqueue(mainQ, wQ);
                    //ptrNodeW->visited = true;
                } else {
                    wQ = Dequeue(neighQ);
                    DeallocateQueue(wQ);
                }

                wQ = neighQ.head;
            }
        }
    }
}

void PrintDFS (listNode &G, listEdge E, infoGraph X) {
    cout << "Mulai DFS" << endl;
    stack mainS, neighS;
    infoGraph xQ;
    adrQueue wQ;
    queue neighQ;

    adrNode ptrNode, ptrNodeX, ptrNodeW;

    CreateStack(mainS);
    CreateStack(neighS);

    Push(mainS, X);

    while (!IsStackEmpty(mainS)) {
        xQ = Pop(mainS);
        ptrNodeX = FindNode(G, xQ);

        if (!ptrNodeX->visited) {
            ptrNodeX->visited = true;

            cout << "Visit " << ptrNodeX->info << endl;            
            neighQ = FindNeighborNode(G, E, ptrNodeX->info);

            while (!IsQueueEmpty(neighQ)) {
                wQ = neighQ.head;

                ptrNodeW = FindNode(G, wQ->info);

                if (!ptrNodeW->visited) {                    
                    wQ = Dequeue(neighQ);
                    Push(mainS, wQ->info);
                    //Enqueue(mainQ, wQ);
                    //ptrNodeW->visited = true;
                } else {
                    wQ = Dequeue(neighQ);
                    DeallocateQueue(wQ);
                }

                wQ = neighQ.head;
            }
        }
    }
}

void ResetVisit(listNode &G) {
    adrNode ptrNode;

    ptrNode = G.first;

    while (ptrNode != Nil) {
        ptrNode->visited = false;

        ptrNode = ptrNode->next;
    }
}