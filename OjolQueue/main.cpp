#include <iostream>
#include "ojolqueue.cpp"

using namespace std;

int main() {
    address P;
    queue Q;
    createQueue(Q);
    int T, N;

    infotype ojol1, ojol2, ojol3, ojol4;
    address elm1, elm2, elm3, elm4;

    ojol1.nama = "Letty";
    ojol1.rating = 4.65;
    ojol1.order = 8;

    ojol2.nama = "Bella";
    ojol2.rating = 4.2;
    ojol2.order = 6;

    ojol3.nama = "Alex";
    ojol3.rating = 4.6;
    ojol3.order = 5;    

    elm1 = alokasi(ojol1);
    enQueue(Q, elm1);

    elm2 = alokasi(ojol2);
    enQueue(Q, elm2);

    elm3 = alokasi(ojol3);
    enQueue(Q, elm3);

    ojol4.nama = "John";
    ojol4.rating = 4.3;
    ojol4.order = 7;

    elm4 = alokasi(ojol4);
    enQueue(Q, elm4);

    cout << "Input waktu : ";
    cin >> T;
    cout << "Input maksimum order : ";
    cin >> N;
    roundRobin(Q, T, N);

    return 0;
}