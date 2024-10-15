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
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define l(a) a.length()
using namespace std;


int main()
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> alpha(n),alpha1;
        loop(i,0,n)
        {
            cin>>alpha[i];
            if(alpha[i]%2 !=0)
            alpha1.pb(alpha[i]); 
        }
        if(alpha1.size() <=1)
        {
            cout<<"0"<<endl;
            continue;
        }
        cout<<alpha1.size()/2<<endl;
    }   
    return 0;
}