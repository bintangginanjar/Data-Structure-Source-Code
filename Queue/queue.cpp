#include <iostream>
#include "queue.h"

using namespace std;

address alokasi(infotype info) {
    address P = new elmQ;
    P->info = info;
    P->next = Nil;

    return P;
}

address findElmt(queue Q, infotype num) {
    address P;
    boolean found;

    P = Q.head;
    found == false;

    while (P != Nil && found == false) {
        if (P->info == num) {
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

void createQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

void dealokasi(address P) {
    delete P;
}

void enQueue(queue &Q, address P) {    
    if (isEmpty(Q)) { /* kondisi kosong */
        Q.head = P;
        Q.tail = P;
    } else { /* kondisi tidak kosong */
        Q.tail->next = P;
        Q.tail = P;
    }
}

void deQueue(queue &Q, address &P) {    
    if (isEmpty(Q)) { /* kondisi kosong */
        cout << "Queue kosong" << endl;
    } else if (Q.head == Q.tail) { /* kondisi satu elemen */
        P = Q.head;
        Q.head = Nil;        
        Q.tail = Nil;
        P->next = Nil;        
    } else { /* kondisi banyak elemen */
        P = Q.head;
        Q.head = P->next;
        P->next = Nil;
    }
}

void printInfo(queue Q) {
    address P;
    int i = 1;

    P = Q.head;
    
    if (P == Nil) { /* kondisi kosong */
        cout << "Queue kosong" << endl;
    } else {
        while (P != Nil) {
            cout << "Antrian ke-" << i << " : " << P->info << endl;
            P = P->next;
            i++;
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

void ganjilGenap(queue &Q, queue &QGanjil, queue &QGenap) {
    address P, R;

    P = Q.head;

    while (!isEmpty(Q)) {                
        if (P->info % 2 == 1) {
            deQueue(Q, R);
            enQueue(QGanjil, R);
        } else {
            deQueue(Q, R);
            enQueue(QGenap, R);
        }

        P = Q.head;
    }
}