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
vector<int> gifts,gindex,rindex;
int binarysearch(int l,int r,int value)
{
    if(r>=l)
    {
        int mid = l + (r-l)/2;
        if(rindex[mid] == value)
        return mid;
        else if(rindex[mid] > value)
        return binarysearch(l,mid-1,value);
        else if(rindex[mid] < value)
        return binarysearch(mid+1,r,value);
    }
    return -1;
}
// 2 3 7 8 9

int main()
{
    fast
    int n,temp;
    cin>>n;
    vector<int> rem(n,-1);
    loop(i,0,n)
    {
        temp=0;
        //cin>>temp;
        gifts.pb(temp);
        if(temp>0)
        {
            rem[gifts[i]-1] = 1;
        }
        if(temp==0)
        gindex.pb(i+1);
    }
    loop(i,0,n)
    {
        if(rem[i]<0)
        rindex.pb(i+1);
    }
    //gifts[gindex[0]-1] = rindex[rindex.size()-1];
    temp=gindex.size();
    //vector<int>::iterator it;
    for(int i=0;i<gindex.size();i++)
    {
        int it = binarysearch(0,rindex.size()-1,gindex[i]);
        //cout<<it<<endl;
        
        if(it==-1)
        continue;
        int num=0;
        if(num == it)
        {
            num++;
        }
        gifts[gindex[i]-1] = rindex[num];
        rindex.erase(rindex.begin()+num);     
        gindex.erase(gindex.begin()+i);  
        i--;
        // for(int i1=0;i1<gindex.size();i1++)
        // {
        //     cout<<gindex[i1]<<" ";
        // }
        // cout<<endl;
        // for(int i1=0;i1<rindex.size();i1++)
        // {
        //     cout<<rindex[i1]<<" ";
        // }
        // cout<<endl;     
    }
    temp=gindex.size();
    loop(i,0,temp)
    {
        gifts[gindex[i]-1] = rindex[0];
        rindex.erase(rindex.begin()+0);        
    }
    // loop(i,0,gindex.size())
    // cout<<gindex[i]<<" ";
    // cout<<endl;
    // loop(i,0,rindex.size())
    // cout<<rindex[i]<<" ";
    // cout<<endl;
    loop(i,0,n)
    cout<<gifts[i]<<" ";
    cout<<endl;
    // loop(i,0,gindex.size())
    // cout<<gindex[i]<<" ";
    // cout<<endl;
    // loop(i,0,rindex.size())
    // cout<<rindex[i]<<" ";
    // cout<<endl;

    return 0;
}

