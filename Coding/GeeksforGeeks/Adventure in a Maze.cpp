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

class Solution {
public:

    
    vector<int> FindWays(vector<vector<int>> &a){
        int n=a.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {dp[i][j]++; continue;}
                if(j==0){
                    if(a[i-1][j]==2 || a[i-1][j]==3) dp[i][j] += dp[i-1][j];
                    continue;
                }
                if(i==0){
                    if(a[i][j-1]==1 || a[i][j-1]==3) dp[i][j] += dp[i][j-1];
                    continue;
                }
                if(a[i-1][j]==2 || a[i-1][j]==3) {
                    dp[i][j] += dp[i-1][j]; 
                }
                if(a[i][j-1]==1 || a[i][j-1]==3) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        vector<int> ans;
        ans.push_back(dp[n-1][n-1]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)    dp[i][j] = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!i && !j)    {dp[i][j] = a[i][j];    continue;}
                if(j==0){
                    if((a[i-1][j]==2 || a[i-1][j]==3) && dp[i-1][j]) dp[i][j] =max(dp[i][j],dp[i-1][j]+a[i][j]);
                    continue;
                }
                if(i==0){
                    if((a[i][j-1]==1 || a[i][j-1]==3) && dp[i][j-1]) dp[i][j] =max(dp[i][j],dp[i][j-1]+a[i][j]);
                    continue;
                }
                if((a[i-1][j]==2 || a[i-1][j]==3) && dp[i-1][j]) {
                    dp[i][j] =max(dp[i][j],dp[i-1][j]+a[i][j]);
                }
                if((a[i][j-1]==1 || a[i][j-1]==3) && dp[i][j-1]) {
                    dp[i][j] =max(dp[i][j],dp[i][j-1]+a[i][j]);
                }
                debug(dp)
            }
        }
        ans.push_back(dp[n-1][n-1]);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends