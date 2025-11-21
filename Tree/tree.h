#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#define Nil NULL
#define info(P) (P)->info
#define right(P) (P)->right
#define left(P) (P)->left

using namespace std;

typedef bool boolean;
typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

typedef address BinTree;

address AlokasiNode(infotype X);

bool EmptyTree(BinTree T);

void CreateTree(BinTree &T);

void InsertNode(BinTree &T, infotype X);

#endif // TREE_H_INCLUDED