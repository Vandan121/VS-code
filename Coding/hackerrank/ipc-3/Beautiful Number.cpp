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
    {
    fast
    vector<string> v(1e6+5);
    loop(i,1,1e6+5) v[i] = bitset<32>(i).to_string();
    vector<ll> ans(1e6+5,0);
    loop(i,1,1e6+5){
        ll cnt = count(all(v[i]),'1');
        if(!(cnt&1))    ans[i]+=ans[i-1]+1;
        else ans[i]=ans[i-1];
    }
    ll t;   cin>>t;
    while(t--){
        ll a,b; cin>>a>>b;
        ll ans1 = ans[b]-ans[a];
        ll cnt = count(all(v[a]),'1');
        if(!(cnt&1))    ans1++;
        if(a > b)   cout<<0<<endl;
        else cout<<ans1<<endl;
    }
    return 0;
}
}