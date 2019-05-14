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

struct node *insert(node *);
struct node *del(node *);
void display(node *);

/*

Declaring a structure called node
having two members:

  1) data block
  2) priority block (to store the priority of the queue)
  3) next block (which stores the address of the next node)

 */

struct node {
  int data;
  int priority;
  node *next;
};

node *insert(node *start) {
  int value, priority;

  cout<<"Enter the value to be inserted: ";
  cin>>value;

  cout<<"Enter the priority: ";
  cin>>priority;

  node *new_node = new node;
  new_node->data = value;
  new_node->priority = priority;

  if(start == NULL || priority < start->priority) {
    new_node->next = start;
    start = new_node;
  }
  else {
    node *ptr = start;

    if(ptr->next != NULL && ptr->next->priority <= priority) {
      ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
  }

  return start;
}

node *del(node *start) {
  if(start == NULL) {
    cout<<"The Queue is empty !\n";
  }
  else {
    node *ptr = start;

    cout<<"The deleted node is "<<ptr->data<<endl;

    start = start->next;
    delete ptr;
  }
  return start;
}

void display(node *start) {
  if(start == NULL) {
    cout<<"The Queue is empty !\n";
  }
  else {
    node *ptr = start;

    while(ptr != NULL) {
      cout<<ptr->data<<" [Priority: "<<ptr->priority<<"]"<<endl;
      ptr = ptr->next;
    }
  }
}

int main() {
  node *start = NULL;

  int option;

  do {
    cout<<"\n***** MENU *****\n"
        <<"1. Insert\n"
        <<"2. Delete\n"
        <<"3. Display\n"
        <<"4. Exit\n";

    cout<<"Enter your option: ";
    cin>>option;

    switch(option) {
      case 1: start = insert(start);
              break;

      case 2: start = del(start);
              break;

      case 3: cout<<"The Queue elements are:\n";
              display(start);
              break;

      case 4: break;

      default: cout<<"Wrong option !\n";
               break;
    }
  } while(option != 4);

  if(option == 4) {
    cout<< "\nTHANK YOU for using the program !\n"
        <<"Have a good day.\n\n";

    delete start;
  }
}
