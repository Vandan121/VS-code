// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        int x=0,y=0,z=0,i,j,k,l,res=100005,c=1;
       for(i=0; i<s.size(); i++){
           if(s[i]=='0'){
               x=1;
               j=i;
           }
           if(s[i]=='1'){
               y=1;
               k=i;
           }
           if(s[i]=='2'){
               z=1;
               l=i;
           }
           if(x and y and z){
               c=0;
               res=min(res,max({j,k,l})-min({j,k,l})+1);
           }
       }
       
       if(c)return -1;
       else return res;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends