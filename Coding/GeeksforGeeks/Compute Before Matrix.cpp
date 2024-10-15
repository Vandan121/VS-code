// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int n, int m, vector<vector<int>> after){
        // Code here
        vector<vector<int>> ans(n,vector<int> (m,0));
        int res=0;
        for(int j=0;j<m;j++)
        {
            ans[0][j] = after[0][j] - res;
            res += ans[0][j];
        }
        res=ans[0][0];
        for(int i=1;i<n;i++)
        {
            ans[i][0] = after[i][0] - res;
            res += ans[i][0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                ans[i][j] = after[i][j] - after[i-1][j] - after[i][j-1] + after[i-1][j-1];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M; 
        vector<vector<int>> after(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>after[i][j];
            }
        } 
        Solution obj;
        vector<vector<int>> before=obj.computeBeforeMatrix(N,M,after); 
        for(int i=0;i<before.size();i++){
            for(int j=0;j<before[i].size();j++){
                cout<<before[i][j]<<' ';
            } 
            cout<<endl;
        }
    }
}  // } Driver Code Ends