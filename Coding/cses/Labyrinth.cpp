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
bool check(int i,int j,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m) return false;
    return true;
}
void solve()
{
    int n,m; cin>>n>>m;
    map<int,vector<string>> m1;
    queue<pl> q;
    vector<string> maze(n);
    vector<vector<char>> vis(n,vector<char> (m,'?'));
    loop(i,0,n) {
        cin>>maze[i];
        loop(j,0,m){
            if(q.size()) break;
            if(maze[i][j] == 'A') q.push({i,j}),vis[i][j]='.';
        }
    }
    int x=-1,y=-1;
    while(q.size()){
        auto it = q.front();
        q.pop();
        int i = it.first;
        int j = it.second;
        if(maze[i][j] == 'B'){
            x = i,y=j;
            break;
        }
        if(check(i+1,j,n,m) && maze[i+1][j]!='#' && vis[i+1][j]=='?') q.push({i+1,j}),vis[i+1][j]='D';
        if(check(i-1,j,n,m) && maze[i-1][j]!='#' && vis[i-1][j]=='?') q.push({i-1,j}),vis[i-1][j]='U';
        if(check(i,j+1,n,m) && maze[i][j+1]!='#' && vis[i][j+1]=='?') q.push({i,j+1}),vis[i][j+1]='R';
        if(check(i,j-1,n,m) && maze[i][j-1]!='#' && vis[i][j-1]=='?') q.push({i,j-1}),vis[i][j-1]='L';
        // debug(n)
    }
    // debug(vis)
    if(x==-1)
        cout<<"NO"<<endl;
    else{
        string s = "";
        while(maze[x][y] != 'A'){
            s += vis[x][y];
            if(vis[x][y] == 'D')x--;
            else if(vis[x][y] == 'U')x++;
            else if(vis[x][y] == 'R')y--;
            else if(vis[x][y] == 'L')y++;
        }
        reverse(all(s));
        cout<<"YES"<<endl;
        cout<<s.length()<<endl;
        cout<<s<<endl;
    }
    
}
int main()
{
    fast
    int	t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}