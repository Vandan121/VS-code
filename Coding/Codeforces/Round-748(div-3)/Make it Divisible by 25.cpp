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

//3450045
int main()
{
    fast
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        ll ans =INT_MAX;
        int len=l(s),opr=0;
        loop(i,0,len)
        {
            if(s[i] == '0' || s[i] == '5')
            {
                loop(j,i+1,len)
                {
                    if(s[j]=='0')
                    {
                        ans = min(ans,(j-i-1)+len-j-1);
                    }
                }
            }
            if(s[i] == '2' || s[i] == '7')
            {
                loop(j,i+1,len)
                {
                    if(s[j]=='5')
                    {
                        ans = min(ans,(j-i-1)+len-j-1);
                    }
                }
            }
        }      
        cout<<ans<<endl;
    }
    return 0;
}