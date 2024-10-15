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
int digits(ll a)
{
    loop(i,0,8)
    {
        if(a < pow(10,i))
        return i;
    }
}

int main()
{
    fast
    int t;
    cin>>t;
    while(t--)
    {
        ll n,l,r,temp1,temp2;
        int pairs=0;
        cin>>n>>l>>r;
        int sizeofl = digits(l);
        int sizeofr = digits(r);
        ll a[n],sizeofa[n];
        ll tens[n];
        loop(i,0,n)
        {
            cin>>a[i];
            sizeofa[i] = digits(a[i]);
            tens[i] = pow(10,sizeofa[i]);
        }
        // 2 4 6 8 10 12 14 673 22774 2928772 2984789 l=5000 r=100000
        // -1 0 4 7 -1 8 -1 9 
        loop(i,0,n)
        {
            loop(j,i,n)
            {
                int test = (sizeofa[i] + sizeofa[j]);
                if(test>=sizeofl && test<=sizeofr)
                {
                    temp1 = a[j]*tens[i] + a[i];
                    temp2 = a[i]*tens[j] + a[j];
                    if(l<=temp1 && temp1<=r)
                    pairs++;
                    if(i==j)
                    continue;
                    if(l<=temp2 && temp2<=r)
                    pairs++;
                }
            }
        }
        cout<<pairs<<endl;
    }
    return 0;
}