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
    fast int n;
    cin >> n;
    vector<ll> arr;
    int temp;
    cin >> temp;
    arr.pb(temp);
    loop(i, 1, n)
    {
        int temp;
        cin >> temp;
        if (arr[arr.size() - 1] != temp)
        {
            arr.pb(temp);
        }
    }
    // loop(i,0,arr.size())
    // cout<<arr[i]<<" ";
    // cout<<endl;
    int m;
    cin >> m;
    ll player[m];
    in(player, m);
    loop(i, 0, m)
    {
        if (arr[0] <= player[i])
            cout << 1 << endl;
        else if (arr[arr.size() - 1] == player[i])
            cout << arr.size() << endl;
        else if (arr[arr.size() - 1] > player[i])
            cout << arr.size() + 1 << endl;
        else
        {
            loop(j, 0, arr.size() - 1)
            {
                if (arr[j] == player[i])
                {
                    cout << j + 1 << endl;
                    break;
                }
                else if (arr[j] > player[i] && player[i] > arr[j + 1])
                    cout << j + 2 << endl;
            }
        }
    }

    return 0;
}
