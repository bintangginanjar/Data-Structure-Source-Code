#include <iostream>
#include "list.cpp"

using namespace std;

int main() {
    //int nilai;
    address P1, P2, P3, P4, Prev, Temp, idxMin, idxMax = Nil;
    list L;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L,P2);

    P3 = alokasi(12);
    insertFirst(L,P3);

    Prev = searchElmt(L,0);
    if (Prev != Nil) {
        P4 = alokasi(20);
        insertAfter(L,P4,Prev);
    }

    cout << endl;
    printInfo(L);
    cout << endl;

    /*
    idxMin = searchMin(L);
    idxMax = searchMax(L);

    cout << info(idxMin) << endl;
    cout << info(idxMax) << endl;
    */

    //maximumSort(L);
    /*
    minimumSort(L);    
    cout << endl;
    printInfo(L);
    cout << endl;
    */
    /*
    cout << endl;
    printEven(L);

    cout << endl;
    printOdd(L);
    */

    /*
    cout << endl;
    cout << nbList(L) << endl;

    delFirst(L, Temp);

    cout << endl;
    printInfo(L);

    delLast(L, Temp);

    cout << endl;
    printInfo(L);
    //cout << info(P8) << endl;

    Prev = searchElmt(L,5);
    if (Prev != Nil) {
        Temp = alokasi(20);
        delAfter(L,Temp,Prev);
    }

    cout << endl;
    printInfo(L);
    */

    return 0;
}