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
        ll n,k;
        cin>>n>>k;
        vector<ll> height(n);
        map<ll,ll> M;
        loop(i,0,n)
        {
            cin>>height[i];
        }
        vector<int> time(100,0);
        loop(i,0,n)
        {
            ll temp = height[i],times=0;
            while(temp%k==0 && temp>0)
            {
                times++;
                temp = temp/k;
            }
            //cout<<"time :"<<times<<endl;
            time[times]++;
        }
        sort(all(time));
        cout<<time[99]<<endl;
    }
    return 0;
}