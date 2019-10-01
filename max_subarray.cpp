/* find the maximum of subarray */

#include<bits/stdc++.h>
using namespace std;

unsigned long long maximum(unsigned long long arr[], unsigned long long n,unsigned long long k){
	unsigned long long max=0;
	for(unsigned long long i=0;i<k;i++){
		if(max<arr[i])
			max=arr[i];
	}
	return max;
}

int main(){
	unsigned long long t,n,k,i,max,pos;
	cin>>t;
	while(t--){
		cin>>n>>k;
		unsigned long long arr[n];
		max=0;
		for(i=0;i<n;i++)
			cin>>arr[i];
		
		for(unsigned long long i=0;i<k;i++){
			if(max<arr[i]){
				max=arr[i];
				pos=i;
			}
		}
		cout<<max<<" ";
		
		for(i=1;i<n-k+1;i++){
			if(pos>=i){
				if(max<arr[i+k-1]){
					max=arr[i+k-1];
					pos=i+k-1;
				}
				cout<<max<<" ";
			}
			else if(pos<i){
				unsigned long long newmax=0;
				for(unsigned long long j=i;j<i+k;j++){
					if(newmax<arr[j]){
						newmax=arr[j];
						pos=j;
					}
				}
				max=newmax;
				cout<<max<<" ";
			}
		}
		cout<<endl;

	}

}