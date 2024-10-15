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
#define mod pow(2,31)
using namespace std;


int main()
{
    fast
    ll n,s,p,q;
    cin>>n>>s>>p>>q;
    vector<<ll> a;
    a.pb(S%mod);
    for i = 1 to N-1
        a.pb((a[i-1]*P+Q)%mod);
    sort(all(a));
    ll count =0;
    loop(i,0,a.size()-1)
    {
        if(a[i] != a[i+1])
        count++;
    }
    cout<<count;
    return 0;
}