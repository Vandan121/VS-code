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
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(queue <T> v) {cerr << "{"; while(v.size()){ _print(v.front()); cerr << " ";v.pop();} cerr << "}"; }
template <class T> void _print(stack <T> v) {stack<T> a; while(v.size()) a.push(v.top()), v.pop(); cerr << "{";  while(a.size()){ _print(a.top()); cerr << " ";a.pop();}  cerr << "}"; }
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


signed main()
{
    fast
    ll n,m,k; cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> g(n+1);
    loop(i,0,m){
        ll v,u,w; cin>>v>>u>>w;
        g[v].pb({u,w});
        g[u].pb({v,w});
    }
    vl v(k); in(v,k);
    set<ll> switch;
    loop(i,0,k) switch.insert(v[i]);
    vl dist(n+1,1e18);
    dist[1]=0;
    queue<pair<ll,ll>> q; q.push({1,0});
    vector<bool> vis(n+1,0);
    // vector<bool> viss(n+1,0);
    visi[1]=1;
    while(q.size()){
        auto v=q.front();
        q.pop();
        ll ver=v.fr;
        ll curs=v.sc;
        for(auto child:g[ver]){
            if(child.sc){
                if(vis[child.fr] && !(curs&1)) continue;
                q.push({child.fr,curs});
                dist[child.fr]=dist[ver]+1;
            }
            else{
                if(switch.count(ver)){
                    q.push({child.fr,curs+1});
                    dist[child.fr]=dist[ver]+1;
                }
            }
        }
    }
    debug(dist)
}