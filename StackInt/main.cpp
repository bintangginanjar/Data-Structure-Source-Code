#include <iostream>
#include "stack.cpp"

using namespace std;

int main() {
    infotype P = 2;
    infotype Q = 1;
    infotype K = 10;
    infotype L = 5;
    infotype M = 4;
    infotype N = 6;

    Stack S;

    createStack(S);
    cout << "Stack created" << endl;

    if (isEmpty(S)) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is full" << endl;
    }

    if (isFull(S)) {
        cout << "Stack is full" << endl;
    } else {
        cout << "Stack is empty" << endl;
    }

    //push(S, P);
    pushSorted(S, P);
    cout << "Top element is " << peek(S) << endl;

    //push(S, Q);
    pushSorted(S, Q);
    cout << "Top element is " << peek(S) << endl;

    /*
    pop(S, R);
    cout << "Top element is " << peek(S) << endl;
    */

    //push(S, K);
    pushSorted(S, K);
    cout << "Top element is " << peek(S) << endl;

    //push(S, L);
    pushSorted(S, L);
    cout << "Top element is " << peek(S) << endl;

    //push(S, M);
    pushSorted(S, M);
    cout << "Top element is " << peek(S) << endl;

    //push(S, N);
    pushSorted(S, N);
    cout << "Top element is " << peek(S) << endl;

    if (isFull(S)) {
        cout << "Stack is full" << endl;
    } else {
        cout << "Stack is empty" << endl;
    }
 
    //reverseStack(S);

    //popth(S, 2, R);    

    printStack(S);

    //printStack(S);
}