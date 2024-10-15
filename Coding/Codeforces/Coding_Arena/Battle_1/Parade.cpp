#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int l, r, suml = 0, sumr = 0, eq = 0;
    vector<pair<int, int>> diff, num;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        // diff.push_back(make_pair(l-r),i);
        num.push_back(make_pair(l, r));
        if (l == r)
            eq++;
        suml += l;
        sumr += r;
    }
    // sort(diff(all));
    if (eq == n)
        cout << 0;
    else
    {
        int temp;
        long long diff = abs(suml - sumr);
        for (int i = 0; i < n; i++)
        {
            int temp1 = suml - num[i].first + num[i].second;
            int temp2 = sumr - num[i].second + num[i].first;
            if (abs(temp1 - temp2) > diff)
            {
                diff = abs(temp1 - temp2);
                temp = i + 1;
            }
        }
        cout << temp;
    }
    return 0;
}