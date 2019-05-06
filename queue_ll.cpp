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

Declaring a class called Queue having:

  two private member:
        front
        rear

  three public member functions:
        insert
        delete
        display

The top is set to NULL initially

*/

class Queue {
  node *front, *rear;

public:
  Queue(): front(NULL), rear(NULL) {}
  void insert(int );
  void del();
  void display();
};


/*

ALGORITHM FOR INSERTING AN ELEMENT IN THE QUEUE:

  1) IF AVAIL = NULL
        WRITE Overflow
        EXIT

  2) NEW_NODE = AVAIL
  3) AVAIL = AVAIL -> NEXT
  4) NEW_NODE -> DATA = VALUE
  5) NEW_NODE -> NEXT = NULL
  6) IF REAR = NULL
        REAR = NEW_NODE
        FRONT = NEW_NODE

  6) ELSE
        REAR -> NEXT = NEW_NODE
        REAR = NEW_NODE

  7) EXIT

*/

void Queue :: insert(int value) {
  node *new_node = new node;
  new_node->data = value;
  new_node->next = NULL;

  if(rear == NULL) {
    rear = new_node;
    front = new_node;
  }
  else {
    rear->next = new_node;
    rear = new_node;
  }
}


/*

ALGORITHM TO DELETE A NODE FROM QUEUE:

  1) IF FRONT = NULL
        WRITE Underflow
        EXIT

  2) PTR = FRONT;
  3) FRONT = FRONT -> NEXT
  4) DELETE PTR
  5) EXIT

*/

void Queue :: del() {
  // Checking if the stack is empty
  if(front == NULL) {
    cout<<"The Queue is empty !\n";
  }
  else {
    // Storing the front node in ptr
    node *ptr = front;

    // Incrementing front
    front = front->next;

    // Printing the element to be deleted
    cout<<"The deleted node is: "<<ptr->data<<endl;

    // Delete the node
    delete ptr;
  }
  // Solving the edge case #1:
  // When the front becomes null, we have to set rear to null also
  if(front == NULL) {
    rear = NULL;
  }
}


/*

ALGORITHM TO DISPLAY THE QUEUE:

  1) IF FRONT = NULL
        WRITE Underflow
        EXIT

  2) PTR = FRONT
  3) WHILE PTR != NULL
        PTR = PTR -> NEXT

  4) EXIT

*/

void Queue :: display() {
  if(front == NULL) {
    cout<<"The Queue is empty !\n";
  }
  else {
    node *ptr = front;

    while(ptr != NULL) {
      cout<<ptr->data<<" ";
      ptr = ptr->next;
    } cout<<endl;
  }
}


// Main Function
int main() {
  int option, value;
  Queue q;

  do {
    cout<<"\n**** MENU ****\n"
        <<"1. Insert\n"
        <<"2. Delete\n"
        <<"3. Display\n"
        <<"4. Exit\n";

    cout<<"Enter your option: ";
    cin>>option;

    switch(option) {
      case 1: cout<<"Enter the value to be inserted: ";
              cin>>value;

              q.insert(value);
              break;

      case 2: q.del();
              break;

      case 3: q.display();
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
