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
int main()
{
    fast
    ll n; cin>>n;
    ll sum=0;
    vl a(n);
    vector<pl> b(n);
    loop(i,0,n)
    {
        cin>>a[i]; sum+=a[i]; b[i].first=sum; b[i].second=i;
    }
    sort(all(b));
    if(sum%3 || a.size()<3)
    {
        cout<<0<<endl;
        return 0;
    }
    vl sums[2];
    loop(i,1,3)
    {
        pl p={i*sum/3,0};
        ll index = lower_bound(all(b),p)-b.begin();
        loop(j,index,n)
        {
            if(b[j].first==(i*sum)/3)sums[i-1].push_back(b[j].second);
            else break;
        }
    }
    ll cnt=0;
    // if(sums[0].size()==0 || sums[1].size()==0)
    // {
    //     cout<<0<<endl;
    //     return 0;
    // }
    sort(all(sums[0]));
    sort(all(sums[1]));
    loop(i,0,sums[0].size())
    {
        ll index = lower_bound(all(sums[1]),sums[0][i]+1)-sums[1].begin();
        if(index==sums[1].size()) continue;
        if(sums[1].back()==n-1)
        {
            cnt+=sums[1].size()-index-1;
        }   
        else cnt +=sums[1].size()-index;
    }
    cout<<cnt;
    return 0;
}