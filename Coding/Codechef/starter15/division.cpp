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

void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        cout << n << " ";
}
int main()
{
    fast
    int t,a,b,n,odd=0,even=0,m;
    cin>>t;
    while(t--)
    {
        odd=0,even=0;
        cin>>n>>a>>b;
        m=n;
        while (n % 2 == 0)
        {
            even++;
            n = n/2;
        }
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                odd++;
                n = n/i;
            }
        }
        if (n > 2)
            odd++;
        //cout<<even<<" "<<odd<<endl;
        if(a>=0 && b>=0)
        {
            cout<<(a*even + b*odd)<<endl;
        }
        else if(a>=0 && b<=0)
        {
            if(even>0)
            {
                cout<<even*a<<endl;
            }
            else
            cout<<b<<endl;
        }
        else if(a<=0 && b>=0)
        {
            if(even>0 && odd>0)
            {
                cout<<a + odd*b<<endl;
            }
            else
            {
                if(odd==0)
                cout<<a<<endl;
                else
                cout<<odd*b<<endl;
            }
        }
        else
        {
            if(m%2==0)
            cout<<a<<endl;
            else
            cout<<b<<endl;
        }
    }
    return 0;
}