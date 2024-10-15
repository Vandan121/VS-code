#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int binarysearch(int arr[],int k,int left,int right)
{
    if(k<=arr[left])
    {
        return arr[left];
        
    }
    if(k>=arr[right])
    {
        return arr[right];
    }
    int mid = (left+right)/2;     
    if(abs(k-arr[mid])<abs(k-arr[mid+1]))
    {
        return binarysearch(arr,k,left,mid);
    }
    else if(abs(k-arr[mid])>abs(k-arr[mid+1]))
    {
        return binarysearch(arr,k,mid+1,right);
    }
    else
    {
        return arr[mid+1];
    }
    return -1;
}

int main() {
    int n,k;
    cin>>n>>k;
    if(n==0)
    {
        cout<<"FAIL"<<endl;
        return 0;
    }
    int arr[n];
    cin>>arr[0];
    for(int i=1;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]<arr[i-1])
        {
            cout<<"FAIL"<<endl;
            return 0;
        }
    }
    if(n==1)
    {
        cout<<arr[0]<<endl;
        return 0;
    }
    cout<<binarysearch(arr,k,0,n-1);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
