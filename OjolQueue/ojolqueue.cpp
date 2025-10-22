#include <iostream>
#include "ojolqueue.h"

using namespace std;

address alokasi(infotype info) {
    address P = new elmQ;
    P->info.nama = info.nama;
    P->info.rating = info.rating;
    P->info.order = info.order;
    P->next = Nil;
    P->prev = Nil;

    return P;
}

address findElmtByRating(queue Q, infotype ojol) {
    address P;
    boolean found;

    P = Q.head;
    found == false;

    while (P != Nil && found == false) {
        if (P->info.rating <= ojol.rating) {
            found = true;            
        } else {
            P = P->next;
        }        
    }

    return P;
}

bool isEmpty(queue Q) {
    if (Q.head == Nil && Q.tail == Nil) {
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q) {
    address P;
    int count;

    P = Q.head;
    count = 0;

    while (P != Nil) {
        count++;
        P = P->next;
    }

    if (count == IDXMax) {
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

void dealokasi(address P) {
    delete P;
}

void enQueue(queue &Q, address P) {
    if (isFull(Q)) {
        cout << "Queue penuh" << endl;
    } else if (isEmpty(Q)) {
            Q.head = P;
            Q.tail = P;            
    } else {
        next(Q.tail) = P;
        P->prev = Q.tail;
        Q.tail = P;
    }
}

void deQueue(queue &Q, address &P) {
    if (isEmpty(Q)) {
        cout << "Queue kosong" << endl;
    } else if (Q.head == Q.tail) {
        P = Q.head;
        Q.head = Nil;      
        Q.tail = Nil;
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = Q.head;
        Q.head = P->next;
        Q.head->prev = Nil;
        P->next = Nil;
        P->prev = Nil;
    }
}

void printInfo(queue Q) {
    address P;
    P = Q.head;
    
    if (P == Nil) {
        cout << "Queue kosong" << endl;
    } else {
        while (P != Nil) {
            cout << P->info.nama << endl;
            cout << P->info.rating << endl;            
            cout << P->info.order << endl;
            P = P->next;
        }
    }
}

int nbOfElm(queue Q) {
    int numOfElmt = 0;

    address P;
    P = Q.head;
    
    while (P != Nil) {
        numOfElmt++;
        P = P->next;
    }

    return numOfElmt;
}

void roundRobin(queue Q, int T, int N) {
    address P, R;

    P = Q.head;

    while ((!isEmpty(Q)) && (T > 0)) {
        if (P->info.order < N) {
            P->info.order = P->info.order + 1;
            deQueue(Q, R);
            enQueue(Q, R);
        } else {
            deQueue(Q, R);
        }

        T = T-60;
        P = Q.head;
    }

    if (isEmpty(Q)) {
        cout << "Queue kosong" << endl;
    } else {
        cout << "Waktu habis" << endl;
    }
}