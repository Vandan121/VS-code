//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    class Trie{
        public:
        class node{
            public:
            node* next[26];
            int count;
            node(){
                count = 0;
                for(int i=0;i<26;i++) next[i] = NULL;
            }
        };
        node* root;
        Trie(){
            root = new node();
        }
        void insert(string &s){
            int n = s.length();
            auto it = root;
            for(int i=0;i<n;i++){
                if(it->next[s[i]-'a']==NULL){
                    it->next[s[i]-'a'] = new node();
                }
                it = it->next[s[i]-'a'];
                it->count++;
            }
        }
        string prefix(string &s){
            auto it = root;
            int n = s.length();
            string ans = "";
            for(int i=0;i<n;i++){
                ans += s[i];
                it = it->next[s[i]-'a'];
                if(it->count == 1){
                    break;
                }
            }
            return ans;
        }
    };
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        Trie* root = new Trie();
        for(int i=0;i<n;i++){
            root->insert(arr[i]);
        }
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = root->prefix(arr[i]);
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends