#define ll long long int
#include<bits/stdc++.h>
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
template <class T> void _print(deque <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll add7(ll x,ll y)  {ll ans = x+y; return (ans>=mod7 ? ans - mod7 : ans);}
ll sub7(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod7 : ans);}
ll mul7(ll x,ll y)  {ll ans = x*y; return (ans>=mod7 ? ans % mod7 : ans);}
ll add9(ll x,ll y)  {ll ans = x+y; return (ans>=mod9 ? ans - mod9 : ans);}
ll sub9(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod9 : ans);}
ll mul9(ll x,ll y)  {ll ans = x*y; return (ans>=mod9 ? ans % mod9 : ans);}
ll binaryMultiply(ll a, ll b,ll M=mod7){ll ans = 0;while (b) {if (b & 1){ans = (ans + a) % M;}a = (a + a) % M;b >>= 1;} return ans;}
ll binaryExponentiation(ll a, ll b,ll M=mod7){a %= M;ll ans = 1;while (b){if (b & 1){if(M>mod7) ans = binaryMultiply(ans, a);else ans = (ans * 1LL * a) % M;}if(M>mod7) a = binaryMultiply(a, a);else a = (a * 1LL * a) % M;b >>= 1;}return ans;}
ll digits(ll num){ll c=0; while(num){num/=10; c++;} return c;}

vl a,b; ll n; 

bool isOK(int persons){
    int p=0;
    loop(i,0,n){
        if(persons-p-1<=a[i]&&p<=b[i]) p++;
    }
    return p>=persons;
}


void dfunc(){
    cin>>n;
    loop(i,0,n){
        ll ai,bi; cin>>ai>>bi;
        a.pb(ai); b.pb(bi);
    }
    ll l=0,r=n,mid; 
    while(l<r-1){
        mid=(l+r)/2;
        if(isOK(mid)) l=mid; else r=mid-1;
    }
    if(isOK(r)) cout<<r<<endl; else cout<<l<<endl;
    a.clear(); b.clear();
}
signed main()
{
    fast
    testcase

}