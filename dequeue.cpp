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

void input_dequeue();
void output_dequeue();


/*

Declaring a class called Dequeue having:

  three private members:
        dequeue[MAX]
        left
        right

  three public member functions:

        Constructor defining left to -1 and right to -1

        insert right
        insert left
        delete right
        delete left
        display

*/

class Dequeue {
  int dequeue[MAX], left, right;

public:
  Dequeue(): left(-1), right(-1) {}
  void insert_right(int );
  void insert_left(int );
  void del_right();
  void del_left();
  void display();
};

void Dequeue :: insert_right(int value) {
  if((left == right + 1) || (left == 0 && right == MAX-1)) {
    cout<<"The Queue is full !\n";
    return;
  }
  if(left == -1) {
    left = 0;
    right = 0;
  }
  else {
    if(right == MAX-1) {
      right = 0;
    }
    else {
      right++;
    }
  }
  dequeue[right] = value;
}

void Dequeue :: insert_left(int value) {
  if((left == right + 1) || (left == 0 && right == MAX-1)) {
    cout<<"The queue is full !\n";
    return;
  }
  if(left == -1) {
    left = 0;
    right = 0;
  }
  else {
    if(left == 0) {
      left = MAX-1;
    }
    else {
      left--;
    }
  }
  dequeue[left] = value;
}

void Dequeue :: del_right() {
  if(left == -1) {
    cout<<"The queue is empty !\n";
    return;
  }

  cout<<"The deleted value is: "<<dequeue[right]<<endl;

  if(left == right) {
    left = -1;
    right = -1;
  }
  else {
    if(right == 0) {
      right = MAX-1;
    }
    else {
      right--;
    }
  }
}

void Dequeue :: del_left() {
  if(left == -1) {
    cout<<"The queue is empty !\n";
    return;
  }

  cout<<"The deleted value is: "<<dequeue[left]<<endl;

  if(left == right) {
    left = -1;
    right = -1;
  }
  else {
    if(left == MAX-1) {
      left = 0;
    }
    else {
      left++;
    }
  }
}

void Dequeue :: display() {
  int front = left;
  int rear = right;

  if(front == -1) {
    cout<<"The queue is empty !\n";
    return;
  }
  if(front <= rear) {
    while(front <= rear) {
      cout<<dequeue[front]<<" ";
      front++;
    }
  }
  else {
    while(front <= MAX-1) {
      cout<<dequeue[front]<<" ";
      front++;
    }
    front = 0;
    while(front <= rear) {
      cout<<dequeue[front]<<" ";
      front++;
    }
  }
  cout<<endl;
}

void input_dequeue() {
  int option, value;
  Dequeue dq;

  do {
    cout<<"\n****** MENU ******\n"
        <<"1. Insert right\n"
        <<"2. Delete right\n"
        <<"3. Delete left\n"
        <<"4. Display\n"
        <<"5. Exit to Main Menu\n";

    cout<<"Enter your option: ";
    cin>>option;

    switch(option) {
      case 1: cout<<"Enter the value to be inserted: ";
              cin>>value;

              dq.insert_right(value);
              break;

      case 2: dq.del_right();
              break;

      case 3: dq.del_left();
              break;

      case 4: dq.display() ;
              break;

      case 5: break;

      default: cout<<"Wrong option !\n";
               break;
    }
  } while(option != 5);
}

void output_dequeue() {
  int option, value;
  Dequeue dq;

  do {
    cout<<"\n****** MENU ******\n"
        <<"1. Insert right\n"
        <<"2. Insert left\n"
        <<"3. Delete left\n"
        <<"4. Display\n"
        <<"5. Exit to Main Menu\n";

    cout<<"Enter your option: ";
    cin>>option;

    switch(option) {
      case 1: cout<<"Enter the value to be inserted: ";
              cin>>value;

              dq.insert_right(value);
              break;

      case 2: cout<<"Enter the value to be inserted: ";
              cin>>value;

              dq.insert_left(value);
              break;

      case 3: dq.del_left();
              break;

      case 4: dq.display() ;
              break;

      case 5: break;

      default: cout<<"Wrong option !\n";
               break;
    }
  } while(option != 5);
}

int main() {
  int option, value;
  Dequeue dq;

  do {
    cout<<"\n******* MAIN MENU *******\n"
        <<"1. Input Restricted Dequeue\n"
        <<"2. Output Restricted Dequeue\n"
        <<"3. Exit\n";

    cout<<"Enter your option: ";
    cin>>option;

    switch(option) {
      case 1: input_dequeue();
              break;

      case 2: output_dequeue();
              break;

      case 3: break;

      default: cout<<"Wrong option !\n";
               break;
    }
  } while(option != 3);

  if(option == 3) {
    cout<< "\nTHANK YOU for using the program !\n"
        <<"Have a good day.\n\n";
  }
}
