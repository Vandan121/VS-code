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
        int n;
        cin>>n;
        ll a[n];
        int temp1=0,temp2=0,temp=0;
        loop(i,0,n)
        {
            cin>>a[i];
            if(a[i]%3==1)
            temp1++;
            if(a[i]%3==2)
            temp2++;
            temp+=a[i]%3;
        }
        if(temp%3 !=0)
        cout<<"-1"<<endl;
        else
        {
            int ans;
            if(temp1>temp2)
            {
                ans=temp2;
                ans += (((temp1-temp2)/3)*2);
            }
            else if(temp1==temp2)
            {
                ans = temp1;
            }
            else 
            {
                ans = temp1;
                ans += (((temp2-temp1)/3)*2);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}