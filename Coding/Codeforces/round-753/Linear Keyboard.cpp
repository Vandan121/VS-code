#include<bits/stdc++.h>
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define out(i,a,n) for(ll i=0;i<n;++i) cout<<a[i]<<" ";
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) {for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;}
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
        vector<int> alpha(26,0);
        string s,s1;
        cin>>s;
        getchar();
        cin>>s1;
        if(l(s1) == 1)
        {
            cout<<"0"<<endl;
            continue;
        }
        loop(i,0,26)
        {
            alpha[s[i] - 97] = i+1;
        }
        // loop(i,0,26)
        // cout<<alpha[i]<<" ";
        int ans=0;
       loop(i,1,l(s1))
        {
            ans += abs(alpha[s1[i-1]-97]-alpha[s1[i]-97]);
        }
        cout<<ans<<endl;
    }
    return 0;
}