// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
        int n=N;
        double ans=0,same=0;
        for(int i=0;i<n;i++)
        {
            map<double,int> m;
            same=0;
            for(int j=0;j<n;j++)
            {
                if(arr[i].first == arr[j].first && arr[i].second==arr[j].second)
                {
                    same++;
                    continue;
                }
                double x,y;
                y = arr[j].second-arr[i].second;
                x = arr[j].first-arr[i].first;
                double slope = y/x;
                m[slope]++;
            }
            for(auto i : m)
            {
                ans = max(ans,i.second+same);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends