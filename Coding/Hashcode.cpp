#define ll long long int
#include<bits/stdc++.h>
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL));
#define l(a) a.length()
#define fr first
#define sc second
#define mod 1000000007
#define endl '\n'
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
using namespace std;
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll add(ll x,ll y)  {ll ans = x+y; return (ans>=mod ? ans - mod : ans);}
ll sub(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod : ans);}
ll mul(ll x,ll y)  {ll ans = x*y; return (ans>=mod ? ans % mod : ans);}
 

class People
{
    public:
        string name;
        ll numOfSkills,available=1,day_working=0;
        vector<string> skill_name;
        vector<ll> skill_level;
        People(){
            cin >> name >> numOfSkills;
            loop(x, 0, numOfSkills){
                string s; cin>>s;
                ll temp; cin>>temp;
                skill_name.pb(s);
                skill_level.pb(temp);
            }
        }
};

class Project
{
    public:
        string name;
        ll days, score, bestBefore, numOfSkills;
        vector<string> skill_name;
        vector<ll> skill_level;
        Project(){
            cin >> name;
            cin >> days >> score >> bestBefore >> numOfSkills;
            loop(x, 0, numOfSkills){
                string s; cin>>s;
                ll temp; cin>>temp;
                skill_name.pb(s);
                skill_level.pb(temp);
            }
        }
};

void countScore(Project p, vector<People> &people){

    
}

void solve(){
    ll contributors, num_projects; cin>>contributors>>num_projects;
    vector<People> people(contributors);
    vector<Project> projects(num_projects);
    vector<pair<string,vector<string>>> ans;
    map<string, vector<People>> m;
    for(auto p: people){
        for(auto thisSkill: p.skill_name){
            m[thisSkill].pb(p);
        }
    }
    cout<<1<<endl;
    cout<<projects[0].name<<endl;
    ll it1=-1;

    for(auto sk:projects[0].skill_name)
    {
        it1++;
        if(m[sk].size()!=0)
        {
            for(auto p:m[sk])
            {
                vector<string> ::iterator it;
                it= find(all(p.skill_name),sk);
                int index = it-p.skill_name.begin();
                if(p.skill_level[index]>=projects[0].skill_level[it1] && p.available)
                {
                    cout<<p.name<<" ";
                    p.available = 0;
                }
            }
        }
    }

    // for(auto pr: projects){
    //     for(auto sk: pr.skills){
            
            
    //     }
    // }
    
    



}

int main()
{
    fast
    solve();
    return 0;
}