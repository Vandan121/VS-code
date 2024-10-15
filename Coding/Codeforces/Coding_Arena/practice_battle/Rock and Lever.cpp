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
    int t;
    cin>>t;
    // int powof2[33];
    // powof2[0] = 1;
    // loop(i,1,33)
    // powof2[i] = 2*powof2[i-1];
    while(t--)
    {
        ll n,pairs=0,power=0;
        cin>>n;
        vector<ll> arr(n);
        loop(i,0,n)
        cin>>arr[i];
        sort(all(arr));
        vector<ll> final;
        ll i=0;
        while(i<n)
        {
            pairs=0;
            ll temp = pow(2,power);
            while(i<n)
            {
                if(temp<= arr[i] && arr[i] < (2*temp))
                {
                    pairs++;
                    i++;
                }
                else
                break;
            }
            //cout<<pairs<<endl;
            final.pb(pairs);
            power++;
        }
        pairs =0;
        loop(i,0,final.size())
        {
            if(final[i]>1)
            {
                ll temp = (final[i]-1)*final[i];
                temp /= 2;
                pairs += temp;
            }
        }
        cout<<pairs<<endl;
    }
    return 0;
}