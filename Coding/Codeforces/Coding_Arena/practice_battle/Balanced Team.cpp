#include<bits/stdc++.h>
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define out(i,a,n) for(ll i=0;i<n;++i) cout<<a[i]<<" ";
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define l(a) a.length()
using namespace std;


int main()
{
    fast
    int n,temp,teams=1;
    cin>>n;
    vector<int> students;
    loop(i,0,n)
    {
        cin>>temp;
        students.pb(temp);
    }
    sort(all(students));
    loop(i,0,n)
    {
        int mem=1;
        loop(j,i+teams,n)
        {
            if((students[j]-students[i])<=5)
            teams++;
            else
            break;
        }
        if(mem>teams) teams = mem;
    }
    cout<<teams<<endl;

    return 0;
}