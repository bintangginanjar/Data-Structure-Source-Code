#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

#define Nil NULL
/*
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)
*/

using namespace std;

typedef bool boolean;
typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct list {
    address first;
    address last;
};

address alokasi(infotype info);

address searchElmt(infotype info);

bool listEmpty(list L);

void createList(list &L);

void dealokasi(address P);

void insertFirst(list &L, address P);

void insertAfter(list &L, address P, address Prev);

void insertLast(list &L, address P);

void delFirst(list &L, address P);

void delLast(list &L, address P);

void delAfter(list &L, address P, address Prec);

void printInfoForward(list L);

void printInfoBackward(list L);

void printEven(list L);

void printOdd(list L);

int nbList(list L);

address searchMin(list L);

address searchMax(list L);

void maximumSort(list L);

void minimumSort(list L);

#endif // DLL_H_INCLUDED