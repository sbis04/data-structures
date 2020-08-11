#include<bits/stdc++.h>
using namespace std;

class Trie{
private:
        Trie *children[26];
        bool isEndOfWord;
public : 
        // constructor intilaization with a Trie size ( 26 chars for every node )
        Trie(){
          isEndOfWord=false;
          for(int i=0;i<26;i++){
          children[i]=nullptr;
          }
        }
        
        // inserting into the trie
        void insert(string word){
        // to get the current Trie instance  of the class,let us use the 'this' keyword
        Trie *curr=this;
        for(char c:word){
          if(!curr->children[c-'a']){
           curr->children[c-'a']=new Trie();
          }
          curr=curr->children[c-'a'];
        }
        isEndOfWord=true;
        }
        
        // searching in the trie
        bool isPresent(string word){
        Trie *curr=this;
        for(char c:word){
        curr=curr->children[c-'a'];
        if(!curr) return false;
        }
        if(!isEndOfWord) return false;
        return true;
        }
        
        // prefix matching
        bool isPrefix(string word){
        Trie *curr=this;
        for(char c:word){
            curr=curr->children[c-'a'];
            if(!curr) return false;
        }
        return true;
        }
};
int main(){
Trie *root=new Trie();
root->insert("giri");
root->insert("giriteja");
root->insert("giole");
root->insert("sel");
root->insert("selenagomez");
root->insert("gomez");
cout<<root->isPresent("giri")<<endl;
cout<<root->isPresent("teja")<<endl;
cout<<root->isPresent("selenagomez")<<endl;
cout<<root->isPresent("Selenagomez")<<endl;
cout<<root->isPrefix("sel")<<endl;
cout<<root->isPrefix("gomez")<<endl;
cout<<root->isPrefix("justinbieber")<<endl;
return 0;
}
