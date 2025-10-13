#include <iostream>
#include "mhslist.h"

using namespace std;

address alokasi(infotype mhs) {
    address p = new elmlist;

    (p->info).nama = mhs.nama;
    (p->info).nim = mhs.nim;
    p->next = Nil;

    return p;
}

address searchElmtByNama(list L, infotype mhs) {
    address Q;
    boolean found;

    Q = L.first;
    found == false;

    while (Q != Nil && found == false) {
        if ((Q->info).nama == mhs.nama) {
            found = true;            
        } else {
            Q = Q->next;
        }        
    }

    return Q;
}

address searchElmtByNim(list L, infotype mhs) {
    address Q;
    boolean found;

    Q = L.first;
    found == false;

    while (Q != Nil && found == false) {
        if ((Q->info).nim == mhs.nim) {
            found = true;            
        } else {
            Q = Q->next;
        }        
    }

    return Q;
}

bool listEmpty(list L) {
    if (L.first == Nil) {
        return true;
    } else {
        return false;
    }
}

void createList(list &L) {
    L.first = Nil;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(list &L, address P) {
    if (listEmpty(L)) {        
        L.first = P;
    } else {
       P->next = L.first;
       L.first = P;
    }
}

void insertAfter(list &L, address P, address Prev) {    
    if (listEmpty(L)) {
        insertFirst(L, P);
    } else {
        P->next = Prev->next;
        Prev->next = P;
    }
}

void insertLast(list &L, address P) {
    address Q;

    if (listEmpty(L)) {
        insertFirst(L, P);
    } else {
        Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void delFirst(list &L, address P) {
    P = L.first;

    if (listEmpty(L)) {
        cout << "List kosong" << endl;
    } else if (P->next == Nil) {
        L.first = Nil;        
    } else {
        L.first = (L.first)->next;
        P->next = Nil;
        dealokasi(P);
    }
}

void delLast(list &L, address P) {
    address Q;
   
    if (listEmpty(L)) {
        cout << "List kosong" << endl;
    } else if (((L.first)->next) == Nil) {
        delFirst(L, P);
    } else {
        P = L.first;

        while (P->next != Nil) {                        
            Q = P;        
            P = P->next;            
        }
        Q->next = Nil;
        dealokasi(P);
    }
}

void delAfter(list &L, address P, address Prev) {
    if (listEmpty(L)) {
        cout << "List kosong" << endl;
    } else if (((L.first)->next) == Nil) {
        delFirst(L, P);
    } else {
        P = Prev->next;
        Prev->next = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

void printInfo(list L) {
    int numOfElmt = 0;
    address Q;   

    Q = L.first;
    
    if (Q == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (Q != Nil) {
            cout << numOfElmt++ + 1 << endl;
            cout << (Q->info).nama << endl;
            cout << (Q->info).nim << endl;
            cout << endl;
            Q = Q->next;
        }
    }
}

int nbList(list L) {
    int numOfElmt = 0;
    address Q;

    Q = L.first;
    
    while (Q != Nil) {
        numOfElmt++;
        Q = Q->next;
    }

    return numOfElmt;
}