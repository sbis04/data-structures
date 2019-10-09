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
#include <vector>
#include <cstring>
using namespace std;

#define STARTING_SIZE 101 // The initial size of the hash table
#define EXPAND_FACTOR 0.7 // The factor to indicates when it's time to expand the hash table
// The two defines above are used to have a more static hash table which also allows more optimization

// Base class to create the Hash Table
class HashTable {
  public:
  HashTable() {
    this->elements = 0;
    this->table_size = STARTING_SIZE;
    this->hash_table = new int[STARTING_SIZE];
    memset(this->hash_table, 0, sizeof(int) * STARTING_SIZE);
  }
  ~HashTable() {
    if (this->hash_table) {
      delete[] this->hash_table;
    }
  }
  void insert(int value) {
    int position = this->find_position(value);
    if (position == -1) {
        cout<<"The table is full and can't be expanded !"<<endl;
        return;
    }
    if (this->hash_table[position] != value) {
      // The position returned is a empty slot
      this->hash_table[position] = value;
      this->elements++;
    }
    // Verify if it's time to expand the hash_table yet
    if((float)(this->elements/this->table_size) > EXPAND_FACTOR) {
        this->expand();
    }
  }
  bool find(int value) {
      int position = this->find_position(value);
      if (position == -1) { //Value not present and table is full
          return false;
      }
      if (this->hash_table[position] == value) { //Value present
          return true;
      }
      return false; //Value not present and table has space
  }
  bool del(int value) {
    int position = this->find_position(value);
    if (this->hash_table[position] == value) {
      // Element found on the position, so let's remove it and decrease the counter
      this->hash_table[position] = 0;
      this->elements--;
      //Resizing and rehashing is expensive, that's why we will not resize it if we are removing elements
      return true;
    }
    return false;
  }
  void display() {  // to display the hashtable contents
    for(int i = 0; i < this->table_size; i++) {
      if (hash_table[i] != 0) {
        cout<<hash_table[i]<<" ";
      }
    }
    cout<<endl;
  }
  private:
  int elements; //Current number of elements on the hash_table
  int table_size; //Current table size
  int *hash_table; //Using vector allows the use of the .resize()

  // This is the main function for a hash table, it's responsible for generating the hash for the value;
  // For easy understading of the process the hash function will be very simple, which also means
  // it would be weak and easy to collide
  // Hash Function 
  int hash(int value) {
      return (value % this->table_size);
  }

  // This function returns the position of a value or the first empty slot starting from the
  // hash of the value or -1 if the value is not present and the table is full
  int find_position(int value) {
    int hash = this->hash(value);
    // Search the inputed value starting from hash position
    for(int i = 0; i < this->table_size; i++) {
        if (this->hash_table[hash] == value) {
            return hash;
        }
        if (this->hash_table[hash] == 0) {
            return hash;
        }
        if (hash++ == this->table_size) {
            hash = 0;
        }
    }
    return -1;
  }

  // This function expands(double its size) the hash table
  void expand() {
      // Creates a new table
      int *new_table = new int[this->table_size * 2];
      if (!new_table) {
        cout<<"The can't be expanded !"<<endl;
        return;
      }
      // Swap the tables
      int *old_table = this->hash_table;
      int old_table_size = this->table_size;
      this->hash_table = new_table;
      this->table_size = this->table_size * 2;
      memset(this->hash_table, 0, sizeof(int) * STARTING_SIZE);  // inserting default value 0 to hash table
      // Insert all values again, now the position(hash) could have changed because of the new table size
      for(int i = 0; i < old_table_size; i++) {
        if (old_table[i] != 0) {
          this->insert(old_table[i]);
        }
      }
      delete[] old_table;
  }
};


// Main Function
int main() {
  int option, value;
  HashTable hashtable;

  do {
    cout<<"\n**** MENU ****\n"
        <<"1. Insert\n"
        <<"2. Search\n"
        <<"3. Delete\n"
        <<"4. Display\n"
        <<"5. Exit\n";

    cout<<"Enter your option: ";
    cin>>option;

    switch(option) {
      case 1: cout<<"Enter the value to be inserted: ";
              cin>>value;

              hashtable.insert(value);
              break;

      case 2: cout<<"Enter the value to be searched: ";
              cin>>value;

              if(hashtable.find(value)) {
                cout<<"The element was found !"<<endl;
              } else {
                cout<<"The element was not found !"<<endl;
              }
              break;

      case 3: cout<<"Enter the value to be deleted: ";
              cin>>value;
              if(hashtable.del(value)) {
                cout<<"The deleted was deleted !"<<endl;
              } else {
                cout<<"The element was not found !"<<endl;
              }
              break;

      case 4: hashtable.display();
              break;

      case 5: break;

      default: cout<<"Wrong option !\n";
               break;
    }
  } while(option != 5);

  if(option == 5) {
    cout<< "\nTHANK YOU for using the program !\n"
        <<"Have a good day.\n\n";
  }
}
