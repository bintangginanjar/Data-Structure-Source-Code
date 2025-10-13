#include <iostream>
#include "dll.cpp"

using namespace std;

int main() {
    //int nilai;
    address P1, P2, P3, P4, P5, P6, P7, P8, Prev, Temp, idxMin, idxMax = Nil;
    list L;
    createList(L);
    cout << "List created" << endl;

    P1 = alokasi(2);
    insertFirst(L,P1);
    cout << "Number " << P1->info << " inserted as first element" << endl;

    P2 = alokasi(0);
    insertFirst(L,P2);
    cout << "Number " << P2->info << " inserted as first element" << endl;

    P3 = alokasi(12);
    insertFirst(L,P3);
    cout << "Number " << P3->info << " inserted as first element" << endl;

    P4 = alokasi(5);
    insertFirst(L,P4);
    cout << "Number " << P4->info << " inserted as first element" << endl;

    P5 = alokasi(13);
    insertFirst(L,P5);
    cout << "Number " << P5->info << " inserted as first element" << endl;

    P6 = alokasi(7);
    insertLast(L,P6);
    cout << "Number " << P6->info << " inserted as last element" << endl;

    P7 = alokasi(16);
    insertLast(L,P7);
    cout << "Number " << P7->info << " inserted as last element" << endl;

    Prev = searchElmt(L,5);
    if (Prev != Nil) {
        P8 = alokasi(20);
        insertAfter(L,P8,Prev);
        cout << "Number " << P8->info << " inserted as after " << Prev->info << endl;
    }

    cout << endl;
    cout << "Print DLL in forward style" << endl;
    printInfoForward(L);
    cout << endl;

    idxMin = searchMin(L);
    idxMax = searchMax(L);

    cout << "Minimum value" << endl;
    cout << idxMin->info << endl;
    cout << "Maximum value" << endl;
    cout << idxMax->info << endl;

    //maximumSort(L);
    minimumSort(L);    
    cout << endl;
    cout << "Print value after sorted" << endl;
    printInfoForward(L);
    cout << endl;

    return 0;
}