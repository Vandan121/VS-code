// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
long rec(vector<vector<int>>&mat,vector<vector<int>>&dp,int i,int j,int value){
    long n=mat.size(),m=mat[0].size();
    if(i==n || j==-1 || j==m || mat[i][j]==-1) return value;
    if(dp[i][j] != -1) return dp[i][j];
    long a=rec(mat,dp,i+1,j,0);
    long b=rec(mat,dp,i+1,j-1,0);
    long c=rec(mat,dp,i+1,j+1,0);
    dp[i][j] = max(mat[i][j]+a,max(mat[i][j]+b,mat[i][j]+c));
    return value + dp[i][j];
}
long MaxGold(vector<vector<int>>&mat){
    // Code here
    long n=mat.size(),m=mat[0].size(),ans=INT_MIN;
    vector<vector<int>> dp(n,vector<int> (m,-1));
    for(int i=0;i<m;i++){
        if(mat[0][i]!=-1){
            ans = max(ans,rec(mat,dp,0,i,0));
        }
    }
    return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends