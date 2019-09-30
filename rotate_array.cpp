#include <bits/stdc++.h> 
using namespace std; 

void leftRotatebyOne(int arr[], int n) 
{ 
	int temp = arr[0], i; 
	for (i = 0; i < n - 1; i++) 
		arr[i] = arr[i + 1]; 

	arr[i] = temp; 
} 


void leftRotate(int arr[], int d, int n) 
{ 
	for (int i = 0; i < d; i++) 
		leftRotatebyOne(arr, n); 
} 

void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

int main() 
{ 
	int size,i;
	cout<<"Enter size of array:";
	cin>>size;
	int arr[size];
	cout<<"Enter the array elements:";
    for( i=0;i<size;i++){
        cin>>arr[i];
    }


	// Function calling 
	leftRotate(arr, 2, size); 
	printArray(arr, size); 

	return 0; 
} 
