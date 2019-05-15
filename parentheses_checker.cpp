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
  int stk[MAX];

public:
  int top;
  Stack(): top(-1) {}
  void push(char );
  char pop();
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

void Stack :: push(char value) {
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

char Stack :: pop() {
  // When the size of stack is -1, the stack is empty
  if(top == -1) {
    cout<<"The Stack is empty !\n";
    return -1;
  }
  else {
    // Store the top value
    char value = stk[top];

    // Decrement top
    top --;

    return value;
  }
}


int main() {
  Stack s;
  string exp;
  char temp;
  int flag = 1;

  cout<<"Enter the expression: ";
  getline(cin, exp);

  for(int i=0; i < exp.length(); i++) {
    if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
      s.push(exp[i]);
    }
    if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
      if(s.top == -1) {
        flag = 0;
      }
      else {
        temp = s.pop();
        if((exp[i] == ')') && (temp == '{' || temp == '[')) {
          flag = 0;
        }
        if((exp[i] == '}') && (temp == '(' || temp == ']')) {
          flag = 0;
        }
        if((exp[i] == ']') && (temp == '(' || temp == '{')) {
          flag = 0;
        }
      }
    }
  }

  if(s.top >= 0) {
    flag = 0;
  }

  if(flag == 1) {
    cout<<"The expression is valid.\n";
  }
  else {
    cout<<"The expression is not valid.\n";
  }
}
