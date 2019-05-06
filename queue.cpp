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

// Defining the maximum size of the queue to be 10
#define MAX 10

// Defining a class to store the member variables
// and member functions required
class Queue {
  int queue[MAX], front, rear;

public:
  Queue(): front(-1), rear(-1) {}
  void insert(int );
  int del();
  void display();
};


/*

ALGORITHM FOR INSERTING AN ELEMENT IN THE QUEUE:

  1) IF REAR = MAX-1
        WRITE Overflow
        EXIT

  2) REAR = REAR + 1
  3) QUEUE[REAR] = VALUE
  4) EXIT

*/

void Queue :: insert(int value) {
  if(rear == MAX-1) {
    cout<<"The Queue is full !\n";
  }
  else {
    rear++;
    queue[rear] = value;
  }
}


/*

ALGORITHM FOR POPPING AN ELEMENT FROM THE STACK:

  1) IF FRONT = REAR
        WRITE Underflow
        RETURN -1
        EXIT

  2) FRONT = FRONT + 1
  3) VALUE = QUEUE[FRONT]
  4) RETURN VALUE
  5) EXIT

*/

int Queue :: del() {
  // When front is equal to rear, then the queue is empty
  if(front == rear) {
    cout<<"The Queue is empty !\n";
    return -1;
  }
  else {
    // Incrementing front
    front++;

    // Storing the element in front position in value
    int value = queue[front];

    return value;
  }
}

// Display the elements of the Queue by incrementing
void Queue :: display() {
  // When front is equal to rear, then the queue is empty
  if(front == rear) {
    cout<<"The Queue is empty !\n";
  }
  else {
    // Printing each element
    for(int i=front+1; i<=rear; i++) {
      cout<<queue[i]<<" ";
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

      case 2: value = q.del();
              if(value != -1) {
                cout<<"The deleted element is: "<<value<<endl;
              }
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
