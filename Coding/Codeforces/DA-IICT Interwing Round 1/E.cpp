            /**************************************
            *                                     *
            *            sasta_samurai            *
            *                                     *
            **************************************/
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
#define vs vector<string>
#define vd vector<ld>
#define vl vector<ll>
#define vpi vector<pi> 
#define vpl vector<pl> 
#define vvl vector<vl> 
#define vcd vector<cd>
#define st string
#define ct continue
#define mll map<ll,ll>
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL));
#define l(a) a.length()
#define maxx(a,b) max(1ll*(a),1ll*(b));
#define minn(a,b) min(1ll*(a),1ll*(b));
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
const int TWO_MOD_INV = 500000004;
bool sq(ll n){
    ll i = sqrt(n);
    return (i*i == n);
}
bool check(ll i,ll j,ll n,ll m){
    if(i<0 || j<0 || i>=n || j>=m){
        return false;
    }
    return true;
}
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime)); 
    for (int p = 2; p * p <= n; p++)
    {
    if (prime[p] == true)
    {
    for (int i = p * p; i <= n; i += p)
        prime[i] = false;
    }
    }
    for (int p = 2; p <= n; p++)
    if (prime[p])
    cout << p << " ";
}
ll total_sum(ll start,ll end){
    return (
        (((end - start + 1) % MOD) * ((start + end) % MOD) % MOD)
        * TWO_MOD_INV % MOD
    );
}
/* sparse table */
void build(vl &a){
ll sparse[200010][32];
ll lg[200010];
    // memset(sparse,-1,sizeof sparse);
    ll n = a.size();
    for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
    for(int i=0;i<n;i++){
        sparse[i][0] = a[i];
    }
    for(int j=1;j<30;j++){
        for(int i=0;i+(1<<j) <= n;i++){
            sparse[i][j] = max(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
        }
    }
}
/*ncr function*/
ll binexp(ll a,ll b, ll m){
    ll res = 1;
    while(b>0){
        if(b&1){
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b >>= 1;
    }
    return res;
}
vl fact(1e6+1,1);
void factorial(){
    for(int i=1;i<=1e6;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}
ll ncr(ll n,ll k){
    ll ans = fact[n];
    ll den = (fact[n-k]*fact[k])%mod;
    den = binexp(den,mod-2,mod);
    ans = (ans*den)%mod;
    return ans;
}
// important syntaxes here
/* sparse table*/
// ll d = lg[abs(x1-x2)];
// ll max_height = max(sparse[min(x1,x2)-1][d],sparse[max(x1,x2)-(1<<d)][d]);
/*ordered_set*/
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
//cout<<setprecision(15)<<pow(1.1,x)
//*max_element(all(vec))
//count(all(vec),0ll))
// Sparse Matrix DP approach to find LCA of two nodes


// pre-compute the depth for each node and their
// first parent(2^0th parent)
// time complexity : O(n)
void dfs(ll cur, ll prev,vvl &graph, vl &depth, vvl &parent)
{
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	for (int i=0; i<graph[cur].size(); i++)
	{
		if (graph[cur][i] != prev)
			dfs(graph[cur][i], cur,graph,depth,parent);
	}
}

// Dynamic Programming Sparse Matrix Approach
// populating 2^i parent for each node
// Time complexity : O(nlogn)
void precomputeSparseMatrix(ll n,vvl &graph, vl &depth, vvl &parent)
{
	for (int i=1; i<32; i++)
	{
		for (int node = 1; node <= n; node++)
		{
			if (parent[node][i-1] != -1)
				parent[node][i] =
					parent[parent[node][i-1]][i-1];
		}
	}
}

// Returning the LCA of u and v
// Time complexity : O(log n)
int lca(int u, int v,vvl &graph, vl &depth, vvl &parent)
{
	if (depth[v] < depth[u])
		swap(u, v);

	int diff = depth[v] - depth[u];

	// Step 1 of the pseudocode
	for (int i=0; i<32; i++)
		if ((diff>>i)&1)
			v = parent[v][i];

	// now depth[u] == depth[v]
	if (u == v)
		return u;

	// Step 2 of the pseudocode
	for (int i=31; i>=0; i--)
		if (parent[u][i] != parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];
		}

	return parent[u][0];
}

void func(ll i,vvl &graph,vl &par,vl &vis){
    vis[i] = 1;
    for(auto e : graph[i]){
        if(vis[e] == 0){
            par[e] = i;
            func(e,graph,par,vis);
        }
    }
}

void solve()
{
    ll n; cin>>n;
    vl a(n+1);
    loop(i,0,n){
        cin>>a[i+1];
    }
 
    vector <vl> graph(n+5);
    vl depth(n+5);
    vvl parent(n+5,vl (32,-1));
    vl par(n+5);
    vl vis(n+5,0);
    loop(i,0,n-1){
        ll x,y; cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    dfs(1,0,graph,depth,parent);
    precomputeSparseMatrix(n,graph,depth,parent);
    func(1,graph,par,vis);
    ll q; cin>>q;
    while(q--){
        ll x,y; cin>>x>>y;
        ll anc = lca(x,y,graph, depth, parent);
        vl vec;
        ll p1 = x;
        ll p2 = y;
        while(p1 != anc){
            vec.pb(a[p1]);
            p1 = par[p1];
        }
        while(p2 != anc){
            vec.pb(a[p2]);
            p2 = par[p2];
        }
        vec.pb(a[anc]);
        sort(all(vec));
        if(vec.size() < 10) cout<<vec.back()<<" ";
        else cout<<vec[vec.size()-10]<<" ";
    }
    cout<<endl;
}
int main()
{
    fast
    int	t=1;
    cin>>t;
    factorial();
    while(t--)
    {
        solve();
    }
    
    return 0;
}