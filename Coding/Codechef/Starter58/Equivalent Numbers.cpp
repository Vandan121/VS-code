#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define ll long long int
#define ld long double
#define cd complex<ld>
#define pi pair<int, int>
#define pl pair<ll,ll>
#define pd pair<ld,ld>
#define vi vector<int>
#define vd vector<ld>
#define vl vector<ll>
#define vpi vector<pi> 
#define vpl vector<pl> 
#define vcd vector<cd>
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
#define endl "\n" 
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
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

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ll add(ll x,ll y)  {ll ans = x+y; return (ans>=mod ? ans - mod : ans);}
ll sub(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod : ans);}
ll mul(ll x,ll y)  {ll ans = x*y; return (ans>=mod ? ans % mod : ans);}


//string decimaltobinary (ll n,ll length) {return bitset<length>(n).to_string();}
const int MOD = 1000000007;
void google(int t) {cout << "Case #" << t << ": ";}
ll binaryMultiply(ll a, ll b,ll M=mod){ll ans = 0;while (b) {if (b & 1){ans = (ans + a) % M;}a = (a + a) % M;b >>= 1;} return ans;}
ll binaryExponentiation(ll a, ll b,ll M=mod){a %= M;ll ans = 1;while (b){if (b & 1){if(M>mod) ans = binaryMultiply(ans, a);else ans = (ans * 1LL * a) % M;}if(M>mod) a = binaryMultiply(a, a);else a = (a * 1LL * a) % M;b >>= 1;}return ans;}
vector<ll> sieve(ll n) {ll *arr = new ll[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void extendgcd(ll a, ll b, vi &v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass a vector of size 3
ll mminv(ll a, ll M) {vi arr(3); extendgcd(a, M, arr); return arr[0];} //for non prime M
ll mminvprime(ll a, ll M) {return binaryExponentiation(a, M - 2, M);}//for prime M
ll phi(ll n){ll result=n;for(ll i=2;i*i<=n;i++){if(n%i==0){while(n%i==0) n/=i;result-=result/i;}}if(n>1) result-=result/n; return result;}
const int MX = 100001;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
void solve()
{
    ll x,y; cin>>x>>y;
    ll a = min(x,y);
    ll b = max(x,y);
    if(b%a){
        // cout<<x<<" "<<y<<endl;
        cout<<"NO"<<endl;
        return;
    }
    else if(a==1 && b!=1){
        // cout<<x<<" "<<y<<endl;
        cout<<"NO"<<endl;
        return;
    }
    
        ll c = b/a;
        while(a > 1 && c!=1){
            if(a%c != 0){
                // cout<<x<<" "<<y<<endl;
                cout<<"NO"<<endl;
                return;
            }
            a /= c;
        }
        // cout<<x<<" "<<y<<endl;
        cout<<"YES"<<endl;
    
}
int main()
{
    fast
    int	t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}

// #include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;
// #define ll long long int
// #define ld long double
// #define cd complex<ld>
// #define pi pair<int, int>
// #define pl pair<ll,ll>
// #define pd pair<ld,ld>
// #define vi vector<int>
// #define vd vector<ld>
// #define vl vector<ll>
// #define vpi vector<pi> 
// #define vpl vector<pl> 
// #define vcd vector<cd>
// #define loop(i,a,b) for(ll i=a;i<b;++i)
// #define rloop(i,a,b) for(ll i=a;i>=b;i--)
// #define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
// #define pb push_back
// #define mk make_pair
// #define all(v) v.begin(),v.end()
// #define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
// #define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
// #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL));
// #define l(a) a.length()
// #define fr first
// #define sc second
// #define mod 1000000007
// #define endl "\n" 
// #define yes cout<<"YES"<<endl;
// #define no cout<<"NO"<<endl;
// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
// #else
// #define debug(x);
// #endif
// #define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(double t) {cerr << t;}
// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T> void _print(queue <T> v) {cerr << "{"; while(v.size()){ _print(v.front()); cerr << " ";v.pop();} cerr << "}"; }
// template <class T> void _print(stack <T> v) {stack<T> a; while(v.size()) a.push(v.top()), v.pop(); cerr << "{";  while(a.size()){ _print(a.top()); cerr << " ";a.pop();}  cerr << "}"; }
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<class key, class value, class cmp = std::less<key>>
// using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// ll add(ll x,ll y)  {ll ans = x+y; return (ans>=mod ? ans - mod : ans);}
// ll sub(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod : ans);}
// ll mul(ll x,ll y)  {ll ans = x*y; return (ans>=mod ? ans % mod : ans);}


// //string decimaltobinary (ll n,ll length) {return bitset<length>(n).to_string();}
// const int MOD = 1000000007;
// void google(int t) {cout << "Case #" << t << ": ";}
// ll binaryMultiply(ll a, ll b,ll M=mod){ll ans = 0;while (b) {if (b & 1){ans = (ans + a) % M;}a = (a + a) % M;b >>= 1;} return ans;}
// ll binaryExponentiation(ll a, ll b,ll M=mod){a %= M;ll ans = 1;while (b){if (b & 1){if(M>mod) ans = binaryMultiply(ans, a);else ans = (ans * 1LL * a) % M;}if(M>mod) a = binaryMultiply(a, a);else a = (a * 1LL * a) % M;b >>= 1;}return ans;}
// vector<ll> sieve(ll n) {ll *arr = new ll[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
// void extendgcd(ll a, ll b, vi &v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass a vector of size 3
// ll mminv(ll a, ll M) {vi arr(3); extendgcd(a, M, arr); return arr[0];} //for non prime M
// ll mminvprime(ll a, ll M) {return binaryExponentiation(a, M - 2, M);}//for prime M
// ll phi(ll n){ll result=n;for(ll i=2;i*i<=n;i++){if(n%i==0){while(n%i==0) n/=i;result-=result/i;}}if(n>1) result-=result/n; return result;}
// const int MX = 100001;
// const ll MOD1 = 1e9+7;
// const ll MOD9 = 998244353;
// const ll INF = 1e18;

// vl spf(1000010);

// vl fn(int a){
//     vector<ll> vc;
//     while(a>1){
//         vc.pb(spf[a]);
//         a/=spf[a];
//     }
//     return vc;
// }

// void solve()
// {
//     ll x,y; cin>>x>>y;
//     ll x1 = x;
//     ll y1 = y;
//     map<ll,ll> m;
//     map<ll,ll> m1;
//     // ll n = primes.size();
//     vl v1=fn(x1);
//     vl v2=fn(y1);
//     for(auto x:v1) m[x]++;
//     for(auto x:v2) m1[x]++;
//     if(m1.size()!=m.size()){
//             cout<<"NO\n"; return ;
//     }
//     ll a,b;
//     bool flag = false;
//     for(auto ele : m){
//         if(m1[ele.fr]==0){
//             cout<<"NO\n"; return ;
//         }
//         if(flag) break;
//         else{
//             ll lcm=(m1[ele.first]*ele.second)/__gcd(m1[ele.first],ele.second);
//             b = lcm/m1[ele.first];
//             a = lcm/ele.second;
//             flag = true;
//         }
//     }
//     for(auto ele : m){
//         if(m1[ele.fr]==0){
//             cout<<"NO\n"; return ;
//         }
//         ll lcm=(m1[ele.first]*ele.second)/__gcd(m1[ele.first],ele.second);
//         ll b1 = lcm/m1[ele.first];
//         ll a1 = lcm/ele.second;
//         if(a1!=a || b1!=b){
//             cout<<"NO\n"; return ;
//         }
//     }
//     cout<<"YES"<<endl;
// }
// int main()
// {
//     fast
//     loop(i,0,spf.size()) spf[i]=i;
//     loop(i,2,1000010){
//         for(int j=i; j<=1e6; j+=i)
//             if(spf[j]==j) spf[j]=i;
//     }
//     int	t=1;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }
