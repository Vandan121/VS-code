#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
   string a=str;
   int temp;
   char ch;
   vector<int> vec;
   size_t found = a.find(",");
   while(found != string::npos)
   {
   stringstream ss(a);
   ss>>temp>>ch;
   vec.push_back(temp);
   a = a.substr(a.find(",")+1,a.size()-a.find(",")-1);
   found = a.find(",");
   }
   stringstream ss(a);
   ss>>temp;
   vec.push_back(temp);
   return vec;
   
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
