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
    ll t,length,flag,a;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>length;
        getchar();
        cin>>s;
        ll len = l(s),cnt=0;
        loop(i,0,len-1)
        {
            flag=1;
            a=i+1;
            while(a<len && flag<=9)
            {
                if(flag == (abs(s[a] - s[i])))
                {
                    //cout<<j<<" "<<i<<endl;
                cnt++;
                }
                flag++;
                a++;
            }
        }
        cout<<cnt<<endl;
    }
    
    return 0;
}   