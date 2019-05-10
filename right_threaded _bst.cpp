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

// Functions for inserting an element in the tree
// and creating the tree by calling insert method repetadly
struct node *insert(node *, int );
struct node *create(node *);

// Functions for traversing the tree
void inorderTraversal(node *);

/*

Declaring a structure called node
having four members:

  1) left block (which stores the address of the left node)
  2) data block (which stores the value)
  3) right block (which stores the address of the right node)
  4) rightThread block (which stores the a boolean, determing whether
                        the node has a right branch or not)

 */

struct node {
  node *left;
  int data;
  node *right;
  bool rightThread;
};


/*

ALGORITHM FOR INSERTING A NODE IN THE TREE:

  1) IF AVAIL = NULL
        WRITE Overflow
        EXIT

  2) NEW_NODE = AVAIL
  3) AVAIL = AVAIL -> LEFT
  4) NEW_NODE -> DATA = VALUE
  5) NEW_NODE -> LEFT = NULL
  6) NEW_NODE -> RIGHT_THREAD = 1
  7) IF TREE = NULL
        TREE = NEW_NODE
        NEW_NODE -> RIGHT = NULL
        NEW_NODE -> RIGHT_THREAD = 0

  8) ELSE
  9)    PAR = NULL
  10)   CUR = TREE
  11)   WHILE CUR != NULL
  12)       PAR = CUR
  13)       IF VALUE < CUR -> data
                CUR = CUR -> LEFT

  14)       ELSE
                IF RIGHT_THREAD = 1
                      CUR = NULL
                ELSE
                      CUR = CUR -> RIGHT
                [END OF IF]
            [END OF IF]
        [END OF WHILE]

  15) IF VALUE < PAR -> DATA
        PAR -> LEFT = NEW_NODE
        NEW_NODE -> RIGHT = PAR
        NEW_NODE -> RIGHT_THREAD = 1

  16) ELSE
        IF PAR -> RIGHT_THREAD = 1
              PAR -> RIGHT_THREAD = 0
              NEW_NODE -> RIGHT_THREAD = 1
              NEW_NODE -> RIGHT = PAR -> RIGHT
              PAR -> RIGHT = NEW_NODE

        ELSE
              NEW_NODE -> RIGHT_THREAD = 0
              NEW_NODE -> RIGHT = NULL
              PAR -> RIGHT = NEW_NODE

        [END OF IF]
      [END OF IF]

  17) EXIT

*/

node *insert(node *tree, int value) {
  // Creating a new node
  node *new_node = new node;
  // Storing values in all blocks of new_node
  new_node->data = value;
  new_node->left = NULL;
  new_node->rightThread = true;

  // When tree is null, just store the new_node in tree
  if(tree == NULL) {
    tree = new_node;
    new_node->right = NULL;
    new_node->rightThread = false;
  }
  else {
    // Setting parent node to null
    node *parentNode = NULL;
    // Storing tree in current node
    node *currentNode = tree;

    // Repeat when current node is null
    while(currentNode != NULL) {
      // Storing current node in parent node
      parentNode = currentNode;

      // When the value to be inserted is less than the current node,
      // we have to go to the left branch and otherwise
      // check if the currentNode has any right thread

      // 1) if it has then, assign null to currentNode, else
      // 2) Traverse currentNode's right branch by one palce
      if(value < currentNode->data) {
        currentNode = currentNode->left;
      }
      else {
        if(currentNode->rightThread) {
          currentNode = NULL;
        }
        else {
          currentNode = currentNode->right;
        }
      }
    }

    // When the value to be inserted is less than the parentNode value
    if(value < parentNode->data) {
       parentNode->left = new_node;
       new_node->right = parentNode;
       new_node->rightThread = true;
     }
     // When the value to be inserted is greater than the parentNode value
     else {
       // When parentNode's right thread is present
       if(parentNode->rightThread) {
         parentNode->rightThread = false;
         new_node->rightThread = true;
         new_node->right = parentNode->right;
         parentNode->right = new_node;
       }
       else {
         new_node->rightThread = false;
         new_node->right = NULL;
         parentNode->right = new_node;
       }
     }
  }
  return tree;
}

// Creating the tree by calling insert method repetadly
node *create(node *tree) {
  int value;

  // Taking the value to be inserted as input
  cout<<"Enter the value to be inserted: ";
  cin>>value;

  // When the value is -1, then stop storing more values
  while(value != -1) {
    tree = insert(tree, value);

    // Taking the value to be inserted as input
    cout<<"Enter the value to be inserted: ";
    cin>>value;
  }

  return tree;
}


/*

ALGORITHM FOR INORDER TRAVERSAL:

  1) CUR = TREE
  2) DO
     {
  2.1)      PAR = NULL

  2.2)      WHILE CUR != NULL
                  PAR = CUR
                  CUR = CUR ->LEFT
            [END OF WHILE]

  2.3)      IF PAR != NULL
                PRINT PAR -> DATA
                CUR = PAR -> RIGHT

                WHILE PAR -> RIGHT_THREAD = 1 && CUR != NULL
                      PRINT CUR -> DATA
                      PAR = CUR
                      CUR = CUR -> RIGHT
                [END OF WHILE]
            [END OF IF]

      } WHILE CUR != NULL

      [END OF DO-WHILE]

   3) EXIT
*/

void inorderTraversal(node *tree) {
  // Storing the tree node in currentNode
  node *currentNode = tree;

  do {
    // Assigning parentNode to be null initially
    node *parentNode = NULL;

    // When current is not null traverse the left branch of the
    // current node
    while(currentNode != NULL) {
      parentNode = currentNode;
      currentNode = currentNode->left;
    }

    if(parentNode != NULL) {
      // Printing thr parentNode value
      cout<<parentNode->data<<" ";

      // Storing parentNode -> right in currentNode
      currentNode = parentNode->right;

      // When parentNode has rightThread and currentNode is not null
      while(parentNode->rightThread && currentNode != NULL) {
        // Print the currentNode value
        cout<<currentNode->data<<" ";

        // Store currentNode in parentNode
        parentNode = currentNode;

        // traverse the left branch of the current node by one place
        currentNode = currentNode->right;
      }
    }
  } while(currentNode != NULL);
}


// MAIN FUNCTION
int main() {
  // Setting the root node to null, initially
  node *root = NULL;

  int option, value;

  do {
    cout<<"\n***** MENU *****\n"
        <<"1. Create\n"
        <<"2. Insert\n"
        <<"3. Inorder Traversal\n"
        <<"4. Exit\n";

    cout<<"Enter your option: ";
    cin>>option;

    switch(option) {
      case 1: root = create(root);
              break;

      case 2: cout<<"Enter the value to be inserted: ";
              cin>>value;

              root = insert(root, value);
              break;

      case 3: inorderTraversal(root);
              cout<<endl;
              break;

      case 4: break;

      default: cout<<"Wrong option !\n";
              break;
    }
  } while(option != 4);

  if(option == 4) {
    // Freeing the space for root, after execution of the program
    delete root;

    cout<< "\nTHANK YOU for using the program !\n"
        <<"Have a good day.\n\n";
  }
}
