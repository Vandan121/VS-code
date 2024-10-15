#include<bits/stdc++.h>
using namespace std;
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

ll add(ll x,ll y)  {ll ans = x+y; return (ans>=mod ? ans - mod : ans);}
ll sub(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod : ans);}
ll mul(ll x,ll y)  {ll ans = x*y; return (ans>=mod ? ans % mod : ans);}


//string decimaltobinary (ll n,ll length) {return bitset<length>(n).to_string();}
const int MOD = 1000000007;
const int MX = 100001;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;

class Solution{
    public:
    // void bfs(vector<int> graph[],bool visited[],int s,vector<int> &dist)
    // {
    //     visited[s]=true;
    //     queue<int> qu;
    //     qu.push(1);
    //     dist[s]=0;
    //     while(!qu.empty())
    //     {
    //         debug(qu)
    //         int k=qu.front();
    //         qu.pop();
    //         for(int x:graph[k])
    //         {
    //             if(visited[x]==false)
    //             {
    //               dist[x]=dist[k]+1;
    //               visited[x]=true;
    //               qu.push(x);
    //             }
    //         }
    //     }
    // }
    // int countOfNodes(vector<int> graph[], int n)
    // {
    //     bool visited[n+1];
    //     vector<int> dist(n+1,-1);
    //     for(int i=1;i<=n;i++) visited[i]=false;
    //     bfs(graph,visited,1,dist);
    //     int cnt1=0;
    //     int cnt2=0;
    //     for(int i=1;i<dist.size();i++)
    //     {
    //         if(dist[i]!=-1 && dist[i]%2==0)
    //         cnt1++;
    //         if(dist[i]!=-1 && dist[i]%2==1)
    //         cnt2++;
    //     }
    //     debug(dist)
    //     cnt1=cnt1*(cnt1-1)/2;
    //     cnt2=cnt2*(cnt2-1)/2;
    //     return cnt1+cnt2;
    // }
    int countOfNodes(vector<int> graph[], int n)
    {
        debug(n)
        // code here
        vector<int> a(n,-1);
        int even=0,odd=0;
        queue<int> q;
        int dist=0;
        q.push(1);
        while(q.size()){
            int qs=q.size();
            debug(q)
            while(qs--){
                auto it = q.front();
                q.pop();
                if(a[it-1]!=-1) continue;
                a[it-1] = dist;
                dist++;
                for(int i=0;i<graph[it].size();i++){
                    q.push(graph[it][i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]%2) odd++;
            else even++;
        }
        cout<<even<<endl;
        cout<<odd<<endl;
        return (even*(even-1) + odd*(odd-1))/2;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends