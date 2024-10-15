#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    vector<int> fac;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int count = 0, flag = 0;
    for (int i = 1; i < 101; i++)
    {
        flag = 1;
        for (int j = 0; j < n; j++)
        {
            if (i % a[j] != 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            fac.push_back(i);
    }
    // for(int i=0;i<fac.size();i++)
    // cout<<fac[i]<<" ";
    // cout<<endl;
    for (int i = 0; i < fac.size(); i++)
    {
        flag = 1;
        for (int j = 0; j < m; j++)
        {
            if (b[j] % fac[i] != 0)
            {
                //cout<<fac[i]<<endl;
                flag = 0;
                break;
            }
        }
        if (flag)
            count++;
    }
    cout << count << endl;
}