#include <iostream>
#include "queue.cpp"

using namespace std;

int main() {
    int numOfElm = 10;
    
    address P, R;
    queue Q, QGanjil, QGenap;
    createQueue(Q);
    createQueue(QGanjil);
    createQueue(QGenap);

    for (int i = 0; i < numOfElm; i++) {
        address elm = Nil;
        elm = alokasi(i+2);
        enQueue(Q, elm);
    }

    printInfo(Q);
    cout << endl;

    ganjilGenap(Q, QGanjil, QGenap);
    cout << "Queue Utama";
    printInfo(Q);

    cout << endl;
    cout << "Queue Ganjil";
    printInfo(QGanjil);

    cout << endl;
    cout << "Queue Genap";
    printInfo(QGenap);
}