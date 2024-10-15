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
#define MAX 1000
 // } Driver Code Ends
/*You are required to complete this method*/

        int M[MAX][MAX];
class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<vector<int>> right(n+1,vector<int> (m+1,0));
        vector<vector<int>> bottom(n+1,vector<int> (m+1,0));
        int ans=0;
        for(int i=1;i<=n;i++) right[i][m] = M[i-1][m-1];
        for(int i=1;i<=n;i++)
        {
            for(int j=m-1;j>=1;j--)
            {
               if(M[i-1][j-1]) right[i][j] = 1+right[i][j+1];
               else right[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++) bottom[n][i] = M[n-1][i-1];
        for(int j=1;j<=m;j++)
        {
            for(int i=n-1;i>=1;i--)
            {
               if(M[i-1][j-1]) bottom[i][j] = 1+bottom[i+1][j];
               else bottom[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(right[i][j] != 0)
                {
                    int minimum = bottom[i][j];
                    for(int i1=j;i1<=j+right[i][j]-1;i1++)
                    {
                        minimum = min(minimum,bottom[i][i1]);
                        ans = max(ans,minimum*(right[i][j]-right[i][i1]+1));
                    }
                }
            }
        }
        return ans;
    }
};
// { Driver Code Starts.
int main() {
    int T=1;
    cin >> T;


    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends