#include <iostream>
#include "list.h"

using namespace std;

address alokasi(infotype info) {
    address p = new elmlist;
    p->info = info;
    p->next = Nil;

    return p;
}

bool listEmpty(list L) {
    if (L.first == Nil) {
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
        L.first = P;
    } else {
        P->next = Prev->next;
        Prev->next = P;
    }
}

void insertLast(list &L, address P) {
    address Q;

    if (listEmpty(L)) {
        L.first = P;
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
        dealokasi(P);
    } else {
        L.first = L.first->next;
        P->next = Nil;
        dealokasi(P);
    }    
}

void delLast(list &L, address P) {
    address Q;    

    if (listEmpty(L)) {
        cout << "List kosong" << endl;
    } else if ((L.first->next) == Nil) {        
        L.first = L.first->next;
        P->next = Nil;
        dealokasi(P);
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
    } else if ((L.first->next) == Nil) {
        L.first = L.first->next;
        P->next = Nil;
        dealokasi(P);
    } else {
        P = Prev->next;
        Prev->next = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

void printInfo(list L) {
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