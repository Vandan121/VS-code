#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long hc,dc,hm,dm,k,w,a;
        cin>>hc>>dc>>hm>>dm>>k>>w>>a;
        if((w==0&&a==0)||k==0){
            if((hc/dm)>=(hm/dc)){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            int flag=1;
            ll x=0,y=0;
            
            for(long long i=0;i<=k;i++){
                 x=(hc+i*a)/dm;
                 y=hm/(dc+(k-i)*w);
                if(x>=y){
                    cout<<"YES\n";
                    flag=0;
                    break;
                }
            }
            if(flag){
                cout<<"NO\n";
            }
        }
    }
    return 0;
}
