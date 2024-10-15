#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    long long n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0){
            cout<<"2\n1 1\n";
            continue;
        }
        else if(!(n&&(n+1)))
        {
            cout<<"1\n"<<n<<endl;
            continue;
        }
        int temp[64];
        int dectobin[64];
        int i = 0;
        while (n > 0) 
        {
            temp[i] = n % 2;
            n = n / 2;
            i++;
        }
        for (int j = 0; j <i; j++)
            dectobin[j] = temp[i-1-j];
        long long arr[64];
        long long h = pow(2,i);
        arr[0] = h-1;
        int size=1;
        for(int j=1;j<i;j++)
        {
            if(dectobin[j]==0)
            {
                if(size%2==0)
                continue;
                else
                {
                    h = pow(2,i-j);
                    arr[size] = h-1;
                    size++;
                }
            }
            else
            {
                if(size%2==1)
                continue;
                else
                {
                    h = pow(2,i-j);
                    arr[size] = h-1;
                    size++;
                }
            }
        }
        cout<<size<<endl;
        for(long long k=0;k<size;k++)
        cout<<arr[k]<<" ";
        cout<<endl;
    }
    return 0;
}