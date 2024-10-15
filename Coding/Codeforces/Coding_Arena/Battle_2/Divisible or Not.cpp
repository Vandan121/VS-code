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
        int n,d,sum;
        cin>>n>>d;
        string s;
        cin>>s;
        switch(d)
        {
            case 1:
            cout<<s<<endl;
            break;
            case 2:
                if((s[n-1]-'0')%2 != 0)
                cout<<"-1"<<endl;
                else
                {
                    string ans = "";
                    int carry=0,temp=0,quo=0;
                    loop(i,0,n)
                    {
                        temp = carry*10;
                        temp += s[i] - '0';
                        quo = temp/2;
                        ans += quo+'0';
                        carry = temp%2;
                    }
                    loop(i,0,n)
                    {
                        temp =i;
                        if(ans[i] != '0')
                        break;
                    }
                    loop(i,temp,n)
                    {
                        cout<<ans[i];
                    }
                    cout<<endl;
                }
                break;
            case 3:
                sum=0;
                loop(i,0,n)
                {
                    sum += s[i] - '0';
                }
                //cout<<"sum : "<<sum<<endl;
                if(sum%3 != 0)
                cout<<"-1"<<endl;
                else
                {
                    string ans = "";
                    int carry=0,temp=0,quo=0;
                    loop(i,0,n)
                    {
                        temp = carry*10;
                        temp += s[i] - '0';
                        quo = temp/3;
                        ans += quo+'0';
                        carry = temp%3;
                    }
                    loop(i,0,n)
                    {
                        temp =i;
                        if(ans[i] != '0')
                        break;
                    }
                    loop(i,temp,n)
                    {
                        cout<<ans[i];
                    }
                    cout<<endl;
                }
                break;
            case 4:
                if(n==1)
                {
                    if((s[0]-'0')%4 != 0)
                    cout<<"-1"<<endl;
                    else
                    cout<<(s[0]-'0')/4<<endl;
                }
                else if(n==2)
                {
                    if(((s[n-2]-'0')*10 + s[n-1] - '0')%4 != 0)
                    cout<<"-1"<<endl;
                    else
                    cout<<((s[n-2]-'0')*10 + s[n-1] - '0')/4<<endl;
                }
                else
                {
                    string ans = "";
                    int carry=0,temp=0,quo=0;
                    loop(i,0,n)
                    {
                        temp = carry*10;
                        temp += s[i] - '0';
                        quo = temp/4;
                        ans += quo+'0';
                        carry = temp%4;
                    }
                    loop(i,0,n)
                    {
                        temp =i;
                        if(ans[i] != '0')
                        break;
                    }
                    loop(i,temp,n)
                    {
                        cout<<ans[i];
                    }
                    cout<<endl;
                }
                break;


        }
    }
    return 0;
}