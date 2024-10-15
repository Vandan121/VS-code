// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int n=s.length();
        int start=0;
        int length=1;
            for(int i=0;i<n;i++)
            {
                for(int j=n-1;j>=i;j--)
                {
                    if(s[i]==s[j])
                    {
                        int temp_i=i;
                        int temp_j=j;
                        while(temp_i<temp_j)
                        {
                            if(s[temp_i]!=s[temp_j]) break;
                            temp_i++;
                            temp_j--;
                        }
                        if((temp_i>=temp_j) && j-i+1 > length)
                        {
                            start=i;
                            length=j-i+1;
                            break;
                        }
                    }
                }
            }
            return s.substr(start,length);

        // code here
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends