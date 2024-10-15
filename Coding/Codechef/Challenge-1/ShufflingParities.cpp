#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, odd = 0, even = 0,result=0;
    cin >> t;
    while (t--)
    {
        odd = 0;
        even = 0;
        result=0;
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        if(odd>even)
        {
            cout<<(2*even + ((odd-even)/2))<<endl;
        }
        else if(even>odd)
        {
            cout<<(2*odd + floor((even-odd+1)/2))<<endl;
        }
        else
        cout<<2*odd<<endl;
    }
    return 0;
}