#include <iostream>
#include "stack.cpp"

using namespace std;

int main() {
    infotype P = 'U';
    infotype Q = 'V';
    infotype R;
    infotype K = 'L';
    infotype L = 'E';
    infotype M = 'T';
    infotype N = 'V';

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

    push(S, P);
    cout << "Top element is " << peek(S) << endl;

    push(S, Q);
    cout << "Top element is " << peek(S) << endl;

    pop(S, R);
    cout << "Top element is " << peek(S) << endl;

    push(S, K);
    cout << "Top element is " << peek(S) << endl;

    push(S, L);
    cout << "Top element is " << peek(S) << endl;

    push(S, M);
    cout << "Top element is " << peek(S) << endl;

    push(S, N);
    cout << "Top element is " << peek(S) << endl;

    if (isFull(S)) {
        cout << "Stack is full" << endl;
    } else {
        cout << "Stack is empty" << endl;
    }
 
    reverseStack(S);

    //popth(S, 2, R);    

    printStack(S);

    //printStack(S);
}