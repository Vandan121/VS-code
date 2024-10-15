//#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define Fast() ios_base::sync_with_stdio(0) ; cin.tie(0) ;
#define all(v) ((v).begin()), ((v).end())
#define lp(i,n) for(int i = 0; i < n ; i++)
#define EPS 1e-9
#define F first
#define S second
#define INF	1<<30
typedef long long ll;
typedef long double ld;
const int pi = 3.14;
//const int mod = 1e9 + 7;
const int N = 2e6+10, shift = 40;
using namespace std;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
//ll dx[] = {-1, -1, -1, 0, 0, 1, 1, 1} ;
//ll dy[] = {-1, 0, 1, -1, 1, -1, 0, 1} ;
string dir[] = {"forth", "right", "left"};
string name = "abcdefghijklmnopqrstuvwxyz";
//map<int,int>freq;
//map<int, int >freqy;
//map<int, bool>visited;
vector<int>adj[N];
//ll dis[N], par[N];
//struct DSU
//{
//    int p[N], sz[N], ncmp, mxsz;
//    void init(int nNodes)
//    {
//        iota(p, p + nNodes, 0);
//        fill(sz, sz + nNodes, 1);
//        ncmp = nNodes;
//        mxsz = 1;
//    }
//    int find(int u)
//    {
//        return p[u] == u ? u : p[u] = find(p[u]);
//    }
//
//    bool operator()(int u, int v)
//    {
//        u = find(u), v = find(v);
//        if (u == v) return 0;
//        if (sz[u] > sz[v])
//            swap(u, v);
//        p[u] = v;
//        sz[v] += sz[u];
//        mxsz = max(mxsz, sz[v]);
//        --ncmp;
//        return 1;
//    }
//} dsu;
//ll solve(int ind, int cmp, int rem)
//{
//	if(ind == n) return rem == 0;
//	ll &ret = dp[ind][cmp][rem];
//	if(vis[ind][cmp][rem] == vid) return ret;
//	vis[ind][cmp][rem] = vid;
//	ret = 0;
//	for(int d = 0 ; d < 10 ; d++)
//	{
//		if(cmp == 0 and d != str[ind] - '0')
//		{
//			if(d < str[ind] - '0') ret = (ret + solve(ind + 1, 1, (rem + d) % D)) % mod;
//		}
//		else
//		{
//			ret = (ret + solve(ind + 1, cmp, (rem + d) % D)) % mod;
//		}
//	}
//	return ret;
//}
//bool is_prime(ll n)
//{
//    if(n==2)
//        return 1;
//    if(n<2||n%2==0)
//        return 0;
//    for(ll i = 3; i*i <= n; i += 2)
//        if(n%i==0)
//            return 0;
//    return 1;
//}
//ll printNcR(int n, int r)
//{
//    long long p = 1, k = 1;
//    if (n - r < r)
//        r = n - r;
//    if (r != 0)
//    {
//        while (r)
//        {
//            p *= n;
//            k *= r;
//            long long m = __gcd(p, k);
//            p /= m;
//            k /= m;
//
//            n--;
//            r--;
//        }
//    }
//    else
//        p = 1;
//    return p;
//}
vector < ll >v;
void  solve ()
{
    ll n = 0;
    for(int i = 1 ; n <= 50000 ; i++)
    {
        n += 7;
        v.push_back(n);
    }
}
void HakunaaMatata()
{
    int n, k, sum = 0;
    cin >> n ;
        int mn = INT_MAX, ans ;
        for(int i = 0 ; i < v.size() ; i++)
        {
            string s = to_string(v[i]), s2 = to_string(n);
            int cnt = 0;
            int sz = s2.size() , sz2 =  s.size();
            if(sz == sz2){
            for(int i = 0 ; i < min(sz, sz2) ; i++)
            {
                if(s[i] != s2[i])
                {
                    cnt++;
                }
            }
            if(cnt < mn)
            {
                mn = cnt;
                ans = v[i];
            }
            }
        }
        cout << ans << endl;


}
int main()
{
    Fast()
    //freopen("traffic_control_validation_input (2).txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TEST_CASE = 1;
    solve();
    cin >> TEST_CASE;
    for(int t = 0 ; t < TEST_CASE ; t++)
    {
        HakunaaMatata() ;
    }
}
