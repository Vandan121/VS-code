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
vi prime_numbers;
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime)); 
    for (int p = 2; p * p <= n; p++)
    {
    if (prime[p] == true)
    {
    for (int i = p * p; i <= n; i += p)
        prime[i] = false;
    }
    }
    for (int p = 2; p <= n; p++)
    if (prime[p])
    prime_numbers.push_back(p);
}
int main()
{
    fast
    int n,m; cin>>n>>m;
    vi a(n); in(a,n);
    set<int> div;
    loop(i,0,n)
    {
        ll index=0;
        ll temp=a[i];
        for(int j=2;j*j<=temp;j++)
        {
            if(temp%j==0)
            {
                div.insert(j);
                while(temp%j==0) temp/=j;
            }
        }
        if(temp>1) div.insert(temp);
        // cout<<prime_numbers.size()<<endl;
        // while(temp-1)
        // {
        //     if(prime_numbers[index]>temp)break;
        //     if(temp%prime_numbers[index]==0)
        //     {
        //         div.insert(prime_numbers[index]);
        //         while(temp%prime_numbers[index]==0) temp /= prime_numbers[index];
        //         index++;
        //     }
        //     else index++;
        // }
        // if(temp>1)div.insert(temp);
    }
    vi divisor;
    for(auto i : div)
    {
        divisor.push_back(i);
    }
    vi ans(m+1,1);
    for(int i=0;i<divisor.size();i++)
    {
        ll temp=divisor[i];
        if(temp > m+1)  break;
        if(!ans[temp]) continue;
        ans[temp]=0;
        for(int j=2*temp;j<m+1;j+=temp)
        {
            ans[j] =0;
        }
    }
    cout<<count(all(ans),1)-1<<endl;
    loop(i,1,m+1) if(ans[i])cout<<i<<endl;
    return 0;
}