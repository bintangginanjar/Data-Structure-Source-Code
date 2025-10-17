#include <iostream>
#include "stack.h"

using namespace std;

void createStack(Stack &S) {
    S.Top = -1;
}

bool isEmpty(Stack S) {
    if (S.Top == -1) {
        return true;
    } else {
        return false;
    }
}

bool isFull(Stack S) {
    if (S.Top == IDXMAX - 1) {
        return true;
    } else {
        return false;
    }
}

void push(Stack &S, infotype X) {
    if (isFull(S)) {
        cout << "Stack is full, cannot add more element" << endl;
    } else {
        S.Top = S.Top + 1;
        S.info[S.Top] = X;
    }
}

void pop(Stack &S, infotype &X) {
    if (isEmpty(S)) {
        cout << "Stack is empty, nothing to pop" << endl;
    } else {
        X = S.info[S.Top];
        S.Top = S.Top - 1;
    }
}

infotype peek(Stack S) {
    return S.info[S.Top];
}

void printStack(Stack &S) {
    infotype temp;

    while (!isEmpty(S)) {
        pop(S, temp);
        cout << temp << endl;
    }
}

void reverseStack(Stack &S) {
    Stack tempStack;
    infotype temp;

    if (isEmpty(S)) {
        cout << "Stack is empty, nothing to pop" << endl;
    } else {
        createStack(tempStack);

        while (!isEmpty(S)) {
            pop(S, temp);
            push(tempStack, temp);
        }

        S = tempStack;
    }
}

void popth(Stack &S, int index, infotype &P) {
    infotype temp;
    Stack tempStack;

    createStack(tempStack);

    if (isEmpty(S)) {
        cout << "Stack is empty" << endl;
    } else {
        while (S.Top != index) {
            pop(S, temp);
            push(tempStack, temp);
        }

        pop(S, P);        
        cout << "Elemen that popped out is " << P << endl;

        while (!isEmpty(tempStack)) {
            pop(tempStack, temp);
            push(S, temp);
        }
    }
}

bool isPalindrom(Stack S) {
    Stack tempStack;
    Stack reversedStack;
    infotype val;
    bool palindrome = true;
    infotype valOri, valRev;

    createStack(tempStack);
    createStack(reversedStack);

    while (!isEmpty(S)) {
        pop(S, val);
        push(tempStack, val);
        push(reversedStack, val);
    }

    while (!isEmpty(tempStack)) {
        pop(tempStack, val);
        push(S, val);
    }

    while (!isEmpty(S) && !isEmpty(reversedStack) && palindrome) {        
        pop(S, valOri);
        pop(reversedStack, valRev);
        
        if (valOri != valRev) {
            palindrome = false;
        }
    }

    return palindrome;
}

void pushSorted(Stack &S) {
    
}