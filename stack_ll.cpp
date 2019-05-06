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


/*

Declaring a structure called node
having two members:

  1) data block
  2) next block (which stores the address of the next node)

 */

struct node {
  int data;
  node *next;
};


/*

Declaring a class called Stack having:

  one private member:
        top

  three public member functions:
        push
        pop
        display

The top is set to NULL initially

*/

class Stack {
  node *top;

public:
  Stack(): top(NULL) {}
  void push(int );
  void pop();
  void display();
};


/*

ALGORITHM FOR PUSHING AN ELEMENT IN THE STACK:

  1) IF AVAIL = NULL
        WRITE Overflow
        EXIT

  2) NEW_NODE = AVAIL
  3) AVAIL = AVAIL -> NEXT
  4) NEW_NODE -> DATA = VALUE
  5) IF TOP = NULL
        NEW_NODE -> NEXT = NULL
        TOP = NEW_NODE

  6) ELSE
        NEW_NODE -> NEXT = TOP
        TOP = NEW_NODE

  7) EXIT

*/

void Stack :: push(int value) {
  node *new_node = new node;
  new_node->data = value;

  if(top == NULL) {
    new_node->next = NULL;
    top = new_node;
  }
  else {
    new_node->next = top;
    top = new_node;
  }
}


/*

ALGORITHM TO POP A NODE FROM STACK:

  1) IF TOP = NULL
        WRITE Underflow
        EXIT

  2) PTR = TOP;
  3) TOP = TOP -> NEXT
  4) DELETE PTR
  5) EXIT

*/

void Stack :: pop() {
  // Checking if the stack is empty
  if(top == NULL) {
    cout<<"The Stack is empty !\n";
  }
  else {
    node *ptr = top;
    top = top->next;

    cout<<"The popped node is: "<<ptr->data<<endl;

    delete ptr;
  }
}


/*

ALGORITHM TO DISPLAY THE STACK:

  1) IF TOP = NULL
        WRITE Underflow
        EXIT

  2) PTR = TOP
  3) WHILE PTR != NULL
        PTR = PTR -> NEXT

  4) EXIT

*/

void Stack :: display() {
  if(top == NULL) {
    cout<<"The Stack is empty !\n";
  }
  else {
    node *ptr = top;

    while(ptr != NULL) {
      cout<<ptr->data<<" ";
      ptr = ptr->next;
    }
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
      case 1: cout<<"Enter the value to be inserted: ";
              cin>>value;

              s.push(value);
              break;

      case 2: s.pop();
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
