#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i][i];
    }
    for(int i=0;i<n;i++)
    {
        sum+=arr[i][n-1-i];
    }
    cout<<abs(sum1-sum2);
}