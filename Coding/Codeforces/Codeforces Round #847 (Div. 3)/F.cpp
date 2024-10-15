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
const ll MAXN = 200200;
const ll INF = 1e9;
 
ll n, ans = INF;
ll dist[MAXN];
bool black[MAXN];
vector<ll> graph[MAXN];
 
void init() {
	ans = INF;
	for (int v = 0; v <= n; ++v)
		graph[v].clear();
	fill(dist, dist + n+5, INF);
	memset(black, 0, n+5);
}
void dfs(ll i,ll par){
    if(dist[i]>=ans) return ;
    if(black[i]) ans=min(ans,dist[i]+0ll);
    for(auto e : graph[i]){
        if(e == par){
            continue;
        }
        if(dist[e] > dist[i]+1){
            dist[e] = dist[i]+1;
            dfs(e,i);
        }
        else{
            ans = min(ans,dist[e]+dist[i]+1);
        }
    }
}
void solve()
{
    cin>>n;
    init();
    vl a(n);
    loop(i,0,n){
        cin>>a[i];
    }
    loop(i,0,n-1){
        ll v1,v2; cin>>v1>>v2;
        graph[v1].pb(v2);
        graph[v2].pb(v1);
    }
    dist[a[0]] = 0;
    dfs(a[0],0);
    black[a[0]] = 1;
    loop(i,1,n){
        dist[a[i]] = 0;
        dfs(a[i],0);
        black[a[i]] = 1;
        cout<<ans<<" ";
    }
    cout<<endl;
}
int main()
{
    fast
    int	t=1;
    cin>>t;
    // factorial();
    while(t--)
    {
        solve();
    }
    
    return 0;
}