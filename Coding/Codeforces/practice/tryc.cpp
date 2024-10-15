#include<bits/stdc++.h>
#define ll long long int
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define vl vector<ll>
#define vs vector<string>
#define v2d vector<vector<ll>>
#define pii pair<ll,ll>
#define vpi vector<pii>
#define dl deque<ll>
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL));
#define l(a) a.length()
#define fr first
#define sc second
#define mod7 1000000007
#define mod9 1000000009
#define mod1 998244353
#define endl '\n'
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define testcase int t; cin >> t; while(t--){dfunc();}
using namespace std;
#define p(n) cout<<n<<endl;
ll add7(ll x,ll y)  {ll ans = x+y; return (ans>=mod7 ? ans - mod7 : ans);}
ll sub7(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod7 : ans);}
ll mul7(ll x,ll y)  {ll ans = x*y; return (ans>=mod7 ? ans % mod7 : ans);}
ll add9(ll x,ll y)  {ll ans = x+y; return (ans>=mod9 ? ans - mod9 : ans);}
ll sub9(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod9 : ans);}
ll mul9(ll x,ll y)  {ll ans = x*y; return (ans>=mod9 ? ans % mod9 : ans);}
ll binaryMultiply(ll a, ll b,ll M=mod7){ll ans = 0;while (b) {if (b & 1){ans = (ans + a) % M;}a = (a + a) % M;b >>= 1;} return ans;}
ll binaryExponentiation(ll a, ll b,ll M=mod7){a %= M;ll ans = 1;while (b){if (b & 1){if(M>mod7) ans = binaryMultiply(ans, a);else ans = (ans * 1LL * a) % M;}if(M>mod7) a = binaryMultiply(a, a);else a = (a * 1LL * a) % M;b >>= 1;}return ans;}
ll digits(ll num){ll c=0; while(num){num/=10; c++;} return c;}
ll reverse1(ll num){ll dig=digits(num); ll g=0; while(num){g=10*g+num%10; num/=10;} return g;}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

#ifndef ONLINE_JUDGE
    #include "debug.h" 
#else
    #define deb(x...)
#endif

void dfunc(){
    
}

signed main()
{
    fast
    testcase

}