#include <iostream>
#include "dll.h"

using namespace std;

address alokasi(infotype info) {
    address P = new elmlist;
    P->info = info;
    P->next = Nil;
    P->prev = Nil;

    return P;
}

bool listEmpty(list L) {
    if (L.first == Nil && L.last == Nil) {
        return true;
    } else {
        return false;
    }
}

address searchElmt(list L, infotype num) {
    address Q;
    boolean found;

    Q = L.first;
    found == false;

    while (Q != Nil && found == false) {
        if (Q->info == num) {
            found = true;
        } else {
            Q = Q->next;
        }        
    }

    return Q;
}

void createList(list &L) {
    L.first = Nil;
    L.last = Nil;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(list &L, address P) {
    if (listEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfter(list &L, address P, address Prec) {    
    if (listEmpty(L)) {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    } else {
        P->next = Prec->next;
        P->prev = Prec;
        P->next->prev = P;
        Prec->next = P;
    }
}

void insertLast(list &L, address P) {
    if (listEmpty(L)) {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void delFirst(list &L, address P) {
    P = L.first;

    if (listEmpty(L)) {
        cout << "List kosong" << endl;
    } else if (P->next == Nil) {
        L.first = Nil;
        L.last = Nil;
        dealokasi(P);
    } else {
        P = L.first;
        L.first = P->next;
        P->next = Nil;
        L.first->prev = Nil;
        dealokasi(P);
    }    
}

void delLast(list &L, address P) {
    if (listEmpty(L)) {
        cout << "List kosong" << endl;
    } else if (P->next == Nil) {
        L.first = Nil;
        L.last = Nil;
        dealokasi(P);
    } else {
        P = L.last;
        L.last = prev(L.last);
        P->prev = Nil;
        L.last->next = Nil;
        dealokasi(P);
    }    
}

void delAfter(list &L, address P, address Prec) {
    if (listEmpty(L)) {
        cout << "List kosong" << endl;
    } else if (next(L.first) == Nil) {
        L.first = Nil;
        L.last = Nil;
        dealokasi(P);
    } else {
        P = Prec->next;
        Prec->next = P->next;
        P->next->prev = Prec;
        P->next = Nil;
        P->prev = Nil;
    }
}

void printInfoForward(list L) {
    address Q;
    Q = L.first;
    
    if (Q == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (Q != Nil) {
            cout << Q->info << endl;
            Q = Q->next;
        }
    }
}
    
void printInfoBackward(list L) {
    address Q;
    Q = L.last;
    
    if (Q == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (Q != Nil) {
            cout << Q->info << endl;
            Q = prev(Q);
        }
    }
}

void printEven(list L) {
    address Q;
    Q = L.first;

    if (Q == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (Q != Nil) {
            if (Q->info % 2 == 0) {
                cout << Q->info << endl;                
            }
            Q = Q->next;       
        }
    }
}

void printOdd(list L) {
    address Q;
    Q = L.first;

    if (Q == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (Q != Nil) {
            if (Q->info % 2 != 0) {
                cout << Q->info << endl;                
            }
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

address searchMin(list L) {
    address P, min;

    min = L.first;
    P = L.first;

    while (P != Nil) {
        if (P->info < min->info) {
            min = P;
        }
        P = P->next;
    }

    return min;
}

address searchMax(list L) {
    address P, max;

    max = L.first;
    P = L.first;

    while (P != Nil) {
        if (P->info > max->info) {
            max = P;
        }
        P = P->next;
    }

    return max;
}

void maximumSort(list L) {
    address P, Q, idx;
    infotype temp;

    P = L.first;    

    while (P != Nil) {
        idx = P;
        Q = P->next;

        while (Q != Nil) {
            if (Q->info > idx->info) {
                idx = Q;
            }
            Q = Q->next;
        }

        temp = P->info;
        P->info = idx->info;
        idx->info = temp;

        P = P->next;
    }
}

void minimumSort(list L) {
    address P, Q, idx;
    infotype temp;

    P = L.first;

    while (P != Nil) {
        idx = P;
        Q = P->next;

        while (Q != Nil) {
            if (Q->info < idx->info) {
                idx = Q;
            }
            Q = Q->next;
        }

        temp = P->info;
        P->info = idx->info;
        idx->info = temp;

        P = P->next;
    }
}