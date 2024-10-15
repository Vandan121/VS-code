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
    fast int t;
    cin >> t;
    vector<int> v(31);
    v[0] = 1;
    loop(i, 1, 31)
    {
        v[i] = 2 * v[i - 1];
    }
    while (t--)
    {
        int n, i = 0;
        cin >> n;
        if (n == 1)
        {
            cout << "1" << endl;
            continue;
        }
        else if (n == 2)
        {
            cout << "1" << endl;
            continue;
        }
        else
        {
            while (1)
            {
                if (v[i] < n && n <= v[i + 1])
                {
                    if(n == v[i+1])
                    n = n-1;
                    break;
                }
                else
                    i++;
            }
            int temp = n-v[i] + 1;
            if( temp < v[i-1])
            cout<<v[i-1]<<endl;
            else
            cout<<temp<<endl;
        }
    }
    return 0;
}