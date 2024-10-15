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
ll cnt = 0;

void solve(){
    cnt++;
    ll n;   cin>>n;
    // n = cnt++;
    vector<ll> v = {0};
    ll idx = 1;
    while(idx*idx <= 3*n){
        v.pb(idx*idx);
        idx++;
    }
    vector<ll> ans(n),vis(n,0);
    vector<vector<ll>> vec(n);
    loop(i,0,n){
        for(auto j:v)   if(j-i >= 0 && j-i < n)    vec[i].pb(j-i);
    }
    if(!vec.back().size())  {cout<<-1<<endl;    return;}
    ll mi = vec.back()[0];
    rloop(i,n-1,0){
        if(!vec[i].size()){cout<<-1<<endl;  return;}
        if(vis[mi] || mi >= n) mi = vec[i][0];
        if(vis[mi]) {cout<<-1<<endl;    return;}
        ans[i] = mi++;
        vis[mi-1] = 1;
    }
    dis(vec[n-1])
    // k1 k2+1 k3+2 k4+3 k5+4 k6+5 k7+6
    // k1,k2,k3,k4,k5,k6 => permutation
    // k1 => [0,1,4]
    // k2 => [0,3]
    // k3 => [2]
    // k4 => [1,6]
    // k5 => [0,5]
    // k6 => [4]
    // k7 => [3]

    // 1 0 2 6 5 4 3

    // 0 => k1,k2
    // 1 => k1
}


int main()
{
    fast
    int t; cin>>t;
    while(t--) solve();
    return 0;
}