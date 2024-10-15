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
    int n;
    cin>>n;
    vector<int> start(n),end(n);
    in(start,n);
    in(end,n);
    vector<pair<int,int>> days;
        for(int i=0;i<n;i++)
        days.push_back(make_pair(end[i],start[i]));
        sort(days.begin(),days.end());
        int act=0,ends;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            act++;
            ends = days[i].first+1;
        }
        if(days[i].second >= ends)
        {
            act++;
            ends = days[i].first+1;
        }
    }
    cout<<act<<endl;
    return 0;
}