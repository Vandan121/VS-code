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
#define endl '\n'
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



int main()
{
    fast int n;
    cin >> n;
    
        vector<int> first;
    int rem = n % 4;
    int num = n / 4;
    int diff;

    if (rem == 1)
    {
        diff = 1;
        int temp = n;
        while (temp > 1)
        {
            first.push_back(temp);
            temp -= 3;
            first.push_back(temp);
            temp--;
        }
    }
    else if (rem == 2)
    {
        diff = 1;
        int temp = 1;
        while (temp < n)
        {
            first.push_back(temp);
            temp += 3;
            first.push_back(temp);
            temp++;
        }
    }
    else if (rem == 3)
    {
        diff = 0;
        int temp = n;
        while (temp > 0)
        {
            first.push_back(temp);
            temp -= 3;
            first.push_back(temp);
            temp--;
        }
    }
    else if (rem == 0)
    {
        diff = 0;
        int temp = 1;
        while (temp <= 4)
        {
            first.push_back(temp);
            temp += 3;
            first.push_back(temp);
            temp++;
        }
    }


cout << diff << endl;
int final = 0;
loop(i, 0, first.size())
{
    if (first[i] < 1 || first[i] > n)
        continue;
    final++;
}
cout << final << " ";
loop(i, 0, first.size())
{
    if (first[i] < 1 || first[i] > n)
        continue;
    cout << first[i] << " ";
}
return 0;
}