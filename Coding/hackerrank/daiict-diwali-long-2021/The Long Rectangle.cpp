#include<bits/stdc++.h>
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define out(i,a,n) for(ll i=0;i<n;++i) cout<<a[i]<<" ";
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long int
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define l(a) a.length()
using namespace std;


int main()
{
    fast
    vector<ll> rect;
    rect.pb(2);
    rect.pb(8);
    int t;
    int size=2;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<=size)
        {
            cout<<rect[n-1]<<endl;
            continue;
        }
        loop(i,size,n)
        {
            ll temp = (6*rect[i-1])%mod - (7*rect[i-2])%mod;
            if(temp>mod)
            temp %= mod;
            if(temp<0)
            temp += mod;
            //cout<<6*rect[i-1]<<" "<<7*rect[i-2]<<" "<<temp<<endl;
            rect.pb(temp);
            size++;
        }
        cout<<rect[n-1]<<endl;
    }
    return 0;
}