#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        if (a >= 0 && b >= 0)
        {
            ll cnt1 = 0, cnt2 = 0;
            while (n % 2 == 0)
                n /= 2, cnt1++;
            for (ll i = 3; i <= sqrt(n); i = i + 2)
            {
                while (n % i == 0)
                    cnt2++, n /= i;
            }
            if (n > 2)
                cnt2++;
            cout << a * cnt1 + b * cnt2 << endl;
        }
        else if (b <= 0 && a >= 0)
        {
            ll cnt = 0;
            while (n % 2 == 0)
                n /= 2, cnt++;
            if (cnt == 0)
                cout << b << endl;
            else
                cout << cnt * a << endl;
        }
        else if (a <= 0 && b >= 0)
        {
            ll cnt2 = 0, cnt1 = 0;
            if (!(n & 1))
                while (n % 2 == 0)
                    n /= 2, cnt1 = 1;
            for (ll i = 3; i <= sqrt(n); i = i + 2)
            {
                while (n % i == 0)
                    cnt2++, n /= i;
            }
            if (n > 2)
                cnt2++;
            cout << a * cnt1 + b * cnt2 << endl;
        }
        else
        {
            if (n & 1)
                cout << b << endl;
            else
                cout << a << endl;
        }
    }
    return 0;
}