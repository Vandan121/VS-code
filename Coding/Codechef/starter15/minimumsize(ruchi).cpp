#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

int binaryNum[64];

long long decToBinary(long long n)
{
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
        
    }
    return i;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        if(n==0){
            cout<<"2\n1 1\n";
            continue;
        }
        long long len=decToBinary(n);
        long long result[64]={0};
        int x=0;
        int l=0;
        for(long long i=len-1;i>=0;i--){
            if(l==0&&binaryNum[i]==1){
                long long h=pow(2,i+1);
                result[x]=h-1;
                x++;
                l=1;
            }
            
            if(l==1&&binaryNum[i]==0){
                long long h=pow(2,i+1);
                result[x]=h-1;
                x++;
                l=0;
            }
        }
        cout<<x<<"\n";
        for(int i=0;i<x;i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
