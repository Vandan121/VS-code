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
    ll n,h,max1,max2,max3,max4,max;
    cin>>n;
    vector<ll> add(n);
    loop(i,0,n)
    cin>>add[i];
    cin>>h;
    sort(all(add));
    if(n==1)
    {
        cout<<"0";
        return 0;
    }
    int ind;
    // loop(i,0,n)
    // cout<<add[i]<<" ";
    // cout<<endl;
    if(h<=add[0])
    {
        cout<<add[n-2]-h;
        return 0;    
    }
    else if(h>=add[n-1])
    {
        cout<<h-add[1];
        return 0;    
    }
    loop(i,0,n)
    {
        //cout<<"i :"<<i<<endl;
        if(h<add[i])
        {
            //cout<<"hi"<<endl;
            ind = i;
            break;
        }
    }
    // cout<<"ind :"<<ind<<endl;
    // cout<<"h :"<<h<<endl;
    if(ind == n-1)
    {
        max1 = h-add[0];
        max2 = h-add[1] + 2*(add[n-1]-h);
        if(max1 <= max2)
        cout<<max1;
        else
        cout<<max2;
        return 0;
    }
    //cout<<"a"<<endl;
    else if(ind == 1)
    {
        max1 = add[n-1]-h;
        max2 = add[n-2]-h + 2*(h-add[0]);
        if(max1 <= max2)
        cout<<max1;
        else
        cout<<max2;
        return 0;
    }
    max1 = 2*(h-add[1]) + add[n-1] -h; 
    max2 = (h-add[0]) + 2*(add[n-2] -h); 
    max3 = 2*(h-add[0]) + (add[n-2] -h); 
    max4 = (h-add[1]) + 2*(add[n-1] -h); 
    max = max1;
    if(max2 < max) max = max2;
    if(max3 < max) max = max3;
    if(max4 < max) max = max4;
    cout<<max;
    return 0;
}