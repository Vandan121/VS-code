#define ll long long int
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<climits>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

#define p(x) cout<<x<<endl;
#define loop(i,a,b) for(ll i=a;i<=b;++i)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL));
#define l(a) a.length()
#define sz(a) a.size()
#define fr first
#define sc second
#define mod 1000000007
#define endl '\n'
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
using namespace std;
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
template <class T> void _print(deque <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll binaryMultiply(ll a, ll b,ll M=mod){ll ans = 0;while (b) {if (b & 1){ans = (ans + a) % M;}a = (a + a) % M;b >>= 1;} return ans;}
ll binaryExponentiation(ll a, ll b,ll M=mod){a %= M;ll ans = 1;while (b){if (b & 1){if(M>mod) ans = binaryMultiply(ans, a);else ans = (ans * 1LL * a) % M;}if(M>mod) a = binaryMultiply(a, a);else a = (a * 1LL * a) % M;b >>= 1;}return ans;}
ll mminvprime(ll a, ll M) {return binaryExponentiation(a, M - 2, M);}
ll __gcd(ll a, ll b) {if (b > a) {return __gcd(b, a);} if (b == 0) {return a;} return __gcd(b, a % b);}
ll add(ll x,ll y)  {ll ans = x+y; return (ans>=mod ? ans - mod : ans);}
ll sub(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod : ans);}
ll mul(ll x,ll y)  {ll ans = x*y; return (ans>=mod ? ans % mod : ans);}

string func(string s,ll ans){
    ll n = s.size();
    ll i = 0;
    ll j = ans;
    string s1 = s;
    while(i <= n-1){
        s1[j] = s[i];
        i++;
        j++;
        if(j==n) j%=n;
    }
    return s1;
}

void solve(){
    ll n; cin>>n;
    string s; cin>>s;
    ll q; cin>>q;
    vector<ll> v(q); in(v,q);

    ll ans = 0;
    if(q&1){//odd
        for(ll i=0;i<=q-2;i+=2){
            ans += (v[i+1]-v[i]);
            if(ans < n) ans+=n;
            if(ans >= n) ans%=n;
        }
        string s1 = func(s,ans);
        reverse(s1.begin(),s1.begin()+v[q-1]);
        reverse(s1.begin()+v[q-1],s1.end());
        p(s1)
    }
    else{
        for(ll i=0;i<=q-1;i+=2){
            ans += (v[i+1]-v[i]);
            if(ans < n) ans+=n;
            if(ans >= n) ans%=n;
        }
        string s1 = func(s,ans);
        p(s1)
    }


}


int main()
{
    fast
    int t; t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}