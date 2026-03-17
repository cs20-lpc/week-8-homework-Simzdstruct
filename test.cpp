#include <iostream>
#include "StackFactory.hpp"

int main()
{
    Stack<int> * mystack = StackFactory<int>::GetStack();
    mystack->push(1);
    mystack->push(2);
    mystack->push(3);
    mystack->push(4);
    mystack->push(5);
    mystack->pop();
    mystack->pop();
    mystack->pop();
    mystack->push(6);
    mystack->push(7);
    cout << mystack->getLength();

    Stack<int> * shouldCreateArraystack = StackFactory<int>::GetStack(5);
    shouldCreateArraystack->push(1);
    shouldCreateArraystack->push(2);
    shouldCreateArraystack->push(3);
    shouldCreateArraystack->push(4);
    shouldCreateArraystack->push(5);
    shouldCreateArraystack->pop();
    shouldCreateArraystack->pop();
    shouldCreateArraystack->pop();
    shouldCreateArraystack->push(6);
    shouldCreateArraystack->push(7);
    cout << " " << shouldCreateArraystack->getLength();


    //Testing rotate
    cout << endl << "Testing rotate:" << endl;
    Stack<int> * rotateStack = StackFactory<int>::GetStack();
    rotateStack->push(1);
    rotateStack->push(2);
    rotateStack->push(3);
    rotateStack->push(4);
    rotateStack->push(5);
    cout << "Original stack: ";
    rotateStack->print(); 
    cout << "expected output 5 4 3 2 1" << endl;
    rotateStack->rotate(Stack<int>::RIGHT);
    rotateStack->print(); 
    cout << "expected output: 4 3 2 1 5" << endl;
    rotateStack->rotate(Stack<int>::LEFT);
    rotateStack->print(); 
    cout << "expected output: 5 1 2 3 4" << endl;
   
    //testing rotate edge cases
    //startign with an empty stack
    Stack<int> * emptyStack = StackFactory<int>::GetStack();
    emptyStack->rotate(Stack<int>::RIGHT);
    emptyStack->print(); // Expected output: Stack is empty, no elements to display.
    cout << "expected output: Stack is empty, no elements to display." << endl;
    //starting with a stack of size 1
    Stack<int> * singleElementStack = StackFactory<int>::GetStack();
    singleElementStack->push(43);
    singleElementStack->rotate(Stack<int>::RIGHT);
    singleElementStack->print(); // Expected output: 42
    cout << "expected output: 43" << endl;

    delete mystack;
    delete shouldCreateArraystack;
    delete rotateStack;
    delete emptyStack;
    delete singleElementStack;

}