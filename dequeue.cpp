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


struct node {
    int data;
    struct node* link;
};


struct node* front, *rear;

void insert_right(struct node* front1, struct node* rear1, int item){
    struct node* newNode = new node;
    if(newNode == NULL)
        {
            cout << "Overflow in memory";
            return;
        }
    newNode->data = item;
    newNode->link = NULL;

    if(front == NULL && rear == NULL)
        {
            front = rear = newNode;
        }
    else
    {
        rear->link = newNode;
        rear = newNode;
    }
    
}

void delete_front(struct node* front1, struct node* rear1){
    if(front == NULL)
    {
        cout << "Queue is already empty.";
        return;
    }

    struct node* to_delete = front;

    if(front == rear){
        front = rear =NULL;
    }

    else {
        front = front->link;
        to_delete->link = NULL;    
    }
}

void insert_beg(struct node* front1, struct node* rear1, int item){
    struct node* newNode = new node;
    newNode->data = item;
    newNode->link = NULL;
    if(newNode == NULL)
    {
        cout << "Overflow in memory";
        return;
    } 

    if(front == NULL && rear == NULL)
        front = rear = newNode;
    else{ 
        newNode->link = front;
        front = newNode;
    }
}

void delete_rear(struct node* front1, struct node* rear1){
    if(front == NULL && rear == NULL){
        cout << "Underflow\n";
        return;
    }

    struct node* parent = front;
    while(1){
        if(parent->link != NULL && parent->link == rear)
            break;
        else if(parent == rear)
            break;
        parent = parent->link;
    }

    if(parent == rear){
        front = rear = NULL;
    }
    else if(parent->link  == rear){
        parent->link =  NULL;

        // I forgot to update the rear pointer here and that causes
        // problems
        
        rear = parent;
    }
}


void print_queue(struct node* front1, struct node* rear1){
    
    if(front == NULL && rear == NULL){
        cout << "Queue doesn't exist";
        return;
    }
    struct node* ptr = front;
    while(ptr != NULL){
        cout  << ptr->data << " ";
        ptr = ptr->link;
    }

}

int main(){


    struct node* front =  NULL;
    struct node* rear = NULL;
    cout << "1. Enter element at end\n";
    cout << "2. Enter element in start\n";
    cout << "3. Delete element from start\n";
    cout << "4. Delete element from end\n";

    int choice;
    cin >> choice;
    cin.ignore();
    int item;
    do{
        switch (choice)
        {
        case 1:
            cout << "Enter item: ";
            cin >> item;
            cin.ignore();
            insert_right(front, rear, item);
            cout << "Printing\n";
            print_queue(front, rear);
            break;
        case 2:
            cout << "Enter item: ";
            cin >> item;
            cin.ignore();
            insert_beg(front, rear, item);
            print_queue(front, rear);
            break;

        case 3: 
            delete_front(front, rear);
            print_queue(front, rear);
            break;
        case 4:
            delete_rear(front, rear);
            print_queue(front, rear);
        default:
            break;
        }

        cout << "\nEnter choice: ";
        cin >> choice;
        cin.ignore();
    }while(choice != -1);
}