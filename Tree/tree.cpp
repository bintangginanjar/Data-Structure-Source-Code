#include <iostream>
#include "tree.h"

using namespace std;

address AlokasiNode(infotype X) {
    address P = new Node;
    info(P) = X;
    left(P) = Nil;
    right(P) = Nil;

    return P;
}

bool EmptyTree(BinTree T) {
    if (T == Nil) {
        return true;
    } else {
        return false;
    }
}

void CreateTree(BinTree &T) {
    T = Nil;
}

void InsertNode(BinTree &T, infotype X) {
    address node;

    if (EmptyTree(T)) {
        node = AlokasiNode(X);
        T = node;
    } else {
        
    }
}