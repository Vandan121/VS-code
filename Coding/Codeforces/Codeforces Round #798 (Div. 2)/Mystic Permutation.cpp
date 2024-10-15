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

void generate_derangement(int N,vector<ll> v)
{
    int S[N + 1];
    priority_queue<int, vector<int>, greater<int> > PQ;
    for (int i = 1; i <= N; i++) {
        S[i] = v[i-1];
        PQ.push(S[i]);
    }
    int D[N + 1];
    for (int i = 1; i <= N; i++) {
        int d = PQ.top();
        PQ.pop();
        if (d != S[i] || i == N) {
            D[i] = d;
        }
        else {
            D[i] = PQ.top();
            PQ.pop();
            PQ.push(d);
        }
    }
 
    if (D[N] == S[N])
       swap(D[N-1], D[N]);
    for (int i = 1; i <= N; i++)    cout<<D[i]<<" ";
    cout<<endl;
}

void solve(){
    ll n;   cin>>n;
    vector<ll> v(n);    in(v,n);
    if(n == 1)  {cout<<-1<<endl;    return;}  
    generate_derangement(n,v);
}


int main()
{
    fast
    int t; cin>>t;
    while(t--) solve();
    return 0;
}