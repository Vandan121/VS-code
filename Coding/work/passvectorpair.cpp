#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > totalandindex;
vector<pair<int, int> > phy;
vector<pair<int, int> > che;
vector<pair<int, int> > mat;
vector<pair<string, int> > name;
int n;
struct student
{
    string name;
    int physics,maths,chemistry,total,sr,rank;
};
void collectdata();
void sortvectorpair(int a,int b,vector<pair<int, int> > &vec);
void print();
int similarity(int &b,int a,vector<pair<int,int> >&total);
void rankmaker();
int main()
{
    collectdata();
    student s[n];
}
void collectdata()
{
    int a,b,c;
    cout<<"Enter the number of children : "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        a = ((rand() % 50) + 51);
        b = ((rand() % 50) + 51);
        c = ((rand() % 50) + 51);
        phy.push_back(make_pair(a,i));
        che.push_back(make_pair(b,i));
        mat.push_back(make_pair(c,i));
        totalandindex.push_back(make_pair(a+b+c,i));
    }
    string temp;
    ifstream read;
    read.open("NameData.dat");
    for(int i=0;i<n;i++)
    {
        read>>temp;
        name.push_back(make_pair(temp,i));
    }
    sort(totalandindex.rbegin(), totalandindex.rend());   //Pushing and sorting of main vectors are done here
}
void sortvectorpair(int a,int b,vector<pair<int, int> > &vec)
{
    int temp1,temp2,count=1;
    while(count)
    {
        count =0;
        for(int i=a;i<b;i++)
        {
            temp1 = vec[i].first;
            temp2 = vec[i].second;
            if(temp1<vec[i+1].first)
            {
                count++;
                vec[i].first = vec[i+1].first;
                vec[i].second = vec[i+1].second;
                vec[i+1].second = temp2;
                vec[i+1].first = temp1;
            }
        }
    }
    for(int i=a;i<=b;i++)
    {
        totalandindex[i].second = vec[i].second;
    }
}
void print()
{
    cout<<"Hi"<<endl;
    ofstream write;
    write.open("myvectorpair.dat");
    write<<"Sr No.\t\tName\t\tPhy\t\tChe\t\tMat\t\tTotal"<<endl;
}
int similarity(int &b,int a,vector<pair<int,int> >&vec)
{
   int temp;
   
   while(b<a-1)
    {
        temp = vec[b].first;
        if(temp == vec[b+1].first)
        {
               if(temp == vec[b+1].first)
               b++;
               else
               return 1;
        }
        b++;
    }
    return -1;
}
void rankmaker()
{
    int index,i=0,b,j;
    while(i<n-1)
    {
        if(totalandindex[i] == totalandindex[i+1])
        {
            index=i;
            similarity(index,n,totalandindex);
            sortvectorpair(i,index,phy);
            j=i;
            if(similarity(j,index-1,phy)==-1)
            continue;


            
        }
    }
    
}
