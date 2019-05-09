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

// Functions for finding smallest and largest element of the tree
struct node *findSmallestElement(node *);
struct node *findLargestElement(node *);

// Functions for traversing the tree
void preorderTraversal(node *);
void inorderTraversal(node *);
void postorderTraversal(node *);

// Functions for finding the number of nodes
int totalNodes(node *);
int totalExternalNodes(node *);
int totalInternalNodes(node *);


/*

Declaring a structure called node
having three members:

  1) left block (which stores the address of the left node)
  2) data block (which stores the value)
  3) right block (which stores the address of the right node)

 */

struct node {
  node *left;
  int data;
  node *right;
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
  6) NEW_NODE -> RIGHT = NULL
  7) IF TREE = NULL
        TREE = NEW_NODE

  8) ELSE
  9)    PAR = NULL
  10)   CUR = TREE
  11)   WHILE CUR != NULL
  12)       PAR = CUR
  13)       IF VALUE < CUR -> data
                CUR = CUR -> LEFT

  14)       ELSE
                CUR = CUR -> RIGHT
            [END OF IF]
        [END OF WHILE]

  15)   IF VALUE < PAR -> DATA
            PAR -> LEFT = NEW_NODE

  16)    ELSE
            PAR -> RIGHT = NEW_NODE

  17) EXIT

*/

node *insert(node *tree, int value) {
  // Creating a new node
  node *new_node = new node;
  // Storing values in all blocks of new_node
  new_node->data = value;
  new_node->left = NULL;
  new_node->right = NULL;

  // When tree is null, just store the new_node in tree
  if(tree == NULL) {
    tree = new_node;
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
      // we have to go to the left branch and otherwise right
      if(value < currentNode->data) {
        currentNode = currentNode->left;
      }
      else {
        currentNode = currentNode->right;
      }
    }

    // When the value is less than the parent node,
    // we have to go to the left branch and otherwise right
    if(value < parentNode->data) {
      parentNode->left = new_node;
    }
    else {
      parentNode->right = new_node;
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

ALGORITHM FOR FINDING THE SMALLEST ELEMENT OF THE TREE:

  1) IF TREE = NULL OR TREE -> LEFT = NULL
        RETURN TREE
  2) ELSE
        RETURN ( RECURSIVELY CALLING FIND_SMALLEST_ELEMENT PASSING TREE -> LEFT)

  3) EXIT

*/

node *findSmallestElement(node *tree) {
  if((tree == NULL) || (tree->left == NULL)) {
    return tree;
  }
  else {
    return findSmallestElement(tree->left);
  }
}


/*

ALGORITHM FOR FINDING THE LARGEST ELEMENT OF THE TREE:

  1) IF TREE = NULL OR TREE -> RIGHT = NULL
        RETURN TREE
  2) ELSE
        RETURN ( RECURSIVELY CALLING FIND_SMALLEST_ELEMENT PASSING TREE -> RIGHT)

  3) EXIT

*/

node *findLargestElement(node *tree) {
  if((tree == NULL) || (tree->right == NULL)) {
    return tree;
  }
  else {
    return findLargestElement(tree->right);
  }
}


/*

ALGORITHM FOR PREORDER TRAVERSAL:

  1) IF TREE != NULL
  2)      PRINT TREE -> DATA
  3)      RECURSIVELY CALL PREORDER_TRAVERSAL PASSING TREE -> LEFT
  4)      RECURSIVELY CALL PREORDER_TRAVERSAL PASSING TREE -> RIGHT
     [END OF IF]

  5) EXIT

*/

void preorderTraversal(node *tree) {
  if(tree != NULL) {
    cout<<tree->data<<" ";
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
  }
}


/*

ALGORITHM FOR INORDER TRAVERSAL:

  1) IF TREE != NULL
  2)      RECURSIVELY CALL INORDER_TRAVERSAL PASSING TREE -> LEFT
  3)      PRINT TREE -> DATA
  4)      RECURSIVELY CALL INORDER_TRAVERSAL PASSING TREE -> RIGHT
     [END OF IF]

  5) EXIT

*/

void inorderTraversal(node *tree) {
  if(tree != NULL) {
    inorderTraversal(tree->left);
    cout<<tree->data<<" ";
    inorderTraversal(tree->right);
  }
}


