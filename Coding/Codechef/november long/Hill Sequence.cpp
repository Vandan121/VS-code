#include <bits/stdc++.h>
#define loop(i, a, b) for (ll i = a; i < b; ++i)
#define in(a, n)               \
    for (ll i = 0; i < n; ++i) \
        cin >> a[i];
#define out(i, a, n)           \
    for (ll i = 0; i < n; ++i) \
        cout << a[i] << " ";
#define pb push_back
#define mk make_pair
#define all(v) v.begin(), v.end()
#define dis(v)            \
    for (auto i : v)      \
        cout << i << " "; \
    cout << endl;
#define display(arr, n)         \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";  \
    cout << endl;
#define rloop(i, a, b) for (ll i = a; i >= b; i--)
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define l(a) a.length()
using namespace std;

int main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> hills(n);
        vector<ll> index;
        loop(i, 0, n)
                cin >>
            hills[i];
        if (n == 1)
        {
            cout << hills[0] << endl;
            continue;
        }
        sort(all(hills));
        if (hills[0] == hills[n - 1])
        {
            cout << "-1" << endl;
            continue;
        }
        if (hills[n - 2] == hills[n - 1])
        {
            cout << "-1" << endl;
            continue;
        }
        int flag = 0;
        ll i = 0;
        while (i < n - 2)
        {
            if (hills[i] == hills[i + 1])
            {
                index.pb(i);
                if (hills[i] == hills[i + 2])
                {
                    flag = 1;
                }
            }
            i++;
        }
        if (flag == 1)
        {
            cout << "-1" << endl;
            continue;
        }
        int j = 0;
        while (j < index.size())
        {
            cout << hills[index[j]] << " ";
            hills[index[j]] = 0;
            j++;
        }
        cout << hills[n - 1] << " ";
        hills[n - 1] = 0;
        rloop(i, hills.size() - 1, 0)
        {
            if (hills[i])
                cout << hills[i] << " ";
        }
        cout << endl;
    }
    return 0;
}