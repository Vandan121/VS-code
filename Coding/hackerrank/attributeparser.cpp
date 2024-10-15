#include <bits/stdc++.h>
using namespace std;
vector<string> str,que;
void check(int i)
{
    string query=que[i].substr(que[i].find("~")+1),b;
    size_t found,found1;
    
    vector<string> strtags,quetags;
    found=que[i].find(".");
    if(found == string::npos)
    {
        quetags.push_back(que[i].substr(0,que[i].find("~")));
    }
    else
    {
        
        found1 = que[i].find(".");
        found=0;
        int j=0;
        while(1)
        {
        j++;
        b = que[i].substr(found,found1-found);
        quetags.push_back(b);
        found = found1+1;
        found1 = que[i].find(".",found1 + j);
        if(found1 == string::npos)
        break;
        }
        b = que[i].substr(found,que[i].find("~")-found);
        quetags.push_back(b);
    }
    int i1=0,top=-1;
    while(1 && i1<(int)str.size())
    {
        cout<<i1<<endl;
        if((int)str[i1][1] == 47)
        {
            strtags.erase(strtags.begin() + top);
            top--;        }
        else
        {
            top++;
            if(str[i1].find(" ") == string::npos)
            {
            b=str[i1].substr(1,str[i1].find(">")-1);
            strtags.push_back(b);
            }
            else
            {
            b=str[i1].substr(1,str[i1].find(" ")-1);
            strtags.push_back(b);
            }
        }
        if(b == quetags[quetags.size()-1])
        break;
        i1++;
    }
    if(quetags.size() != strtags.size())
    {
        cout<<"Not Found!"<<endl;
        return;
    }
    else
    {
        for(int j=0;j<(int)quetags.size();j++)
        {
            if(quetags[j] != strtags[j])
            {
                cout<<"Not Found!"<<endl;
                return;
            }
        }
    }
    
    
    
    found=str[i1].find(query);
        
    if(found == string::npos)
    {
        cout<<"Not Found!"<<endl;
        return;
    }
    else
    {
        if((int)str[i1][found-1] != 32)
        {
            int temp=1;
            while((int)str[i1][(int)found-1] != 32)
            {
                found = str[i1].find(query,found + temp);
                if(found == string::npos)
                {
                    cout<<"Not Found!"<<endl;
                    return;
                }
            }
        }
        int index1 = found + 4 + query.size();
        while((int)str[i1][index1] != 34)
        {
            cout<<str[i1][index1];
            index1++;
        }
        cout<<endl;
    }


}
int main()
{
    char a[200];
    int n,q;
    cin>>n>>q;
    getchar();
    for(int i=0;i<n;i++)
    {
        cin.getline(a,200);
        str.push_back(a);
    }
    
    for(int i=0;i<q;i++)
    {
        cin.getline(a,200);
        que.push_back(a);
    }
    for(int i=0;i<q;i++)
    {
        check(i);
    }
    return 0;
}