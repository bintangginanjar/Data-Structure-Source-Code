#ifndef MHSLIST_H_INCLUDED
#define MHSLIST_H_INCLUDED

#define Nil NULL

using namespace std;

struct mahasiswa{
    string nama;
    string nim;
};

typedef bool boolean;
typedef mahasiswa infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct list {
    address first;
};

address alokasi(infotype info);

address searchElmtByNama(list L, infotype info);

address searchElmtByNim(list L, infotype info);

bool listEmpty(list L);

void createList(list &L);

void dealokasi(address P);

void insertFirst(list &L, address P);

void insertAfter(list &L, address P, address Prev);

void insertLast(list &L, address P);

void delFirst(list &L, address P);

void delLast(list &L, address P);

void delAfter(list &L, address P, address Prev);

void printInfo(list L);

int nbList(list L);

#endif // MHSLIST