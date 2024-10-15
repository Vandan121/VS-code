#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ul;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL));
#define gcd(x,y) __gcd(x,y)
const ll M =  1000000007;
const int N = 200001;
#define int ll
#define inp(i,s,e,a) for(ll i=s;i<e;i++) cin>>a[i];
#define fr(i,s,e) for(ll i=s;i<e;i++)
#define mp make_pair 
#define pb push_back
#define ff first
#define ss second
#define pi pair<int,int>
#define all(a) a.begin(),a.end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define tc(x) cout<<"Case "<<"#"<<x<<": ";
#define deb1(x) cout<<#x<<" : "<<x<<endl;
#define deb2(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<endl;
#define deb4(x,y,z,w) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<"\t"<<#w<<" : "<<w<<endl;
#define deb5(x,y,z,w,v) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<"\t"<<#w<<" : "<<w<<"\t"<<#v<<" : "<<v<<endl;
using vi = vector<int>; 
using vvi = vector<vi>;

int32_t main()
{
     fast
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vi x(k),d(k);
        for(auto &i:x) cin>>i;
        for(auto &i:d) cin>>i;
        vvi g(n+1);
        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        vector<bool> vis(n+1,0);
        // map<int,pair<int,int>> mp;
        for(int i=0;i<k;i++){
            // if(!vis[x[i]]){
                queue<int> q;
                q.push(x[i]);
                vis[x[i]] = 1;
                int dist = d[i]-1;
                while(!q.empty() && dist>0){
                    dist--;
                    int sz = q.size();
                    while(sz--){
                        int curr = q.front();
                        q.pop();
                        for(auto child:g[curr]){
                                if(!vis[child]){
                                    q.push(child);
                                    vis[child] = 1;
                                }
                        }
                    }
                }
            // }
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(vis[i]) cnt++;
        }
        if(cnt == n) yes;
        else no;
    }
	return 0;
}