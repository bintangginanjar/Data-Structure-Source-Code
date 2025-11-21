#include <iostream>
#include "tree.cpp"

using namespace std;

int main() {
    BinTree root;

    CreateTree(root);

    cout << EmptyTree(root) << endl;

    return 0;
}