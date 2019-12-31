#include<iostream>
using namespace std;
void bubblesort(int*,int);
void swaps(int*,int*);
int main()
{
int n;
cout<<"\nenter the number of  elements\n";
cin>>n;
int arr[n];
cout<<"\nenter the values:\n";
for(int i=0;i<n;i++)
cin >> arr[i];
bubblesort(arr,n);
cout<<"\nthe sorted array is:\n";
for(int i=0;i<n;i++)
cout<<arr[i]<<" ";
cout<<"\n";
}

void bubblesort(int*arr,int n)
{

for(int rounds=0;rounds<n-1;rounds++) // n-rounds-2=0 rounds=n-2
for(int i=0;i<n-rounds-1;i++)
{
    if(arr[i]>arr[i+1]) swaps(&arr[i],&arr[i+1]);
}



}


void swaps(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}



/*

8 6 10 5 7 9 11
6 8 5 7 9 10 11
6 5 7 8 9 10 11
5 6 7 8 9 10 11

*/
