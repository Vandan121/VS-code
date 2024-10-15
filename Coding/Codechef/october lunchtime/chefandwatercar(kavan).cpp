#include <bits/stdc++.h> 
#define ll long long int 
#define ull unsigned long long int 
#define setbits(x) __builtin_popcountll(x) 
#define lcm(a,b) (a*b*1LL)/__gcd(a,b)
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define l(a) a.length()
#define fr first
#define sc second
#define mod 1000000007
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define size(v) (int)v.size()
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n,v;
        cin>>n>>v;
        ll maxi = n*(n-1)/2;
        ll i =1;
        ll mini= 0;
        ll m =n-1;
        if(v==1)
        {
            cout << maxi << " "<<maxi<<endl;
            continue;
        }
        while (m>0)
        {
            mini+=min(v,m)*i;
            i++;
            m-=min(v,m);
        }
        cout << maxi <<" "<<mini<<endl;
    }
}