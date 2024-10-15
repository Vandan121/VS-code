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
    string str;
    cin>>str;
    int substr=n,temp=0;
    vector<int> ele;
    char c=str[0];
    loop(i,0,n)
    {
        if(str[i] != c)
        {
            ele.pb(temp);
            c = str[i];
            temp=1;
        }
        else
        temp++;
    }
    ele.pb(temp);
    //dis(ele);
    loop(i,0,ele.size())
    {
        int temp=2;
        loop(j,i+1,ele.size())
        {
            if(ele[j]<temp)
            break;
            else if(ele[j]>temp)
            {
                substr++;
                break;
            }
            else
            {
                temp *= 2;
                substr++;
            }
        }
        
    }
    cout<<substr<<endl;
    return 0;
}