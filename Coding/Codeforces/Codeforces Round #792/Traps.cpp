#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define deb(x) cout<<#x<<" : "<<x<<"\n";
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\n";
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define setp(n) cout << fixed << setprecision(n)
#define mset(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define checkbit(x,i) (x&(1ll<<i))?1:0
#define setbit(x,i) x|(1ll<<i)
#define compbit(x,i) x^(1ll<<i)
#define ff first
#define ss second
#define mod 1000000007
#define N 100010

template<class T>
T complement(T x){T ans=0;T temp=1;while(x){ans+=((x%2)?0:1)*temp;x>>=1;temp<<=1;}return ans;}

ll pow_mod(ll x,ll y)
{
ll r=1;
for(;y;y>>=1,x=(ll)x*x%mod)
if(y&1)r=(ll)r*x%mod;
return r;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<pair<ll,ll>> v1;
        for(int i=0;i<n;i++){
            v1.push_back(make_pair(v[i]-(n-i-1), i));
            //cout<<v1[i].first<<" ";
        }
        
        sort(v1.begin(),v1.end());
        reverse(v1.begin(),v1.end());
        
        vector<ll> v2(n,0);
        
        for(int i=0;i<k;i++){
            v2[v1[i].second]=1;
        }
        
        ll ans=0,count=0;
        
        for(int i=0;i<n;i++){
            if(v2[i]){
                cout<<i<<endl;
               count++; 
            }
            else{
                ans+=v[i]+count;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
