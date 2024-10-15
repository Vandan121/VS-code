#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<vector<ll>> vv;
typedef vector<pair<ll, ll>> vp;
 
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define in(a, n)               \
    for (ll i = 0; i < n; ++i) \
        cin >> a[i];
#define display(arr, n)        \
    for (ll i = 0; i < n; i++) \
        cout << arr[i] << " "; \
    cout << endl;
#define mod 1000000007




int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    string str;
    cin >> str;
    ll c = 0;
    ll d = 0;
    vector<bool> arr(n, true);
    char ch = '0';
 
    int temp = 2;
    while (1)
    {
        ch = '0';
        for (ll i = 0; i < n; i++)
        {
            if (str[i] == 'D')
            {
                if (c >= 0 && arr[i])
                    d--;
                else if (c < 0 && arr[i])
                {
                    c++;
                    arr[i] = false;
                }
            }
            else
            {
                if (d >= 0 && arr[i])
                    c--;
                else if (d < 0 && arr[i])
                {
                    d++;
                    arr[i] = false;
                }
            }
        }
 
        string ans = "";
        for(int i=0;i<n;i++)
        {
            if(arr[i])
            ans += str[i];
        }
        ll cnt = count(ans.begin(),ans.end(),'R');
        if (cnt == 0 || cnt == ans.length())
        {
            break;
        }
            
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i])
        {
            cout<<str[i]<<endl;
            break;
        }
    }
    return 0;
}