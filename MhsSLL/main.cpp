#include <iostream>
#include "mhslist.cpp"

using namespace std;

int main() {
    address P1, P2, P3, P4, P5, P6, P7, P8, Prev, Temp = Nil;
    infotype mhs1, mhs2, mhs3, mhs4, mhs5, mhs6, mhs7, mhs8;
    list L;
    createList(L);

    mhs1.nama = "GABRIELLA AURALIA NAINGGOLAN";
    mhs1.nim = "1301224489";

    P1 = alokasi(mhs1);
    insertFirst(L,P1);

    mhs2.nama = "DEVIN PRAWIRA ARISSAPUTRA";
    mhs2.nim = "1301224478";

    P2 = alokasi(mhs2);
    insertFirst(L,P2);

    mhs3.nama = "MUHAMMAD FAKHRI WIRASASMITA";
    mhs3.nim = "1301224477";

    P3 = alokasi(mhs3);
    insertFirst(L,P3);

    mhs4.nama = "MUHAMMAD NIBRAS RASYID";
    mhs4.nim = "1301224469";

    P4 = alokasi(mhs4);
    insertFirst(L,P4);

    mhs5.nama = "ARI RAMADHAN";
    mhs5.nim = "1301224458";

    P5 = alokasi(mhs5);
    insertFirst(L,P5);

    mhs6.nama = "RULY BIJA";
    mhs6.nim = "1301224196";

    P6 = alokasi(mhs6);
    insertLast(L,P6);

    mhs7.nama = "MAHESA KIMI PUTRANTO";
    mhs7.nim = "1301224451";

    P7 = alokasi(mhs7);
    insertLast(L,P7);

    cout << endl;
    printInfo(L);

    Prev = searchElmtByNim(L,mhs1);
    if (Prev != Nil) {
        mhs8.nama = "FAYYAZA SAJIDA NUR AZIZA";
        mhs8.nim = "1301224092";
        P8 = alokasi(mhs8);
        insertAfter(L,P8,Prev);
    }

    cout << endl;
    printInfo(L);

    return 0;
}