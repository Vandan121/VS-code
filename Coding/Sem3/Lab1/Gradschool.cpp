#include<bits/stdc++.h>
using namespace std;
string multiply_single_bit(string s1,char c,int l)
{
    string result = "";
    for(int i=0;i<l;i++)
    {
        result += '0';
    }
    int bit = c - '0';
    int carry=0;
    int len = s1.length();
    for(int i=0;i<len;i++)
    {
        int x = bit*(s1[len-1-i]-'0') + carry;
        carry=0;
        if(x<=9) result+=(x+'0');
        else
        {
            result+= (x%10 + '0');
            carry = x/10;
        }
        if(i == len-1 && carry!=0) result+= carry+'0';
    }
    reverse(result.begin(),result.end());
    return result;
}

void multiply(string s1,string s2)
{
    vector<string> str;
    for(int i=0;i<s2.length();i++)
    {
        str.push_back(multiply_single_bit(s1,s2[i],s2.length()-i-1));
    }
    //5435345 
    //6456456
    string zero = "";
    for(int i=0;i<str.size();i++)
    {
        str[i].insert(0,zero);
        zero+="0";
    }
    int len = str[0].length();
    string result = "";
    int carry=0;
    for(int i=len-1;i>=0;i--)
    {
        int sum=0;
        for(int j=0;j<str.size();j++)
        {
            sum += str[j][i]-'0';
        }
        sum+=carry;
        carry=0;
        if(sum<=9) result+=sum+'0';
        else
        {
            result+= (sum%10 + '0');
            carry = sum/10;
        }
        if(i == 0 && carry!=0) result += carry + '0';
    }
    reverse(result.begin(),result.end());
    cout<<"multiplication : "<<result<<endl;
}

int main()
{
    cout<<"Enter two numbers : ";
    string s1,s2;
    cin>>s1>>s2;
    multiply(s1,s2);
    return 0;
}