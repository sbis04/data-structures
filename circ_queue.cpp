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
  void del();
  void display();
};


/*

ALGORITHM FOR INSERTING AN ELEMENT IN THE QUEUE:

  1) IF (FRONT = REAR+1) OR (FRONT = 0 AND REAR = MAX-1)
        WRITE Overflow
        EXIT

  2) IF FRONT = -1 & REAR = -1
        FRONT = 0

  3) REAR = (REAR + 1) % MAX
  3) QUEUE[REAR] = VALUE
  4) EXIT

*/

void Queue :: insert(int value) {
  // When both front and rear is equal to -1, then the queue is empty
  if((front == rear+1) || (front == 0 && rear == MAX-1)) {
    cout<<"The Queue is full !\n";
  }
  else {
    // For inserting when the queue is empty
    if(front == -1 && rear == -1) {
      front = 0;
    }
    // Using modular arithmatic to calculate the rear
    rear = (rear+1) % MAX;

    // Storing the value in rear position of queue
    queue[rear] = value;
  }
}


/*

ALGORITHM FOR DELETING AN ELEMENT FROM THE QUEUE:

  1) IF FRONT = -1 AND REAR = -1
        WRITE Underflow
        EXIT

  2) ITEM = QUEUE[FRONT]
  3) IF FRONT = REAR
        FRONT = -1 AND REAR = -1

  4) ELSE
        FRONT = (FRONT + 1) % MAX

  5) EXIT

*/

void Queue :: del() {
  // When both front and rear is equal to -1, then the queue is empty
  if(front == -1 && rear == -1) {
    cout<<"The Queue is empty !\n";
  }
  else {
    cout<<"The deleted element is "<<queue[front]<<endl;

    // If front is equal to rear then the queue will be empty
    // after deleting element, so set both front and rear to -1
    if(front == rear) {
      front = -1;
      rear = -1;
    }
    else {
      // Using modular arithmatic to calculate the front
      front = (front+1) % MAX;
    }
  }
}


// Display the elements of the Queue by incrementing
void Queue :: display() {
  // When both front and rear is equal to -1, then the queue is empty
  if(front == -1 && rear == -1) {
    cout<<"The Queue is empty !\n";
  }
  else {
    // Printing each element
    for(int i=front; i<=rear; i++) {
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
