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
        int n;
        cin>>n;
        vector<ll> num(n);
        int min=INT_MAX,ind,min_max;
        loop(i,0,n)
        {
            cin>>num[i];
            if(min>num[i])
            {
                min = num[i];
                ind = i;
            }
        }
        min_max = min;
        while(num.size()>1)
        {
            num.erase(num.begin() + ind);
            loop(i,0,num.size())
            {
                num[i] -= min;
            }
            min=INT_MAX;
            loop(i,0,num.size())
            {
                if(min>num[i])
                {
                    min = num[i];
                    ind = i;
                }
            }
            if(min_max<min) min_max = min; 
        }
        cout<<min_max<<endl;
    }
    return 0;
}