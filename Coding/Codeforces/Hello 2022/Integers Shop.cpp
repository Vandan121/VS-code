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
        int n;
        cin>>n;
        vector<pair<ll,ll>> ing(n);
        vector<ll>price(n);
        loop(i,0,n)
        {
            cin>>ing[i].first>>ing[i].second>>price[i];
        }
        int left=ing[0].first,right=ing[0].second,sum=0,lefti=0,righti=0;
        loop(i,0,n)
        {
            sum=0;
            if(ing[i].first <= left && ing[i].second >= right)
            {
                if(ing[i].first == left && ing[i].second == right)
                {
                    if(price[i] < price[lefti]+price[righti])
                    {
                        lefti=i;
                        righti=i;
                        left = ing[i].first;
                        right = ing[i].second;
                    }
                }
                else
                {
                    lefti=i;
                    righti=i;
                    left = ing[i].first;
                    right = ing[i].second;
                }
            }
            else if(ing[i].first <= left)
            {
                if(ing[i].first == left && price[i] < price[lefti] && lefti != righti)
                    lefti=i;
                else if(ing[i].first < left)
                    lefti=i;
                left = ing[lefti].first;
            }
            else if(ing[i].second >= right)
            {
                if(ing[i].second == right && price[i] < price[righti] && lefti != righti)
                    righti=i;
                else if(ing[i].second > right)
                    righti=i;
                right = ing[righti].second;
            }
            if(lefti == righti)
            cout<<price[lefti]<<endl;
            else
            cout<<price[lefti]+price[righti]<<endl;
        }
    }
    return 0;
}