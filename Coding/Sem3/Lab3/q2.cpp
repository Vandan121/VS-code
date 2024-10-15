#include <bits/stdc++.h>
using namespace std;
int inttobin(int a)
{
    switch(a)
    {
        case 0:
        return 0;
        case 1:
        return 1;
        case 2:
        return 10;
        case 3:
        return 11;
    }
}
void bintoint(string a)
{
    int result=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        result  = result + (a[i] - '0')*pow(2,a.length()-1-i);
    }
    cout<<result;
}
string addition(string a,string b)
{
    if(a.length() >= b.length())
    {
        b = string(a.length()-b.length(),'0').append(b);
    }
    else if(b.length() > a.length())
    {
        a = string(b.length()-a.length(),'0').append(a);
    }
    // reverse(a.begin(), a.end());
    // reverse(b.begin(), b.end());
    string result = "";
    int carry=0,x;
    for(int i=a.length()-1;i>=0;i--)
    {
        x = a[i] - '0' + b[i] - '0' + carry;
        x = inttobin(x);
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
string multiplication(string a,string b)
{
    if(b=="0")
        return "0";
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
    return addition(ac,addition(adbc,bd));   
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    bintoint(karatsuba(s1,s2));
}