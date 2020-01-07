#include<iostream>

using namespace std;

void plot(int ar[], int n)
{
    int highest=0;
    for(int i=0; i<n; i++)
    {
        if(ar[i]>highest)
            highest=ar[i];
    }
    cout<<endl;
    for(int c=highest;c> 0;c--)
    {
        if(highest<10)
        {
            cout<<"\t\t";
            cout<<" "<<highest<<"-|";
            cout<<"\t";
        }
        else
        {
            cout<<"\t\t";
            cout<<highest<<"-|";
            cout<<"\t";
        }

        for(int r=0;r<n;r++)
        {
            if(ar[r]<highest)
                cout<<"\t";
            if(ar[r]>=highest)
                cout<<"|##|\t";
        }

        highest--;
        cout<<endl;
    }
    cout<<"\t\t___|_________";
    for(int k=n;k>0;k--)
        cout<<"________";
    cout<<endl;
    cout<<"\t\t\t ";
    for(int k=0;k<n;k++)
        cout<<k+1<<"       ";
    cout<<"\n\n";
}

int main()
{

    cout<<"Enter the total no. of data entries : ";
    int n;
    cin>>n;
    int ar[n];

    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter the value of no."<<i+1<<" element : ";
        cin>>ar[i];

    }
    plot(ar,n);
}
