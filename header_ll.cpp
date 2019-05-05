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


// Function prototypes
struct node *insert_beg(node *, int );
struct node *insert_end(node *, int );
struct node *insert_after(node *, int );
struct node *insert_before(node *, int );

struct node *create(node *);

void count(node *);
void display(node *);


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

ALGORITHM FOR INSERTING AT THE BEGINNING:

  1) IF AVAIL = NULL
        Write Overflow
        EXIT

  2) NEW_NODE = AVAIL
  3) AVAIL = AVAIL -> NEXT
  4) NEW_NODE -> DATA = VALUE
  5) NEW_NODE -> NEXT = START -> NEXT
  6) START -> NEXT = NEW_NODE
  7) EXIT

*/

node *insert_beg(node *start, int value) {
  // Creating a new node
  node *new_node = new node;

  // Storing the data and assigning
  // which address to keep in the next block
  new_node->data = value;
  new_node->next = start->next;

  // Updating the next block of start
  start->next = new_node;

  return start;
}


/*

ALGORITHM FOR INSERTING AT THE END:

  1) IF AVAIL = NULL
        Write Overflow
        EXIT

  2) NEW_NODE = AVAIL
  3) AVAIL = AVAIL -> NEXT
  4) NEW_NODE -> DATA = VALUE
  5) NEW_NODE -> NEXT = START
  6) PTR = START -> NEXT
  7) WHILE PTR -> NEXT != START
        PTR = PTR -> next

  8) PTR -> NEXT = NEW_NODE
  7) EXIT

*/

node *insert_end(node *start, int value) {
  // Storing the value of start to ptr
  node *ptr = start->next;

  // Creating a new node
  node *new_node = new node;

  // Storing the data and assigning
  // which address to keep in the next block
  new_node->data = value;
  new_node->next = start;

  // Searching for the last element after which we should insert
  while(ptr->next != start) {
    // Incrementing
    ptr = ptr->next;
  }

  // Storing the address of new node to the next pointer of ptr
  ptr->next = new_node;

  return start;
}


/*

ALGORITHM FOR INSERTING AFTER A GIVEN NODE:

  1) IF AVAIL = NULL
        Write Overflow
        EXIT

  2) NEW_NODE = AVAIL
  3) AVAIL = AVAIL -> NEXT
  4) NEW_NODE -> DATA = VALUE
  5) PTR = START -> NEXT
  6) PREPTR = PTR
  7) WHILE PREPTR -> NEXT != NUM
        PREPTR = PTR
        PTR = PTR -> NEXT

  8) PREPTR -> NEXT = NEW_NODE
  9) NEW_NODE -> NEXT = PTR
  10) EXIT

*/

node *insert_after(node *start, int value) {
  int num;

  // Storing the value of start to ptr
  node *ptr = start->next;

  // Number after which to insert
  cout<<"Enter the number after which to insert: ";
  cin>>num;

  // Creating a new node
  node *new_node = new node;

  // Storing the data
  new_node->data = value;

  // Taking another node to store the location of
  // the element before ptr
  node *preptr = ptr;

  // Incrementing till the number is found
  while(preptr->data != num) {
    preptr = ptr;
    ptr = ptr->next;
  }

  // Adding the new node
  preptr->next = new_node;
  new_node->next = ptr;

  return start;
}


/*

ALGORITHM FOR INSERTING BEFORE A GIVEN NODE:

  1) IF AVAIL = NULL
        Write Overflow
        EXIT

  2) NEW_NODE = AVAIL
  3) AVAIL = AVAIL -> NEXT
  4) NEW_NODE -> DATA = VALUE
  5) PTR = START -> NEXT
  6) PREPTR = PTR
  7) WHILE PTR -> NEXT != NUM
        PREPTR = PTR
        PTR = PTR -> NEXT

  8) PREPTR -> NEXT = NEW_NODE
  9) NEW_NODE -> NEXT = PTR
  10) EXIT

*/

node *insert_before(node *start, int value) {
  int num;

  // Number after which to insert
  cout<<"Enter the number before which to insert: ";
  cin>>num;

  // Creating a new node
  node *new_node = new node;

  // Storing the data
  new_node->data = value;

  // Storing the value of start to ptr
  node *ptr = start->next;

  // Taking another node to store the location of
  // the element before ptr
  node *preptr = ptr;

  // Incrementing till the number is found
  while(ptr->data != num) {
    preptr = ptr;
    ptr = ptr->next;
  }

  // Adding the new node
  preptr->next = new_node;
  new_node->next = ptr;

  return start;
}


/*

ALGORITHM FOR CREATING THE LINKED LIST:

  1) IF START = NULL
  2)    IF AVAIL = NULL
            Write Overflow
            EXIT

  3)    NEW_NODE = AVAIL
  4)    AVAIL = AVAIL -> NEXT
  5)    NEW_NODE -> DATA = VALUE
  6)    START -> NEXT = NEW_NODE
  7)    NEW_NODE -> NEXT = START
     [ END OF IF ]

  8) ELSE
        INSERT AT THE END

  9) EXIT

*/

node *create(node *start) {
  int value;

  // Storing the value to be inserted
  cout<<"Enter -1 to stop\n";
  cout<<"Enter the value to be stored: ";
  cin>>value;

  while(value != -1){
    if(start == NULL) {
      node *new_node = new node;
      new_node->data = value;

      start = new node;
      start->next = new_node;
      new_node->next = start;
    }
    else {
      // Elements are inserted at the end
      insert_end(start, value);
    }

    cout<<"Enter the value to be stored: ";
    cin>>value;
  }

  return start;
}


/*

ALGORITHM FOR COUNTING THE NUMBER OF ELEMENTS:

  1) IF START = NULL
        Write Underflow
        EXIT

  2) PTR = START
  3) SET COUNT = 0
  4) WHILE PTR != NULL
        COUNT = COUNT + 1
        PTR = PTR -> NEXT

  5) WRITE COUNT
  6) EXIT

*/

void count(node *start) {
  int count = 0;

  // Checking if the linked list is empty
  if(start == NULL) {
    cout<<"The linked list is empty !\n";
  }
  else {
    count = 1;

    // Storing start in ptr
    node *ptr = start->next;

    // Incrementing till the end
    while(ptr->next != start) {
      count++;
      ptr = ptr->next;
    }
  }
  // Printing the number of elements
  cout<<"The number of elements present in the linked list are: "
      <<count
      <<endl;
}


/*

ALGORITHM FOR DISPLAYING THE ELEMENTS:

  1) IF START = NULL
        Write Underflow
        EXIT

  2) PTR = START
  3) WHILE PTR != START
        Write PTR -> DATA
        PTR = PTR -> NEXT
  4) EXIT

*/

void display(node *start) {
  // Checking if the linked list is empty
  if(start == NULL) {
    cout<<"The linked list is empty !\n";
  }
  else {
    // Storing start in ptr
    node *ptr = start->next;

    // Incrementing till the end
    while(ptr->next != start) {
      // Printing the elements
      cout<<ptr->data<<" ";
      ptr = ptr->next;

    }
    cout<<ptr->data<<endl;
  }
}


// Main Function
int main() {
  // Initialize start to be null
  node *start = NULL;

  int option, value;

  // Continuing to show the menu till the program is exited
  do {
    cout<<"\n********** MENU **********\n"
        <<"1. Create the linked list\n"
        <<"2. Insert at the beginning\n"
        <<"3. Insert at the end\n"
        <<"4. Insert after an element\n"
        <<"5. Insert before an element\n"
        <<"6. Count\n"
        <<"7. Display\n"
        <<"8. Exit\n";

    cout<<"Enter your option: ";
    cin>>option;

    switch(option) {

      case 1: start = create(start);
              break;

      case 2: // Storing the value to be inserted
              cout<<"Enter the value to be stored: ";
              cin>>value;

              start = insert_beg(start, value);
              break;

      case 3: // Storing the value to be inserted
              cout<<"Enter the value to be stored: ";
              cin>>value;

              start = insert_end(start, value);
              break;

      case 4: // Storing the value to be inserted
              cout<<"Enter the value to be stored: ";
              cin>>value;

              start = insert_after(start, value);
              break;

      case 5: // Storing the value to be inserted
              cout<<"Enter the value to be stored: ";
              cin>>value;

              start = insert_before(start, value);
              break;

      case 6: count(start);
              break;

      case 7: display(start);
              break;

      case 8: break;

      default: cout<<"Wrong option is selecred !!\n";
              break;
    }
  } while(option != 8);

  // Freeing the space occupied by start
  if(option == 8) {
    cout<< "\nTHANK YOU for using the program !\n"
        <<"Have a good day.\n\n";

    delete start;
  }
}
