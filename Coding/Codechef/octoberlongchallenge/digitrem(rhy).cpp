#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t>0){
        int n,d;
        cin>>n>>d;
        int x=n,r=0,c=0,ans=0;
    while(x>0)
    {
        r=x%10;
        x = x/10;
        c++;
        if(r==d)
        {
            x=x*pow(10,c)+(r+1)*pow(10,c-1);
            ans=x-n;
            cout<<ans<<endl;
            c=0;
        }
    }
    cout<<ans<<endl;
    t--;
    }
    
    

    return 0;
}