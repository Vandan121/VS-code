#include <bits/stdc++.h>

using namespace std;

vector<int> towersonhouses;

/*
 * Complete the 'hackerlandRadioTransmitters' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY x
 *  2. INTEGER k
 */

int hackerlandRadioTransmitters(vector<int> x, int k) {
    if(x.size()==1)
    return 1;
    sort(x.begin(),x.end());
    vector<int> y;
    int elirepeat=x[0];
    y.push_back(x[0]);
    for(int i=1;i<x.size();i++)
    {
        if(x[i] != elirepeat)
        y.push_back(x[i]);
        elirepeat = x[i];
    }
    if(y.size()==1)
    return 1;
    int distance=0,index,i=0,towers=0;
    while(1)
    {
        distance=0;
        if(i==y.size())
        return towers;
        towers++;
        // cout<<"main"<<endl;
        if(i==y.size()-1)
        {
            towersonhouses.push_back(y[i]);
        return towers;
        }
        while(1)
        {
            // cout<<"left"<<endl;
            if(i<y.size()-1)
            {

            if(distance + y[i+1] - y[i] <= k)
            {
                distance += y[i+1] - y[i];
                // if(distance == k)
                // {
                //     towersonhouses.push_back(y[i+1]);
                //     distance =0;
                // }
                i++;
                
            }
            else
            {
                // towersonhouses.push_back(y[i]);
                //break;
                goto next;
            }
            }
            else
            return towers;
        }
        next:
        towersonhouses.push_back(y[i]);
        distance =0;
        while(1)
        {
            // cout<<"right"<<endl;
            if(i<y.size()-1)
            {

            if(distance + y[i+1] - y[i] <= k)
            {
                distance += y[i+1] - y[i];
                // if(distance == k)
                // {
                //     towersonhouses.push_back(y[i+1]);
                //     distance =0;
                // }
                i++;
            }
            else
            {
                // towersonhouses.push_back(y[i]);
                break;
            }
            }
            else
            return towers;
        }
        i++;
    }
}

int main()
{
    

   int n,k,a;
   cout<<"Enter number of houses : "<<endl;
   cin>>n;
   cout<<"Enter value of k : "<<endl;
   cin>>k;


    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        cin>>a;
        x[i] = a;
    }

    int result = hackerlandRadioTransmitters(x, k);

    cout<<"Tower required : " <<result << "\n";
    cout<<result << "\n";
    cout<<"Towers : "<<endl;
    for(int i=0;i<towersonhouses.size();i++)
    {
        cout<<i+1<<" : "<<towersonhouses[i]<<endl;
    }

    return 0;
}

