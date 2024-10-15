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
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vl x(n),y(n);
        in(x,n);
        in(y,n);
        sort(all(x));
        if(n<=2*k || x[n-1]-x[0] <= 2*k)
        {
            cout<<n<<endl;
            continue;
        }
        else
        {
            ll middle = (n-1)/2,ans=0,i=0,last;
            while(i<=middle && middle-i+1>ans)
            {
                ll left = i;
                ll right = middle;
                ll count = 0;
                ll key = x[i] + k;
                while (left <= right) {
                ll mid = (right + left) / 2;
                if (x[mid] <= key) {
                    count = mid + 1;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
                }
                i++;
                if(count>ans)
                {
                    ans = count;
                    last = i+count-1;
                }
            }
            debug(ans)
            debug(last)
            ll ans1=0;
            while(last<n && n-last>ans1)
            {
                ll left = last;
                ll right = n-1;
                ll count = 0;
                ll key = x[last] + k;
                while (left <= right) {
                ll mid = (right + left) / 2;
                debug(mid)
                if (x[mid] <= key) {
                    count = mid + 1-left;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
                }
                last++;
                ans1 = max(ans1,count);
                debug(count)
            }
            debug(ans1)
            cout<<ans+ans1<<endl;
        }
    }
    return 0;
}

//1 1 2 3 4 5 5 