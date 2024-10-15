#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int binarysearch(vector<int> arr,int k,int left,int right)
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
    if(abs(k-arr[mid]) == abs(k-arr[mid+1]))
    {
        return arr[mid+1];
    }
    else if(abs(k-arr[mid])<abs(k-arr[mid+1]))
    {
        return binarysearch(arr,k,left,mid);
    }
    else if(abs(k-arr[mid])>abs(k-arr[mid+1]))
    {
        return binarysearch(arr,k,mid+1,right);
    }
}

int main() {
    int n,k,i,j,temp;
    cin>>n>>k;
    if(n==0)
    {
        cout<<"FAIL"<<endl;
        return 0;
    }
    vector<int> arr,arr1; //4 7 10 | 1 2 3
    cin>>temp;
    arr.push_back(temp);
    for(i=1;i<n;i++)
    {
        cin>>temp;
        if(temp<arr[i-1])
        {
            break;
        }
        arr.push_back(temp);
    }    
    if(i!=n)
    {
        arr1.push_back(temp);
    for(j=1;j<n-i;j++)
    {
        cin>>temp;
        if(temp<arr1[j-1])
        {
            cout<<"FAIL"<<endl;
            return 0;
        }
        arr1.push_back(temp);
    }
    }
    if(n==1)
    {
    cout<<arr[0]<<endl;
        return 0;
    }
        vector<int> final;
    int k1 = binarysearch(arr,k,0,arr.size()-1);
    int k2=0;
    if(arr1.size() != 0)
    {
        k2 = binarysearch(arr1,k,0,arr1.size()-1);
        final.push_back(k2);
    }
    final.push_back(k1);
    
    cout<<binarysearch(final,k,0,final.size()-1);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
