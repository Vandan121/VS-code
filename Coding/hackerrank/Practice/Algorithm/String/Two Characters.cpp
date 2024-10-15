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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> freq;
    vector<int> v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15,v16,v17,v18,v19,v20,v21,v22,v23,v24,v25,v26;
    loop(i,0,n)
    {
        if(s[i] == 'a' )
        {
        v1.push_back(i);
        continue;
        }
    if(s[i] == 'b' )
        {
        v2.push_back(i);
        continue;
        }
    if(s[i] == 'c' )
        {
        v3.push_back(i);
        continue;
        }
    if(s[i] == 'd' )
        {
        v4.push_back(i);
        continue;
        }
    if(s[i] == 'e' )
        {
        v5.push_back(i);
        continue;
        }
    if(s[i] == 'f' )
        {
        v6.push_back(i);
        continue;
        }
    if(s[i] == 'g' )
        {
        v7.push_back(i);
        continue;
        }
    if(s[i] == 'h' )
        {
        v8.push_back(i);
        continue;
        }
    if(s[i] == 'i' )
        {
        v9.push_back(i);
        continue;
        }
    if(s[i] == 'j' )
        {
        v10.push_back(i);
        continue;
        }
    if(s[i] == 'k' )
        {
        v11.push_back(i);
        continue;
        }
    if(s[i] == 'l' )
        {
        v12.push_back(i);
        continue;
        }
    if(s[i] == 'm' )
        {
        v13.push_back(i);
        continue;
        }
    if(s[i] == 'n' )
        {
        v14.push_back(i);
        continue;
        }
    if(s[i] == 'o' )
        {
        v15.push_back(i);
        continue;
        }
    if(s[i] == 'p' )
        {
        v16.push_back(i);
        continue;
        }
    if(s[i] == 'q' )
        {
        v17.push_back(i);
        continue;
        }
    if(s[i] == 'r' )
        {
        v18.push_back(i);
        continue;
        }
    if(s[i] == 's' )
        {
        v19.push_back(i);
        continue;
        }
    if(s[i] == 't' )
        {
        v20.push_back(i);
        continue;
        }
    if(s[i] == 'u' )
        {
        v21.push_back(i);
        continue;
        }
    if(s[i] == 'v' )
        {
        v22.push_back(i);
        continue;
        }
    if(s[i] == 'w' )
        {
        v23.push_back(i);
        continue;
        }
    if(s[i] == 'x' )
        {
        v24.push_back(i);
        continue;
        }
    if(s[i] == 'y' )
        {
        v25.push_back(i);
        continue;
        }
    if(s[i] == 'z' )
        {
        v26.push_back(i);
        continue;
        }
    }
    freq.push_back(v1);
    freq.push_back(v2);
    freq.push_back(v3);
    freq.push_back(v4);
    freq.push_back(v5);
    freq.push_back(v6);
    freq.push_back(v7);
    freq.push_back(v8);
    freq.push_back(v9);
    freq.push_back(v10);
    freq.push_back(v11);
    freq.push_back(v12);
    freq.push_back(v13);
    freq.push_back(v14);
    freq.push_back(v15);
    freq.push_back(v16);
    freq.push_back(v17);
    freq.push_back(v18);
    freq.push_back(v19);
    freq.push_back(v20);
    freq.push_back(v21);
    freq.push_back(v22);
    freq.push_back(v23);
    freq.push_back(v24);
    freq.push_back(v25);
    freq.push_back(v26);
    debug(freq)
    int temp=0;
    loop(i,0,26)
    {
        int size1 = freq[i].size();
        loop(j,i+1,26)
        {
            int size2=freq[j].size();
            if(abs(size1 - size2)>1) continue;
            else if(size1 && size2)
            {
                if(size1 > size2)
                {
                    vector<int>cmp,cmp1;
                    loop(k,0,size1)
                    {
                        cmp.pb(freq[i][k]); 
                        cmp1.pb(freq[i][k]); 
                        if(k<size2)
                        {
                            cmp.pb(freq[j][k]); 
                            cmp1.pb(freq[j][k]);
                        }
                    }
                    // cout<<"vector before sorting :"<<endl;
                    // loop(vs,0,size1+size2)
                    // {
                    //     cout<<cmp[vs]<<" ";
                    // }
                    // cout<<endl;
                    sort(all(cmp));
                    // cout<<"vector afer sorting :"<<endl;
                    // loop(vs,0,size1+size2)
                    // {
                    //     cout<<cmp[vs]<<" ";
                    // }
                    // cout<<endl;
                    if(cmp == cmp1)
                    {
                        temp = max(temp,size1+size2);
                    }
                }
                if(size2 > size1)
                {
                    //cout<<i<<" hi"<<endl;
                    vector<int>cmp,cmp1;
                    loop(k,0,size2)
                    {
                        cmp.pb(freq[j][k]); 
                        cmp1.pb(freq[j][k]); 
                        if(k<size1)
                        {
                            cmp.pb(freq[i][k]); 
                            cmp1.pb(freq[i][k]);
                        }
                    }
                    sort(all(cmp));
                    if(cmp == cmp1)
                    {
                        temp = max(temp,size1+size2);
                    }
                }
                else if(size1 == size2)
                {
                    
                    vector<int>cmp,cmp1;
                    loop(k,0,size2)
                    {
                        if(freq[j][0] > freq[i][0])
                        {
                            cmp.pb(freq[i][k]); 
                            cmp1.pb(freq[i][k]);
                            cmp.pb(freq[j][k]); 
                            cmp1.pb(freq[j][k]);
                        }
                        else
                        {

                        cmp.pb(freq[j][k]); 
                        cmp1.pb(freq[j][k]); 
                        cmp.pb(freq[i][k]); 
                        cmp1.pb(freq[i][k]);
                        }
                        
                    }
                    sort(all(cmp));
                    if(cmp == cmp1)
                    {
                        temp = max(temp,size1+size2);
                    }
                }
            }
        }
    }
    cout<<temp;
    return 0;
}