// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string moveRobots(string s1, string s2){
        // code here 
        int n=s1.length();
        char a[n];
        int pos[n],cur=0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!='#')
            {
                a[cur]=s1[i];
                pos[cur]=i;
                cur++;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s2[i]!='#' && s2[i] == a[cur-1])
            {
                if(s2[i] == 'A' && i<=pos[cur-1]) {cur--;continue;}
                else if(s2[i] == 'B' && i>=pos[cur-1]) {cur--;continue;}
                else return "No";
            }
            else if(s2[i]!='#' && s2[i] != a[cur-1]) return "No";
        }
        return "Yes";
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends