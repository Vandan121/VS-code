#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, result = 0;
    cin >> t;
    while (t--)
    {
        result = 0;
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        for (int i = 0; i < a; i++)
        {
            if (s[i] == '0')
                result += b;
            else
                result += c;
        }
        cout<<result<<endl;
    }
}