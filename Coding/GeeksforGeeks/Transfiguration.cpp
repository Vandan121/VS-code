// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
        if(A.length() != B.length()) return -1;
        int n=A.length();
        int i=n-1,j=n-1,count=0;
        vector<int> a(n),b(n);
        for(int ii=0;ii<n;ii++)
        {
            a.push_back(A[ii]);
            b.push_back(B[ii]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a != b) return -1;        
        while(i>=0)
        {
            if(A[i] != B[j]) 
            {
                i-=2;
                count++;
            }
            else i--;
            j--;
        }
        return count;
    	// Your code goes here
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends