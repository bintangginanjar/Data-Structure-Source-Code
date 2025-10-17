#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define Nil NULL

const int IDXMAX = 4;

using namespace std;

typedef bool boolean;
typedef int infotype;
typedef int index;

struct Stack {
    infotype info[IDXMAX];
    index Top;
};

void createStack(Stack &S);

bool isEmpty(Stack S);

bool isFull(Stack S);

void push(Stack &S, infotype X);

void pop(Stack &S, infotype &X);

infotype peek(Stack S);

void printStack(Stack &S);

void reverseStack(Stack &S);

void popth(Stack &S, int index, infotype &P);

bool isPalindrom(Stack S);

void pushSorted(Stack &S);

#endif // STACK_H_INCLUDED