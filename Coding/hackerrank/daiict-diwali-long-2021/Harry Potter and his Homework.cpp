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


ll add(ll x,ll y)  {ll ans = x+y; return (ans>=mod ? ans - mod : ans);}
ll sub(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod : ans);}
ll mul(ll x,ll y)  {ll ans = x*y; return (ans>=mod ? ans % mod : ans);}
int main()
{
    fast
    ll n,q; string s; cin>>n>>q>>s;
    vector<ll> starting(n,0),ending(n,0);       starting[0] = 0;
    vector<pair<ll,ll>> values(n,{0,0});
    ll temp = 0;
    //10100101011101
    // 0 0 0 0 4 4 4 4 4 4 10 11 11 11 
    // 3 3 3 3 9 9 9 9 9 9 10 13 13 13
    // 1000111101
    // 0 0 2 3 3 5 6 7 7 7 
    // 1 1 2 4 4 5 6 9 9 9
    loop(i,1,n){
        ll value = i;
        while(i < n && s[i]!=s[i-1]) i++;
        loop(j,temp,i) ending[j] = i-1;
        temp = i;  
    }
    loop(i,0,n-1){
        ll value = i;
        while(i < n-1 &&s[i] != s[i+1]) i++;
        if(i == n-2 && s[i+1]!=s[i])    i++;
        loop(j,value,i+1)   starting[j] = value;
    }
    if(ending[n-1] == 0) ending[n-1] = n-1;
    if(starting[n-1] == 0 && s[n-1]==s[n-2]) starting[n-1] = n-1;
    ll prev = 0,value = 0;
    loop(i,1,n){
        ll cnt = 1;
        while(i<n && s[i] != s[i-1])  i++,cnt++;
        loop(j,value,i) values[j].fr = prev;
        loop(j,value,i) values[j].sc = prev + (cnt*(cnt+1))/2;
        prev += (cnt*(cnt+1))/2;    value = i;
    }
    if(s[n-1]==s[n-2])  values[n-1].fr = values[n-2].sc,values[n-1].sc = values[n-2].sc+1;
    // dis(starting);
    // dis(ending);
    // loop(i,0,n) cout<<values[i].fr<<" "<<values[i].sc<<endl;
    while(q--){
        ll l,r; cin>>l>>r;
        if(l == r)  cout<<1<<endl;
        else{
            ll k1 = ending[l-1],k2 = starting[r-1];
            // cout<<k1<<" "<<k2<<endl;
            if(ending[l-1] == ending[r-1])  cout<<((r-l+1)*(r-l+2))/2<<endl;
            else{
                ll sum = ((k1 - l + 2)*(k1-l+3))/2 + ((r-k2)*(r-k2+1))/2;
                sum+=max(0LL,values[r-1].fr - values[l-1].sc);
                cout<<sum<<endl;
            }
        }
    }
    return 0;
}