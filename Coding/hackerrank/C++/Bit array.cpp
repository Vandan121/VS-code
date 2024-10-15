#include<bits/stdc++.h>
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define out(i,a,n) for(ll i=0;i<n;++i) cout<<a[i]<<" ";
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define dis(v) for(auto i:v)cout<<i<<" "<<endl;cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define l(a) a.length();
using namespace std;


int main()
{
    fast
    ll n,s,p,q,temp;
    ll mod = pow(2,31);
    cin>>n>>s>>p>>q;
    map<ll,ll> m;
    vector<ll> a;
    temp=(s%mod);
    m[temp]++;
    loop(i,1,n)
        m[((temp*p+q)%mod)]++, temp=((temp*p+q)%mod);
    cout<<m.size();
    // dis(a);
    // ll count =1;
    // loop(i,0,a.size()-1)
    // {
    //     if(a[i] != a[i+1])
    //     count++;
    // }
    //cout<<count;
    return 0;
}