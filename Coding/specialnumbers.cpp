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
    int modulo = (pow(10,9)+7);
    while(t--)
    {
        vector<ll> sum;
        ll n,k,temp,length;
        cin>>n>>k;
        sum.pb(1);
        ll index=1,power=1;
        while(index<k)
        {
            length=index;
            temp = pow(n,power);
            sum.pb(temp);
            index++;
            loop(i,0,length)
            {
                if(index == k)
                break;
                temp = pow(n,power);
                temp += sum[i];
                temp = temp%modulo;
                sum.pb(temp);
                index++;
            }
            power++;
        }
        // loop(i,0,index)
        // cout<<sum[i]<<" ";
        // cout<<endl;
    cout<<(sum[k-1]%modulo)<<endl;
    }
    return 0;
}