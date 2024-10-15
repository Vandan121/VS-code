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
        long long rem=0,sum=0,n;
        cin>>n;
        if(n==1)
        {
            cout<<"1 1"<<endl;
            continue;
        }
        for(int i=1;i<n-1;i++)
        {
            cout<<i<<" ";
            sum += i;
        }
        cout<<n-1<<" ";
        sum += n-1;
        cout<<n-1<<" ";
        sum += n-1;
        long long power = pow(2,n);
        rem = power - sum;
        cout<<rem<<endl;
    }

    return 0;
}