#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if(a+b <= d && c<=e)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else if(b+c <= d && a<=e)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else if(a+c <= d && b<=e)
        {
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
}