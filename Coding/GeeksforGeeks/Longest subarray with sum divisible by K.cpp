// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
        map<int,int> m;
        m[0] = 0;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            int mod =(sum)%k;
            if(mod == 0){
                ans = max(ans,i+1);
            }
            else{
                if(m[mod]==0){
                    m[mod] = i+1;
                }
                else{
                    ans = max(ans,i+1-m[mod]);
                }
            }
        }
        return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends