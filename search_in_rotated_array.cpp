#include <iostream>
using namespace std;
int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0){
            return -1;
        }
        int l=0,h=n-1;
        while(l<h){
            int mid=(l+h)/2;
            if(nums[mid]>nums[h]){
                l=mid+1;
            }
            else{
                h=mid;
            }
        }
        int start=l;
        cout<<start;
        if(nums[n-1]>=target){
            l=start;
            h=n-1;
        }
        else{
            l=0;
            h=start-1;
        }
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return -1;
    }