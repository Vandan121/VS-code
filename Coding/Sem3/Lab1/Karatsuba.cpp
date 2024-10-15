#include<bits/stdc++.h>
#include<string.h>
using namespace std;
string kartsuba(string s1, string s2)
{
    string a = "", b = "", c = "", d = "";

    int n1 = s1.length();
    int n2 = s2.length();

    if (n1 < 2 || n2 < 2)
    {
        int x =  stol(s1)*stol(s2);
        ostringstream str;
        str << x;
        string s = str.str();
        return s;
    }
    else
    {
        for (int i = 0; i < floor(n1 / 2); i++)
        {
            a += s1[i];
        }
        for (int i = floor(n1 / 2); i < n1; i++)
        {
            b += s1[i];
        }
        for (int i = 0; i < floor(n2 / 2); i++)
        {
            c += s2[i];
        }
        for (int i = floor(n2 / 2); i < n2; i++)
        {
            d += s2[i];
        }
        string temp1 = kartsuba(a,c);
        string temp2 = kartsuba(a,d);
        string temp3 = kartsuba(c,b);
        string temp4 = kartsuba(b,d);
        for(int i=0;i<(n1 + n2 - (floor(n1 / 2) + floor(n2 / 2)));i++)
        {
            temp1.insert(temp1.length(),"0");
        }
        for(int i=0;i<(n1 - floor(n1 / 2));i++)
        {
            temp2.insert(temp2.length(),"0");
        }
        for(int i=0;i<(n2 - floor(n2 / 2));i++)
        {
            temp3.insert(temp3.length(),"0");
        }
        reverse(temp1.begin(),temp1.end());
        reverse(temp2.begin(),temp2.end());
        reverse(temp3.begin(),temp3.end());
        reverse(temp4.begin(),temp4.end());
        int flag[4] = {1,1,1,1};
        int carry=0;
        string result ="";
        for(int i=0;;i++)
        {
            if(flag[0] == 0 && flag[1] == 0 && flag[2] == 0 && flag[3] == 0) break;
            int sum=0;
            if(flag[0] == 1 && i<temp1.length()) sum+=temp1[i]-'0';
            else flag[0] = 0;
            if(flag[1] == 1 && i<temp2.length()) sum+=temp2[i]-'0';
            else flag[1] = 0;
            if(flag[2] == 1 && i<temp3.length()) sum+=temp3[i]-'0';
            else flag[2] = 0;
            if(flag[3] == 1 && i<temp4.length()) sum+=temp4[i]-'0';
            else flag[3] = 0;
            sum+=carry;
            carry=0;
            if(sum<=9) result+= sum+'0';
            else
            {
                result += sum%10+'0';
                carry = sum/10;
            }
            if(flag[0] == 0 && flag[1] == 0 && flag[2] == 0 && flag[3] == 0) break;
        }
        reverse(result.begin(),result.end());
        return result;
    }
}

int main()
{
    string s1,s2;
    cout<<"Enter two numbers : ";
    cin>>s1>>s2;
    string s = kartsuba(s1, s2);
    cout << s;
    return 0;
}