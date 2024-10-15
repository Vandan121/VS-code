#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,k,n;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int arr[n]; 
        for(int i=0;i<n;i++) cin>>arr[i];
        int max=arr[0];
        for(int i=0;i<k;i++)
        {
            if(arr[i]>max) max = arr[i];
        }
        cout<<max<<" ";
        for(int i=k;i<n;i++)
        {
            if(arr[i]>max) max = arr[i];
            cout<<max<<" ";
        }
    }
    return 0;
}