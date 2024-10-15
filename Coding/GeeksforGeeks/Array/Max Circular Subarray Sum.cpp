#include<bits/stdc++.h>
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define out(i,a,n) for(ll i=0;i<n;++i) cout<<a[i]<<" ";
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define l(a) a.length()
using namespace std;


int main()
{
    int num;
    cin>>num;
    int arr[num];
    in(arr,num);
    int cursum=0,sum=0;
    int min = arr[0];
    int maxsum = -1*arr[0];
    for(int i=0;i<num;i++)
    {
        sum += arr[i];
        if(arr[i]>min)min=arr[i];
        cursum = cursum + -1*arr[i];
        if(cursum>maxsum) maxsum = cursum;
        if(cursum<0) cursum =0;
    }
    int final = sum+maxsum;
     cout<<"sum :"<<sum<<endl;
     cout<<"maxsum :"<<maxsum<<endl;
    // if(final==0)
    // return min;
    cursum=0;
    maxsum = arr[0];
    for(int i=0;i<num;i++)
    {
        cursum = cursum + arr[i];
        if(cursum>maxsum) maxsum = cursum;
        if(cursum<0) cursum =0;
    }
    cout<<"sum :"<<sum<<endl;
    cout<<"final :"<<final<<endl;
    cout<<"maxsum :"<<maxsum<<endl;
    cout<<max(final,maxsum);
    fast
    return 0;
}