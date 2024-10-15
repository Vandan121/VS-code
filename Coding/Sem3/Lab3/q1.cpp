#include <bits/stdc++.h>
using namespace std;
string addition(string a,string b)
{
    if(a.length() > b.length())
    {
        b = string(a.length()-b.length(),'0').append(b);
    }
    else if(b.length() > a.length())
    {
        a = string(b.length()-a.length(),'0').append(a);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string result = "";
    int carry=0,x;
    for(int i=0;i<a.length();i++)
    {
        x = a[i] - '0' + b[i] - '0' + carry;
        carry = x/10;
        x = x%10;
        result += x + '0';
    }
    if(carry ==1)
    {
        result += carry + '0';
    }
    reverse(result.begin(),result.end());
    return result;
}
string multiplication(string a,string b)
{
    
    reverse(a.begin(), a.end());
    string result = "";
    int carry=0,x;
    for(int i=0;i<a.length();i++)
    {
        x = (a[i] - '0')*(b[0] - '0') + carry;
        carry = x/10;
        x = x%10;
        result += x + '0';
    }
    if(carry)
    {
        result += carry + '0';
    }
    reverse(result.begin(),result.end());
    return result;
}
string karatsuba(string s1,string s2)
{
    if(s1 == "0" || s2 == "0")
    return "0";
    cout<<"s1 : "<<s1<<" s2 : "<<s2<<endl;
    if(s1.length() <= 1 || s2.length() <= 1)
    {
        if(s1.length() == 1)
        return multiplication(s2,s1);
        else
        return multiplication(s1,s2);
    }
    string a=s1.substr(0,s1.length()/2);
    string b=s1.substr(a.length(),s1.length()-a.length());
    string c=s2.substr(0,s2.length()/2);
    string d=s2.substr(c.length(),s2.length()-c.length());
    string ac = karatsuba(a,c);
    string ad = karatsuba(a,d);
    string bc = karatsuba(b,c);
    string bd = karatsuba(b,d);

    ac = ac.append(string(s1.length() + s2.length()-a.length()-c.length(),'0'));
    ad = ad.append(string(s1.length() - a.length(),'0'));
    bc = bc.append(string(s2.length() - c.length(),'0'));
    string adbc = addition(ad,bc);
    cout<<"ac : "<<ac<<" adbc : "<<adbc<<" bd : "<<bd<<endl;
    return addition(ac,addition(adbc,bd));   
}
int main()
{
    int n;
    cin>>n;
    vector<string> numbers(n);
    for(int i=0;i<n;i++)
    {
        cin>>numbers[i];
    }
    string query;
    cin>>query;
    vector<int> singles;
    vector<pair<int,int> >doubles;
    int x=0,i=0,y=0;
    while(i<query.length())
    {
        x=-1;
        if(query[i] == '[')
        {
            x=0;
            i++;
            while(1)
            {
                if(query[i] -'0' <10 && query[i] - '0' >=0)
                    {
                        x = x*10 + query[i] - '0';
                        i++;
                    }
                else
                {
                    i++;
                    break;
                }
            }
            singles.push_back(x);
        }
        if(query[i] == '(')
        {
            x=0;
            y=0;
            i++;
            
            while(query[i] != ',')
            {
                x = x*10 + query[i] - '0';
                i++;    
           }
           i++;
           while(query[i] != ')')
            {
                y = y*10 + query[i] - '0';
                i++;
            }
            doubles.push_back(make_pair(x,y));
            i++;
        }
    }
    
    string result = "1";
    for(int i=0;i<doubles.size();i++)
    {
        string s1= karatsuba(numbers[doubles[i].first],numbers[doubles[i].second]);
        result = karatsuba(result,s1);
    }
    for(int i=0;i<singles.size();i++)
    {
        result = karatsuba(result,numbers[singles[i]]);
    }
    cout<<result;

}