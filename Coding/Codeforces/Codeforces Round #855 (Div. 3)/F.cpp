#define ll long long int
#include<bits/stdc++.h>
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
#define endl '\n'
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
using namespace std;
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


void solve(){
    ll n;   cin>>n;
    vector<string> v(n);    in(v,n);
    vector<map<int,int>> mp1(26),mp2(26);
    ll ans = 0;
    loop(i,0,n){
        ll sz = l(v[i]);    sz%=2;
        vector<int> fq(26,0);
        for(auto j:v[i])    fq[j-'a']++;
        vector<int> fq3 = fq;
        int vl = 0;
        loop(j,0,26)    {
            fq3[j]%=2;  fq3[j]^=1;
            vl+=fq3[j]*(1ll<<j);
        }
        loop(j,0,26)    {
            if(fq[j])   continue;
            fq3[j] = -1;
            vl+=fq3[j]*(1ll<<j);
            if(sz == 1 && mp1[j].find(vl)!=mp1[j].end()) ans+=mp1[j][vl];
            else if(sz == 0 && mp2[j].find(vl)!=mp2[j].end())    ans+=mp2[j][vl]; 
            vl-=fq3[j]*(1ll<<j);
            fq3[j] = 1;
        }
        vector<int> fq2 = fq;
        vl = 0;
        loop(k,0,26)    {
            fq2[k]%=2;
            vl+=fq2[k]*(1ll<<k);
        }
        loop(j,0,26){
            if(fq[j])   continue;
            fq2[j] = -1;
            if(sz == 0) mp1[j][vl]++;
            else mp2[j][vl]++;
            fq2[j] = 0;
        }
    }
    cout<<ans<<endl;

}


int main()
{
    fast
    int t = 1;
    while(t--) solve();
    return 0;
}