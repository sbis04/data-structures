// fractional knapsack problem
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
struct item
{
    int value;
    int weight;
    /*
    It can't be used as we are not passing the arguments at the time of creation of array
    item(int value,int weight):value(value),weight(weight)
    {};*/
};
bool comp(const item &a,const item &b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}
long double solve(item arr[],ll W,ll N)
{
    sort(arr,arr+N,comp);
    ll weight=0; // weight of knapsack
    ll value=0; // value of knapsack
    for(int i=0;i<N;++i)
    {
        if(arr[i].weight+weight<=W)
        {
            value+=arr[i].value;
            weight+=arr[i].weight;
        }
        else
        {
            value+=(W-weight)*double(arr[i].value)/arr[i].weight;
            break;
        }
    }
    return value;
}
int main()
{
    ll W,N;
    cout << "Enter the weight of Knapsack:";
    cin >> W;
    cout <<  "Enter number of items:";
    cin >> N;
    item arr[N];
    for(int i=0;i<N;++i)
    {
        int val,wei;
        cout << "Enter  value and weight of item separated by space:";
        cin >> val >> wei;
        arr[i]={val,wei};
    }
    cout << solve(arr,W,N) << endl;
}
