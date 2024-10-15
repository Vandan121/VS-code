#include <iostream>
#define ll long long
using namespace std;
// 0    00000
// 1	00001
// 2	00010
// 3	00011
// 4	00100
// 5	00101
// 6	00110
// 7	00111
// 8	01000
// 9	01001
// 10	01010
// 11	01011
// 12	01100
// 13	01101
// 14	01110
// 15	01111
// 16	10000
// 17	10001
// 18	10010
// 19	10011
// 20	10100
// 21	10101
// 22	10110
// 23	10111
// 24	11000
// 25	11001
// 26	11010
// 27	11011
// 28	11100
// 29	11101
// 30	11110
ll power_2(ll n)
{
    ll res = 0,kk = 1;
    while(kk<=n) kk*=2;
    res = kk/2;
    return res;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        if(x == 0) cout<<"1"<<endl;
        else if(x==1 || x==2) cout<<"2"<<endl;
        else{
            ll ans = power_2(x);
            if(ans == x)
            cout<<x<<endl;
            else if(x == (2*ans-1))
            cout<<x+1<<endl;
            else
            cout<<ans<<endl;
        }
    }
    return 0;
}