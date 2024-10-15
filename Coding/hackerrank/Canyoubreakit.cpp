#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length(), substr = 1, max = 1;
    if (n == 1)
    {
        cout << "1";
        return 0;
    }
    cout << "1 ";
    for (int i = 1; i < n; i++)
    {
        max = 1;
        for (int j = 0; j <= (i / 2); j++)
        {
            substr = 1;
            string s1 = s.substr(0, j + 1);
            if ((i + 1) % (j + 1) != 0)
            {
                continue;
            }
            else
            {
                int k = 0;
                substr = 0;
                while (k <= i)
                {
                    //cout << "k = " << k;
                    string str = s.substr(k, j + 1);
                    if (s1 == str)
                    {
                        substr++;
                        k += str.length();
                    }
                    else
                    {
                        substr = 1;
                        break;
                    }
                }
            }
            if(substr>=max) max = substr;
        }
        cout<<max<<" ";
    }
    //cout << substr << " ";
}