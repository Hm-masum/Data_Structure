#include <bits/stdc++.h>
using namespace std;

/*
//...01...insert the number in a array
int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    int k,val;
    cout<<"Enter the position for insert : ";
    cin>>k;
    cout<<"Enter the value for insert : ";
    cin>>val;

    for(int i=n;i>=k;i--)
    {
        arr[i+1]=arr[i];
        if(i==k)
        {
            arr[i]=val;
        }
    }

    for(int i=1;i<=n+1;i++)
    {
        cout<<arr[i]<<" ";
    }
}

//...02...Delete a number in a array
int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    int k;
    cout<<"Enter the position for insert : ";
    cin>>k;

    for(int i=k;i<n;i++)
    {
        arr[i]=arr[i+1];
    }

    for(int i=1;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

//...03...Bubble sort
int main()
{
    int n;
    cin>>n;
    int arr[n+3];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
           if(arr[j]>arr[j+1])
           {
               swap(arr[j],arr[j+1]);
           }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
*/
//...04...Binary search
int main()
{
    int n;
    cin>>n;
    int arr[n+3];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    int num;
    cout<<"Enter Your Number : ";
    cin>>num;

    int lb=0;
    int rb=n;
    int mid=(lb+rb)/2;

    int cnt=0;
    while(lb<=rb)
    {
        if(num>arr[mid]){
            lb=mid+1;
        }
        else if(num<arr[mid]){
            rb=mid-1;
        }
        else if(num==arr[mid]){
            cnt=1;
            break;
        }
        mid=(lb+rb)/2;
    }

    if(cnt==1)
    {
        cout<<num<<" was found ";
    }
    else
        cout<<num<<" was not found ";

}

