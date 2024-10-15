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
        ll n, m;
        cin >> n >> m;
        if (m == n - 1)
        {
            loop(i, 1, n)
                    cout
                << i << " " << i + 1 << endl;
        }
        else if (m == n)
        {
            cout << "1 2" << endl;
            cout << "2 3" << endl;
            cout << "1 3" << endl;
            loop(i, 3, n)
                    cout
                << i << " " << i + 1 << endl;
        }
        else
        {
            loop(i, 1, n)
                    cout
                << i << " " << i + 1 << endl;
            cout << 1 << " " << n << endl;
            vector<pair<int, int>> edges;
            loop(i, 1, n + 1)
            {
                int temp = 2;
                loop(j, 1, n - 2)
                {
                    if (i + temp <= n)
                    {
                        edges.pb(mk(i, i + temp));
                        temp++;
                    }
                    else
                        break;
                }
            }
            loop(i, 0, m - n)
                    cout
                << edges[i].first << " " << edges[i].second << endl;
        }
    }
    return 0;
}