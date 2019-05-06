// Copyright 2019 Souvik Biswas
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <iostream>
using namespace std;

// Defining the maximum size of the stack to be 10
#define MAX 10

// Defining a class to store the member variables
// and member functions required
class Stack {
  int stk[MAX], top;

public:
  Stack(): top(-1) {}
  void push(int );
  int pop();
  void display();
};


/*

ALGORITHM FOR PUSHING AN ELEMENT IN THE STACK:

  1) IF TOP = MAX-1
        WRITE Overflow
        EXIT

  2) TOP = TOP + 1
  3) STACK[TOP] = VALUE
  4) EXIT

*/

void Stack :: push(int value) {
  // When the size of stack has reached maximum,
  // we cannot insert any element
  if(top == MAX-1) {
    cout<<"The Stack is full !\n";
  }
  else {
    // Incrementing top
    top++;

    // Store the value in the stack at top position
    stk[top] = value;
  }
}


/*

ALGORITHM FOR POPPING AN ELEMENT FROM THE STACK:

  1) IF TOP = -1
        WRITE Underflow
        RETURN -1
        EXIT

  2) VALUE = STK[TOP]
  3) TOP = TOP - 1
  4) RETURN VALUE
  5) EXIT

*/

int Stack :: pop() {
  // When the size of stack is -1, the stack is empty
  if(top == -1) {
    cout<<"The Stack is empty !\n";
    return -1;
  }
  else {
    // Store the top value
    int value = stk[top];

    // Decrement top
    top --;

    return value;
  }
}


// Display the elements of the Stack by decrementing starting from top
void Stack :: display() {
  // When the size of stack is -1, the stack is empty
  if(top == -1) {
    cout<<"The Stack is empty !\n";
  }
  else {
    // Decrementing stack starting from top position
    for(int i=top; i>=0; i--) {
      // Printing each stack element
      cout<<stk[i]<<" ";
    } cout<<endl;
  }
}


// Main Function
int main() {
  int option, value;
  Stack s;

  do {
    cout<<"\n**** MENU ****\n"
        <<"1. Push\n"
        <<"2. Pop\n"
        <<"3. Display\n"
        <<"4. Exit\n";

    cout<<"Enter your option: ";
    cin>>option;

    switch(option) {
      case 1: cout<<"Enter the value to be pushed: ";
              cin>>value;

              s.push(value);
              break;

      case 2: value = s.pop();
              if(value != -1) {
                cout<<"The popped element is: "<<value<<endl;
              }
              break;

      case 3: s.display();
              break;

      case 4: break;

      default: cout<<"Wrong option !\n";
               break;
    }
  } while(option != 4);

  if(option == 4) {
    cout<< "\nTHANK YOU for using the program !\n"
        <<"Have a good day.\n\n";
  }
}
