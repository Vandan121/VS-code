#define ll long long int
#include<bits/stdc++.h>
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL));
#define l(a) a.length()
#define fr first
#define sc second
#define mod 1000000007
#define endl '\n'
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
using namespace std;
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll add(ll x,ll y)  {ll ans = x+y; return (ans>=mod ? ans - mod : ans);}
ll sub(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod : ans);}
ll mul(ll x,ll y)  {ll ans = x*y; return (ans>=mod ? ans % mod : ans);}
vector<vector<ll>> vec,v;
vector<ll> vis,sz,par;
ll ma = INT_MAX,vl;
ll fn(ll i,ll h,ll j){
    vis[i]++;
    ll ans = 1,ok = 0;
    par[i] = j;
    for(auto j:vec[i]){
        if(!vis[j]){
            ok = 1;
            ans+=fn(j,h+1,i);
            v[i].pb(j);
        }
    }
    if(!ok){
        if(ma > h){
            ma = h;
            vl = i;
        }
    }   
    // debug(i)
    // debug(ans)
    return sz[i] = ans;
}

void solve(){
    ma = INT_MAX;
    ll n;   cin>>n;
    vec.assign(n+1,{});
    v.assign(n+1,{});
    vis.assign(n+1,0);
    sz.assign(n+1,0);
    par.assign(n+1,0);
    loop(i,0,n-1){
        ll a,b; cin>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
    }
    fn(1,0,-1);
    vector<ll> path;
    while(vl!=1){
        path.pb(vl);
        vl = par[vl];
    }
    path.pb(1);
    reverse(all(path));
    ll ans = 0;
    loop(i,0,path.size()-1){
        ll temp = path[i+1],temp2 = path[i];
        loop(j,0,v[temp2].size()) {
            if(v[temp2][j] == temp)   continue;
            else ans+=sz[v[temp2][j]]-1;
        }
    }
    // debug(v)
    // debug(size)
    loop(j,0,v[1].size())   ans = max(ans,sz[v[1][j]]-1);
    cout<<ans<<endl;
}


int main()
{
    fast
    int t; cin>>t;
    while(t--) solve();
    return 0;
}