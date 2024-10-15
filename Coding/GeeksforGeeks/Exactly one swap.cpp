// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string s)
    {
        // code here
        vector<int> freq(26,0);
        int n=s.length();
        int flag=1;
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }
        long long ans=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>=2 && flag)
            {
                ans++;
                flag=0;
            }
            for(int j=i+1;j<26;j++)
            {
                ans += 1LL*freq[i]*freq[j];
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends
