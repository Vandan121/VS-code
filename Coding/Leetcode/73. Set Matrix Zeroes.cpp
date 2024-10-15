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


const int MOD = 1000000007;
const int MX = 100001;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;

void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int column = matrix[0].size();
        bool r=0,c=0;
        for(int i=0;i<column;i++)
        {
            if(matrix[0][i]==0)
            {
                r=true;
                break;
            }
        }
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0]==0)
            {
                c=true;
                break;
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=row-1;i>=1;i--)
        {
            for(int j=column-1;j>=1;j--)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if(r)
        {
            for(int j=0;j<column;j++)
            {
                matrix[0][j]=0;
            }
        }
        if(c)
        {
            for(int j=0;j<row;j++)
            {
                matrix[j][0]=0;
            }
        }
    }
void solve()
{
    vector<vector<int>> matrix;
    int n,m; cin>>n>>m;
    loop(i,0,n)
    {
        vi a(m); in(a,m);
        matrix.push_back(a);
    }
    setZeroes(matrix);
    
}
int main()
{
    fast
    int	t=1;
    // cin>>t
    while(t--)
    {
        solve();
    }
    
    return 0;
}