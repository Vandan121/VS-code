#include <bits/stdc++.h> 
// #include<ext/pb_ds/assoc_container.hpp> 
// #include<ext/pb_ds/tree_policy.hpp> 

using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;

#define ll long long int 
#define endl "\n" 
#define ull unsigned long long int 
#define setbits(x) __builtin_popcountll(x) 
#define lcm(a,b) (a*b*1LL)/__gcd(a,b)
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define in(a) for(auto &i:a) cin>>i;
#define dis(v) for(auto &i:v)cout<<i<<" ";cout<<endl;
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define l(a) a.length()
#define fr first
#define sc second
#define mod 1000000007
#define mod1 998244353
#define PI 3.141592653589793238462
#define inf 1e18
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define vi vector<ll>
#define pii pair<ll,ll>
#define s(v) (int)v.size()
#define add accumulate
#define precise(x) fixed << setprecision(x)
#define p(n) cout<<n<<"\n";

// typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds;// find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

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
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void google(int t) {cout << "Case #" << t << ": ";}
ll binaryMultiply(ll a, ll b,ll M=mod){ll ans = 0;while (b) {if (b & 1){ans = (ans + a) % M;}a = (a + a) % M;b >>= 1;} return ans;}
ll binaryExponentiation(ll a, ll b,ll M=mod){a %= M;ll ans = 1;while (b){if (b & 1){if(M>mod) ans = binaryMultiply(ans, a);else ans = (ans * 1LL * a) % M;}if(M>mod) a = binaryMultiply(a, a);else a = (a * 1LL * a) % M;b >>= 1;}return ans;}
vector<ll> sieve(ll n) {ll *arr = new ll[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void extendgcd(ll a, ll b, vi &v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass a vector of size 3
ll mminv(ll a, ll M) {vi arr(3); extendgcd(a, M, arr); return arr[0];} //for non prime M
ll mminvprime(ll a, ll M) {return binaryExponentiation(a, M - 2, M);}//for prime M
ll phi(ll n){ll result=n;for(ll i=2;i*i<=n;i++){if(n%i==0){while(n%i==0) n/=i;result-=result/i;}}if(n>1) result-=result/n; return result;}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll m,n; cin>>m>>n;
        vi v(m); in(v)
        ll zeros=(count(all(v),0));
        if(zeros<n+1)
        {
            cout << "-1\n";
            continue;
        }
        vi pos;
        loop(i,0,m)
        {
            if(v[i]==0) pos.pb(i);
        }
        // debug(pos)
        ll ans=inf;
        ll median1=(n>>1);
        ll median2=((n>>1)+1);
        ll median3=((n>>1)-1);
        loop(i,0,s(pos)-n)
        {
            // debug(mk(pos[median1],pos[median2]))
            ll tmp1=max(abs(pos[median1]-pos[i]),abs(pos[median1]-pos[i+n]));
            ll tmp2=max(abs(pos[median2]-pos[i]),abs(pos[median2]-pos[i+n]));
            ll tmp3=max(abs(pos[median3]-pos[i]),abs(pos[median3]-pos[i+n]));
            // debug(mk(tmp1,tmp2))
            ans=min({tmp1,tmp2,tmp3,ans});
            median1++;
            median2++;
            median3++;
        }
        cout << ans << endl;
    }
}