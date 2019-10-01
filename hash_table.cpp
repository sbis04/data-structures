// Author: Proma Roy
// GITHUB: https://github.com/promaroy

// hash table implementation for finding the frequency of each character in a string...

#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s="hacktoberfest";//string
  int hash[26]={0};// initializing hash table to store the frequency of each character..

  for(int i=0;i<s.length();i++)// looping through the string..
  {
    hash[s[i]-'a']++; // frequency of "a" stored at hash[0], frequency of "b" stored at hash[1] and so on..
  }
  for(int i=0;i<26;i++)
  {
    if(hash[i]!=0)
    {
      cout<<"Frequency of "<<char(i+'a')<<"- "<<hash[i]<<endl;
    }
  }

}
