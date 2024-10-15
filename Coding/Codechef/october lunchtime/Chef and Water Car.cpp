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
    while(t--)
    {
        ll n,v,km,temp=1;
        cin>>n>>v;
        km=n-1;
        ll max = (n*(n-1))/2,min=0;
        if(v==1)
        {
            cout<<max<<" "<<max<<endl;
            continue;
        }
        if(v>=n)
        {
            cout<<max<<" "<<n-1<<endl;
            continue;
        }
        if(n==1)
        {
            cout<<"0 0"<<endl;
            continue;
        }
        ll temp1 = km/v;
        ll last = 1 + (temp1-1)*v;
        min = v*(temp1)*(1 + last);
        min = min/2;
        int x = (n-last-v);
        // loop(i,1,x+1)
        // {
        //     min += last + i;
        // }
        min += last*x + (x*(x+1))/2;
        // while(km/v)
        // {
        //     km = km-v;
        //     min += v*temp;
        //     temp += v;
        // }
        // min += km*temp;
        // if(max==min)
        // cout<<"1"<<endl;
        // else
        // cout<<"0"<<endl;
        cout<<max<<" "<<min<<endl;
    }
    return 0;
}