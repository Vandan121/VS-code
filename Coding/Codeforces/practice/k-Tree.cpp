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
#define mod 1000000007
#define ull long long int
void solve(){	
	ull n, k, d;
	cin>>n>>k>>d;
	vl table_d(n+1,0) ,table(n+1,0);
	/*
	ith element in table_d stores number of ways to make sum i with atleast one edge with weight equal to atleast d
	ith element in table stores number of ways to make sum i without any restriction
	*/
	table_d[0]=0;//no edge selected thus, condition is violated so no of ways = 0
	table[0]=1;//no edge selected
	for (ull i = 1; i <= n; i++){ // try to make sum i 
		for (ull j = 1; j <= k; j++){ //start with edge weight j
			if (j <= i){
				table[i] = (table[i]+table[i-j])%mod;
			}
			else{ // if j > i sum of path has already exceeded required sum 
				table[i]+=0;
			}
		}
	}
	for (ull i = 1; i <= n; i++){ 
		for (ull j = 1; j <= k; j++){
			if (j <= i){
				if (j >= d){ // if j >= d condition is fulfilled so we can make rest of the path without any restriction
					table_d[i] = (table_d[i] + table[i-j])%mod;
				}
				else{ // we still need to get a path with edge weight greater than or equal to d 
	 				table_d[i] = (table_d[i] + table_d[i-j])%mod;
				}
			}
			else{// if j > i sum of path has already exceeded required sum 
				table_d[i] += 0;
			}
		}
	}
	/*for (ull i = 0; i <= n; i++){
		cout<<table_d[i]<<" ";
	}
	cout<<"\n";*/
	cout<<table_d[n]<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	//int t;
	//cin>>t;
	//while(t--){
		solve();
	//}
	return 0;
}