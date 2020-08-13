#include <iostream>
using namespace std;
int myAtoi(string str) {
        int n=str.size();
        int i=0;
        while(i<n && str[i]==' '){
            i++;
        }
        if(i==n){
            return 0;
        }
        int sign=1;
        if(str[i]=='-'){
            sign=-1;
            i++;
        }
        else if(str[i]=='+'){
            i++;
        }
        if(i==n || !(str[i]>='0' && str[i]<='9')){
            return 0;
        }
        long long ans=0;
        for(i;i<n;i++){
            if(str[i]>='0' && str[i]<='9'){
                if(sign==1){
                    if(INT_MAX/10<ans){
                        return INT_MAX;
                    }
                    if(INT_MAX/10==ans && str[i]>'7'){
                        return INT_MAX;
                    }
                }
                if(sign==-1){
                    if(INT_MAX/10<ans){
                        return INT_MIN;
                    }
                    if(INT_MAX/10==ans && str[i]>'8'){
                        return INT_MIN;
                    }
                }
                ans*=10;
                ans+=str[i]-'0';
            }
            else{
                break;
            }
        }
        return sign*ans;
    }