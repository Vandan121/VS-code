#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */

vector<string> bigSorting(vector<string> unsorted) {
    vector<string> sorted(unsorted.size());
    vector<pair<int,int> > size;
    string a,b,c;
    for(int i=0;i<(int)unsorted.size();i++)
    {
        size.push_back(make_pair(unsorted[i].size(),i));
    }
    sort(size.begin(),size.end());
    for(int i=0;i<(int)unsorted.size();i++)
    {
        sorted[i]=unsorted[size[i].second];
    }
    for(int i=0;i<sorted.size()-1;i++)
    {
        if(sorted[i].size() == sorted[i+1].size())
        {
            int j=i+1;
            int k=i;
            a=sorted[i];
            while(size[j].second==size[i].second && j<sorted.size())
            {
                b=sorted[j];
                for(int k=sorted[i].size()-1;k>=0;k--)
                {
                    if(a[j]<b[j])
                    break;
                    else if(a[j]>b[j])
                    {
                        k=j;
                        break;
                    }
                }
                j++;
            }
            if(k != i)
            {
                sorted[i] = sorted[k];
                sorted[k] = a;
            }
            }
        }

    return sorted;
}

int main()
{
    int n;
    string a;
    cin>>n;
    cin>>a;
    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (size_t i = 0; i < result.size(); i++) {
        cout<< result[i];

        if (i != result.size() - 1) {
            cout<< "\n";
        }
    }

    cout<< "\n";

    

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
