// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int kthDiff(int a[], int n, int k);

// Driver code
int main() {
    int t, i;
    int k;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;

        cout << kthDiff(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends


int countpairs(int a[],int n,int mid)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans += upper_bound(a,a+n,a[i]+mid)-(a+i+1);
    }
    return ans;
}
int kthDiff(int a[], int n, int k)
{
    sort(a,a+n);
    int low=INT_MAX;
    for(int i=1;i<n;i++) low = min(low,a[i]-a[i-1]);
    int high= a[n-1]-a[0];
    while(low<high)
    {
        int mid =(low+high)/2;
        if(countpairs(a,n,mid)<k)
        low = mid +1;
        else 
        high = mid;
    }
    return low;
}
