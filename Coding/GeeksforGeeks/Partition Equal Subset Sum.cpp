// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<n;i++) sum+=arr[i];
        if(sum%2) return 0;
        sum /= 2;
        vector<vector<int>> ans(n+1,vector<int> (sum+1,1));
        for(int i=0;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(i==0) ans[i][j] = 0;
                else{
                    if(arr[i-1] > j) ans[i][j] = ans[i-1][j];
                    else{
                        ans[i][j] = ans[i-1][j] || ans[i-1][j-arr[i-1]];
                    }
                }
            }
        }
        return ans[n][sum];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends