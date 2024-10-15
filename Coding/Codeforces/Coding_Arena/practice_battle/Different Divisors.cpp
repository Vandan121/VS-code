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
    vector<int> prime;
    int n=20100;
    prime.pb(2);
    prime.pb(3);
    for (int i=2; i<n; i++)
    {
        for (int j=2; j*j<=i; j++)
        {
           if (i % j == 0)
           break;
           else if (j+1 > sqrt(i)) {
           prime.pb(i);
        }
        }
    }
    
    while(t--)
    {
        int d,f1,f2;
        cin>>d;
        loop(i,0,prime.size())
        {
            if((prime[i]-1)>=d)
            {
                f1 = prime[i];
                break;
            }
        }
        loop(i,0,prime.size())
        {
            if((prime[i]-f1)>=d)
            {
            f2 = prime[i];
            break;
            }
        }
        cout<<f1*f2<<endl;
        
    }
    return 0;
}