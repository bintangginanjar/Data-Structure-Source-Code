#include <string>
#ifndef OJOLQUEUE_H_INCLUDED
#define OJOLQUEUE_H_INCLUDED

#define Nil NULL
/*
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define head(Q) ((Q).head)
#define tail(Q) ((Q).tail)
*/

using namespace std;

const int IDXMax = 3;

struct ojol {
    string nama;
    float rating;
    int order;
};

typedef bool boolean;
typedef ojol infotype;
typedef struct elmQ *address;

struct elmQ {
    infotype info;
    address next;
    address prev;
};

struct queue {
    address head, tail;
};

address alokasi(infotype info);

address findElmtByRating(queue Q, infotype num);

bool isEmpty(queue Q);

bool isFull(queue Q);

void createQueue(queue &Q);

void enQueue(queue &Q, address P);

void deQueue(queue &Q, address &P);

void printInfo(queue Q);

void roundRobin(queue Q, int T, int N);

int nbOfElm(queue Q);

#endif // OJOLQUEUE_H_INCLUDED