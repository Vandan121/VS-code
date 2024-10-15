// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        //code here.
        int n=s.length(),flag=0;
        string s1="";
        int i=0;
        while(i<n)
        {
            flag=0;
            for(;s[i]!='.' && i<n;i++)
            {
                if(s[i]!='0' && !flag)
                {
                    flag=1;
                }
                if(flag)
                {
                    s1.push_back(s[i]);
                }
            }
            if(!flag)
            {
                s1.push_back('0');
            }
            if(i<n)
            {
                s1.push_back(s[i++]);
            }
        }
        return s1;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends