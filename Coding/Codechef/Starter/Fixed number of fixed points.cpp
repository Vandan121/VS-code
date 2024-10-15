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

void fnofp(int x,int y)
{
    if(x-y == 1)
    {
        cout<<"-1"<<endl;
        return;
    }
    else
    {
        loop(i,1,y+1)
        {
            cout<<i<<" ";
        }
        if(y != x)
        cout<<x<<" ";
        loop(i,y+1,x)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
} 

int main()
{
    fast
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        fnofp(x,y);
    }
    return 0;
}