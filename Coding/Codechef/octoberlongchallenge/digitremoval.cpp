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
int digitremoval0(string s,char ch)
{
    //cout<<"dg0"<<endl;
    int result=0;
    int len=l(s);
    size_t found = s.find(ch);
    //cout<<"found : "<<found<<endl;
    while(found != string::npos)
    {
        if(found == len-1)
        {
        result += 1;
        s[found]++;
        cout<<s<<endl;
        return result;
        }
        else
        {
            if(s[found+1] != '0')
            {
                result += (11-(s[found+1] -'0'))*pow(10,len-1-found-1);
                // cout<<result<<endl;
                s[found] = '1';
                s[found+1] = '1';
                cout<<s<<endl;
            }
            else
            {
                result += pow(10,len-1-found);
                s[found] = '1';
                cout<<s<<endl;
            }
        }
        found = s.find(ch);
    }
    return result;
}
int digitremoval9(string s,char ch)
{
    //cout<<"dg9"<<endl;
    int result=0,a,flag=0,tempresult=0;
    int len=l(s);
    size_t found = s.find(ch);
    //cout<<"found : "<<found<<endl;
    while(found != string::npos)
    {
        tempresult=0;
        loop(j,found+1,len-1)
        {
            tempresult = tempresult*10 + 9-(s[j] -'0');
        }
        tempresult = tempresult*10 + 10-(s[len-1] -'0');
        result += tempresult;
        //cout<<result<<endl;
        if(found==0)
        return result;
        s[found-1]++;
        loop(i,found,len)
        s[i] = '0';
        //cout<<s<<endl;
        found = s.find(ch);
        // cout<<"found : "<<found<<endl;
    }
    return result;
}
int digitremoval(string s,char ch)
{
    //cout<<"dg"<<endl;
    int len=l(s);
    int a,result=0,flag=0;
    loop(i,0,len)
    {
        if(s[i] == ch)
        {
            a=i;
            flag++;
            break;
        }
    }
    if(!flag)
    return 0;
    if(a==len-1)
    return 1;
    loop(i,a+1,len-1)
    {
        result = result*10 + 9-(s[i] -'0'); 
    }
    
    result = result*10 + 10-(s[len-1] -'0'); 
    return result;
}

int main()
{
    fast
    int t,n;
    cin>>t;
    string s;
    char ch;
    while(t--)
    {
        cin>>s;
        getchar();
        cin>>ch;
        getchar();
        n = ch - '0';
        //cout<<n<<endl;
        switch(n)
        {
            case 0:
            cout<<digitremoval0(s,ch)<<endl;
            break;
            case 9:
            cout<<digitremoval9(s,ch)<<endl;
            break;
            default:
            cout<<digitremoval(s,ch)<<endl;
        }
    }
    return 0;
}