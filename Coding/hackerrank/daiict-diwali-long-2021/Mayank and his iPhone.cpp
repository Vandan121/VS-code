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
#define e1(i) cn[i].first
#define e2(i) cn[i].second
using namespace std;


int main()
{
    fast
    int t;
    cin>>t;
    while(t--)
    {
        ll n,s1,s;
        int flag[4] = {0};
        cin>>n>>s1;
        s=s1;
        vector<pair<int,int> >cn;
        loop(i,0,n)
        {
            int temp = s%10;
            if(temp==0)
            {
                cn.pb(mk(3,1));
                s = s/10;
                flag[0] = -1;
                flag[1] = -1;
                flag[2] = -1;
                continue;
            }
            temp--;
            cn.pb(mk(temp/3,temp%3));
            s = s/10;
        }
        // rloop(i,n-1,0)
        // cout<<cn[i].first<<" "<<cn[i].second<<endl;
        if(flag[0] != -1)
        {
            loop(i,0,n)
            {
                if(e2(i)+1 == 3)
                {
                    flag[0]=-1;
                    break;
                }
            }
        }
        if(flag[1] != -1)
        {
            loop(i,0,n)
            {
                if((e2(i)-1)==-1)
                {
                    flag[1]=-1;
                    break;
                }
            }
        }
        if(flag[2] != -1)
        {
            loop(i,0,n)
            {
                if((e1(i)+1)==3)
                {
                    if(e2(i) != 1)
                    {
                        flag[2]=-1;
                        break;
                    }
                }
            }
        }
        if(flag[3] != -1)
        {
            loop(i,0,n)
            {
                if((e1(i)-1)==-1)
                {
                    flag[3]=-1;
                    break;
                }
            }
        }
        if(flag[0]+flag[1]+flag[2]+flag[3] == -4)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

        // if(x[0]==0 && x[n-1]==3)
        // {
        //     cout<<s1<<endl;
        //     cout<<"YES"<<endl;
        //     continue;
        // }
        // if(x[0]==0 && x[n-1]==2 && y[0]==0 && y[n-1]==2)
        // {
        //     cout<<s1<<endl;
        //     cout<<"YES"<<endl;
        //     continue;
        // }
        // cout<<s1<<endl;
        // cout<<"NO"<<endl;
    }
    return 0;
}