#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ul;
#define gcd(x,y) __gcd(x,y)
#define M 1000000007
#define fr(i,s,e) for(ll i=s;i<e;i++)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int,int>
#define all(a) a.begin(),a.end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
bool comp(pair<int,int> a,pair<int,int> b)
{
    if(a.ss>b.ss)
    return true;
    else if(a.ss == b.ss)
    return(a.ff>b.ff);
    return false;
}
vector<pair<ll,ll>> Sort(map<ll,ll> &m)
{
  vector<pair<ll,ll>> a;
  for(auto it:m)
  {
      a.pb({it.ff,it.ss});
  }
  sort(all(a),comp);
  return a;
}
ll Log[100001];
ll Max_t[100001][17];
ll Max_value(int l,int r)
{
    int len = r-l+1;
    int t = Log[len];
    // if(len == (1<<t))
    // return Max_t[l-1][t];
    // else 
    return max(Max_t[l-1][t],Max_t[r-(1<<t)][t]);
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     int n,k;
     cin>>n;
     map<ll,ll> m;
     for(int i=0;i<n;i++) 
     {
        cin>>k;
        m[k]++; 
     }
     if(m.size() == n)
     {
         cout<<n<<"\n";
         continue;
     }
     map<ll,ll> c;
     for(auto it:m)
     {
        c[it.ss]++;   
     }
     int mx = INT_MIN,numofele = 0;
    //  for(auto it:c)
    //  {
    //      cout<<it.ff<<" "<<it.ss<<"\n";
    //  }
     for(auto it:c)
     {
         if(mx<=it.ss)
         {
             mx = it.ss;
             numofele = it.ff;
         }
     }
     //cout<<mx<<" "<<numofele<<"\n";
     long long ans = mx*(numofele);
     //cout<<"a: "<<ans<<"\n";
     for(auto it:c)
     {
         if(it.ff>numofele)
         {
             ans += (numofele)*(it.ss) ;
         }
     }
     cout<<ans<<"\n";
   }
   return 0;
}
/*
3
6
1 2 4 5 1 2
8
10 12 12 16 16 13 13 13
4
5 4 5 5
*/