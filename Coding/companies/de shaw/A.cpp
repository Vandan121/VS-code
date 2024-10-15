/* Dynamic Programming implementation 
of Maximum Sum Increasing Subsequence 
(MSIS) problem */
#include <bits/stdc++.h> 
using namespace std; 

/* maxSumIS() returns the maximum 
sum of increasing subsequence 
in arr[] of size n */
int func(vector<int> heights) 
{ 
    int n = heights.size();
	vector<int> sum(n); 
    reverse(heights.begin(),heights.end());
	for (int i = 0; i < n; i++ ) 
		sum[i] = heights[i]; 
	for (int i = 1; i < n; i++ ){
		for (int j = 0; j < i; j++ ){
			if (heights[i] > heights[j] ) {
                if(sum[i] < sum[j] + heights[i]){
                    sum[i] = sum[j] + heights[i]; 
                }
            }
        } 
    } 
    int ans = 0;
	for (int i = 0; i < n; i++ ){
		ans = max(ans,sum[i]); 
    } 
	return ans; 
} 

// Driver Code 
int main() 
{ 
	int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
	cout << func( arr) << endl; 
	return 0; 
} 

// This is code is contributed by rathbhupendra 
