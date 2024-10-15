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
void solve()
{
    ll n,k; cin>>n>>k;
    vl a(n); 
    map <ll,ll> m;
    loop(i,0,n)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    if(m.size() == n)
    {
        sort(all(a));
        ll q=ceil(1.0*k/n);
        ll rem=k-n*(q-1);
        cout<<a[q-1]<<" "<<a[rem-1]<<endl;
    }
    else
    {
        map<ll,ll> :: iterator itr;
        vector<pl> freq(m.size());
        ll i=0;
        for(itr=m.begin();itr!=m.end();itr++)
        {
            freq[i].first = itr->first;
            freq[i].second = itr->second;
            i++;
        } 
        
        ll temp=0;
        i=0;
        while(i<freq.size())
        {
		
            if(1LL*(temp+(freq[i].second*n)) >= 1LL*k)
            {
				
				
                ll j=0;
                while(1)
                {
                    if(temp+(freq[i].second*freq[j].second) >= k) 
                    {
                        cout<<freq[i].first<<" "<<freq[j].first<<endl;
                        return;
                    }
                    else temp += freq[i].second*freq[j].second;
                    j++;
                }
            }
            else 
			{
				temp+=(freq[i].second*n);
				
			}
            i++;
        }
    }
}
int main()
{
    fast
    ll t=1;
    cin>>t;
    while(t--)
    {
    solve();
    }
    
    return 0;
}

