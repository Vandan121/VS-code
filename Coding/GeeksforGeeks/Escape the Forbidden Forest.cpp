// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends
class Solution
{
    public:
    int build_bridges(string s1, string s2)
    {
        // code here
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>> matrix(n2+1,vector<int> (n1+1,0));
        for(int i=1;i<=n2;i++)
        {
            for(int j=1;j<=n1;j++)
            {
                
                if(s2[i-1]==s1[j-1])
                {
                    matrix[i][j] = 1+matrix[i-1][j-1];
                }
                else 
                {
                    matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
                }
            }
        }
        return matrix[n2][n1];
    }
};

// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends