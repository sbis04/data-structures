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

struct node *del_beg(node *);
struct node *del_end(node *);

void count(node *);
void display(node *);


/*

Declaring a structure called node
having three members:

  1) prev block (which stores the address of the previous node)
  2) data block
  3) next block (which stores the address of the next node)

 */

struct node {
  node *prev;
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
  5) NEW_NODE -> PREV = START -> PREV
  6) NEW_NODE -> NEXT = START
  7) START -> PREV -> NEXT = NEW_NODE
  8) START -> PREV = NEW_NODE
  9) START = NEW_NODE
  10) EXIT

*/

node *insert_beg(node *start, int value) {
  // Creating a new node
  node *new_node = new node;

  // Storing the data and assigning
  // which address to keep in the next block and prev block
  new_node->data = value;
  new_node->prev = start->prev;
  new_node->next = start;

  // Updating the next block of last node
  start->prev->next = new_node;

  // Updating the prev block of start to store the address
  start->prev = new_node;

  // making the start point to be first element of the linked list
  start = new_node;

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
  5) NEW_NODE -> PREV = START -> PREV
  6) NEW_NODE -> NEXT = START
  7) START -> PREV -> NEXT = NEW_NODE
  8) START -> PREV = NEW_NODE
  9) EXIT

*/

node *insert_end(node *start, int value) {
  // Creating a new node
  node *new_node = new node;

  // Storing the data and assigning
  // which address to keep in the next block
  new_node->data = value;
  new_node->prev = start->prev;
  new_node->next = start;

  // Accommodating the new node at the end
  start->prev->next = new_node;
  start->prev = new_node;

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
  5) PTR = START
  6) WHILE ptr -> DATA != NUM
        PTR = PTR -> NEXT

  7) NEW_NODE -> NEXT = PTR -> NEXT
  8) NEW_NODE -> PREV = PTR
  9) PTR -> NEXT -> PREV = NEW_NODE
  10) PTR -> NEXT = NEW_NODE
  11) EXIT

*/

node *insert_after(node *start, int value) {
  int num;

  // Number after which to insert
  cout<<"Enter the number after which to insert: ";
  cin>>num;

  // Creating a new node
  node *new_node = new node;

  // Storing the data
  new_node->data = value;

  // Storing the value of start to ptr
  node *ptr = start;

  // Incrementing till the number is found
  while(ptr->data != num) {
    ptr = ptr->next;
  }

  // Adding the new node
  new_node->next = ptr->next;
  new_node->prev = ptr;
  ptr->next->prev = new_node;
  ptr->next = new_node;

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
  5) PTR = START
  6) WHILE PTR -> NEXT != NUM
        PREPTR = PTR
        PTR = PTR -> NEXT

  7) NEW_NODE -> NEXT = PTR
  8) NEW_NODE -> PREV = PTR -> PREV
  9) PTR -> PREV -> NEXT = NEW_NODE
  10) PTR -> PREV = NEW_NODE
  11) EXIT

*/

node *insert_before(node *start, int value) {
  int num;

  // Number after which to insert
  cout<<"Enter the number before which to insert: ";
  cin>>num;

  // Solving edge case #1
  if(start->data == num) {
    // If the element is present is to be inserted before a number,
    // which is in the beginning, then use the insert_beg method
    // to insert the new value.
    start = insert_beg(start, value);
  }
  else {
    // Creating a new node
    node *new_node = new node;

    // Storing the data
    new_node->data = value;

    // Storing the value of start to ptr
    node *ptr = start;

    // Incrementing till the number is found
    while(ptr->data != num) {
      ptr = ptr->next;
    }

    // Adding the new node
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
  }

  return start;
}


// For creating the entire linked list
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

      start = new_node;

      new_node->prev = start;
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

ALGORITHM FOR DELETING FROM THE BEGINNING:

  1) IF START = NULL
        Write Underflow
        EXIT

  2) PTR = START
  3) PTR -> PREV -> NEXT = START -> NEXT
  4) PTR -> NEXT -> PREV = START -> PREV
  4) DELETE START
  5) START = PTR -> NEXT
  6) EXIT

*/

node *del_beg(node *start) {
  // Checking if the linked list is empty
  if(start == NULL) {
    cout<<"The linked list is empty !\n";
  }
  else {
    // Storing start to ptr
    node *ptr = start;

    ptr->prev->next = start->next;
    ptr->next->prev = start->prev;

    // Printing the value to be deleted
    cout<<"The deleted value is: "<<start->data<<endl;

    // Deleting the first element
    delete start;

    start = ptr->next;
  }

  return start;
}


/*

ALGORITHM FOR DELETING FROM THE END:

  1) IF START = NULL
        Write Underflow
        EXIT

  2) PTR = START -> PREV
  3) PTR -> PREV -> NEXT = START;
  4) START -> PREV = PTR -> PREV
  5) DELETE PTR
  6) EXIT

*/

node *del_end(node *start) {
  // Checking if the linked list is empty
  if(start == NULL) {
    cout<<"The linked list is empty !\n";
  }
  else {
    // Storing start to ptr
    node *ptr = start->prev;

    ptr->prev->next = start;
    start->prev = ptr->prev;

    // Printing the value to be deleted
    cout<<"The deleted value is: "<<ptr->data<<endl;

    // Deleting the last element
    delete ptr;
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
    node *ptr = start;

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
  3) WHILE PTR != NULL
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
    node *ptr = start;

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
        <<"6. Delete from the beginning\n"
        <<"7. Delete from the end\n"
        <<"8. Count\n"
        <<"9. Display\n"
        <<"10. Exit\n";

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

      case 6: start = del_beg(start);
              break;

      case 7: start = del_end(start);
              break;

      case 8: count(start);
              break;

      case 9: display(start);
              break;

      case 10: break;

      default: cout<<"Wrong option is selecred !!\n";
              break;
    }
  } while(option != 10);

  // Freeing the space occupied by start
  if(option == 10) {
    cout<< "\nTHANK YOU for using the program !\n"
        <<"Have a good day.\n\n";

    delete start;
  }
}