/*

ALGORITHM FOR POSTORDER TRAVERSAL:

  1) IF TREE != NULL
  2)      RECURSIVELY CALL POSTORDER_TRAVERSAL PASSING TREE -> LEFT
  3)      RECURSIVELY CALL POSTORDER_TRAVERSAL PASSING TREE -> RIGHT
  4)      PRINT TREE -> DATA
     [END OF IF]

  5) EXIT

*/

void postorderTraversal(node *tree) {
  if(tree != NULL) {
    postorderTraversal(tree->left);
    postorderTraversal(tree->right);
    cout<<tree->data<<" ";
  }
}


/*

ALGORITHM FOR COUNTING THE TOTAL NUMBER OF NODES:

  1) IF TREE = NULL
        RETURN 0

  2) ELSE
        RETURN (RECURSIVE CALL PASSING TREE -> LEFT
                + RECURSIVE CALL PASSING TREE -> RIGHT + 1)

      [END OF IT]

  3) EXIT

*/

int totalNodes(node *tree) {
  if(tree == NULL) {
    return 0;
  }
  else {
    return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
  }
}


/*

ALGORITHM FOR COUNTING THE TOTAL NUMBER OF EXTERNAL NODES:

  1) IF TREE = NULL
        RETURN 0

  2) ELSE IF TREE -> LEFT = NULL && TREE -> RIGHT = NULL
        RETRUN 1

  3) ELSE
        RETRUN (RECURSIVE CALL PASSING TREE -> LEFT
                + RECURSIVE CALL PASSING TREE -> RIGHT)
    [END OF IF]

  4) EXIT

*/

int totalExternalNodes(node *tree) {
  if(tree == NULL) {
    return 0;
  }
  else if(tree->left == NULL && tree->right == NULL) {
    return 1;
  }
  else {
    return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
  }
}


/*

ALGORITHM FOR COUNTING THE TOTAL NUMBER OF INTERNAL NODES:

  1) IF TREE = NULL OR (TREE -> LEFT = NULL && TREE -> RIGHT = NULL)
        RETURN 0

  2) ELSE
        RETRUN (RECURSIVE CALL PASSING TREE -> LEFT
                + RECURSIVE CALL PASSING TREE -> RIGHT + 1)
    [END OF IF]

  3) EXIT

*/

int totalInternalNodes(node *tree) {
  if(tree == NULL || (tree->left == NULL && tree->right == NULL)) {
    return 0;
  }
  else {
    return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
  }
}


// MAIN FUNCTION
int main() {
  // Setting the root node to null, initially
  node *root = NULL;
  node *ptr;

  int option, value;

  do {
    cout<<"\n***** MENU *****\n"
        <<"1. Create\n"
        <<"2. Insert\n"
        <<"3. Search for the smallest element\n"
        <<"4. Search for the largest element\n"
        <<"5. Preorder Traversal\n"
        <<"6. Inorder Traversal\n"
        <<"7. Postorder Traversal\n"
        <<"8. Total number of nodes\n"
        <<"9. Total number of external nodes\n"
        <<"10. Total number of internal nodes\n"
        <<"11. Exit\n";

    cout<<"Enter your option: ";
    cin>>option;

    switch(option) {
      case 1: root = create(root);
              break;

      case 2: cout<<"Enter the value to be inserted: ";
              cin>>value;

              root = insert(root, value);
              break;

      case 3: ptr = findSmallestElement(root);
              cout<<"The smallest element is "<<ptr->data<<endl;
              break;

      case 4: ptr = findLargestElement(root);
              cout<<"The largest element is "<<ptr->data<<endl;
              break;

      case 5: preorderTraversal(root);
              cout<<endl;
              break;

      case 6: inorderTraversal(root);
              cout<<endl;
              break;

      case 7: postorderTraversal(root);
              cout<<endl;
              break;

      case 8: value = totalNodes(root);
              cout<<"The total number of nodes are "<<value<<endl;
              break;

      case 9: value = totalExternalNodes(root);
              cout<<"The total number of external nodes are "<<value<<endl;
              break;

      case 10: value = totalInternalNodes(root);
               cout<<"The total number of internal nodes are "<<value<<endl;
               break;

      case 11: break;

      default: cout<<"Wrong option !\n";
              break;
    }
  } while(option != 11);

  if(option == 11) {
    // Freeing the space for root, after execution of the program
    delete root;

    cout<< "\nTHANK YOU for using the program !\n"
        <<"Have a good day.\n\n";
  }
}
