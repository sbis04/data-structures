#include <bits/stdc++.h>
using namespace std;

/*Trie data structure allows for optimized searching of words in a dictionary
Searching time: O(N), where N = number of characters present in the word.
Creation of trie - preprocessing - done only once
in Brute Force, you would need to iterate the whole array and compare each string element of array to search key - Very Time Consuming !
*/

class Node{
    public:
    bool isTerminal; //the node bearing last character of a word will be the terminal node
    Node* child[26]; //26 children because there are 26 alphabets, and each index corresponds to an alphabet

    Node(){
        isTerminal = false;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

void add(string word, Node* trie){
    int word_size = word.size();
    for(int i=0;i<word_size;i++) //iterating through every character in the word
    {
        if(trie->child[word[i]-'A'] == NULL)
        {
            trie->child[word[i]-'A'] = new Node();
        }
        trie = trie->child[word[i]-'A'];
    }

    trie->isTerminal = true;  //because the last character of every word is a terminal node
}

bool search(string word, Node* trie){
    int word_size = word.size();
    int i;
    bool hitTerminal = false;
    for(i=0;i<word_size;i++)
    {
        if(trie->child[word[i]-'A'] == NULL)
        {
            return false;
        }
        else{
            trie = trie->child[word[i]-'A'];
        }
    }

    if(trie->isTerminal == true) //check if last character is terminal node or not
    {
        return true;
    }
}


int main() {
    vector<string> dict;
    dict.push_back("ARE");
    dict.push_back("AS");
    dict.push_back("DO");
    dict.push_back("DOT");
    dict.push_back("NEW");
    dict.push_back("NEWS");
    dict.push_back("NO");
    dict.push_back("NOT");
    dict.push_back("RONITT");
    dict.push_back("RON");

    Node* root = new Node();
    for(int i=0;i<dict.size();i++){
        add(dict[i] , root);
    }

    cout<<search("ARE" , root)<<endl;
    cout<<search("NO" , root)<<endl;
    cout<<search("NEWS" , root)<<endl;
    cout<<search("WIN" , root)<<endl;
    cout<<search("ABC" , root)<<endl;
    cout<<search("AER" , root)<<endl;
    cout<<search("XYZ" , root)<<endl;
    cout<<search("RONITT", root)<<endl;
    cout<<search("RON", root)<<endl;
    cout<<search("RONIT", root)<<endl;


	return 0;
}
