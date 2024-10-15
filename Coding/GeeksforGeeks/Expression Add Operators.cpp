                /**************************************
                *                                     *
                *            sasta_samurai            *
                *                                     *
                **************************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define ll long long int
#define ld long double
#define cd complex<ld>
#define pi pair<int, int>
#define pl pair<ll,ll>
#define pd pair<ld,ld>
#define vi vector<int>
#define vs vector<string>
#define vd vector<ld>
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vector<pl> 
#define vvl vector<vl> 
#define vcd vector<cd>
#define st string
#define ct continue
#define mll map<ll,ll>
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL));
#define l(a) a.length()
#define maxx(a,b) max(1ll*(a),1ll*(b));
#define minn(a,b) min(1ll*(a),1ll*(b));
#define fr first
#define sc second
#define mod 1000000007
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
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
template <class T> void _print(queue <T> v) {cerr << "{"; while(v.size()){ _print(v.front()); cerr << " ";v.pop();} cerr << "}"; }
template <class T> void _print(stack <T> v) {stack<T> a; while(v.size()) a.push(v.top()), v.pop(); cerr << "{";  while(a.size()){ _print(a.top()); cerr << " ";a.pop();}  cerr << "}"; }
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ll add(ll x,ll y)  {ll ans = x+y; return (ans>=mod ? ans - mod : ans);}
ll sub(ll x,ll y)  {ll ans = x-y; return (ans<0 ? ans + mod : ans);}
ll mul(ll x,ll y)  {ll ans = x*y; return (ans>=mod ? ans % mod : ans);}


//string decimaltobinary (ll n,ll length) {return bitset<length>(n).to_string();}
const int MOD = 1000000007;
void google(int t) {cout << "Case #" << t << ": ";}
ll binaryMultiply(ll a, ll b,ll M=mod){ll ans = 0;while (b) {if (b & 1){ans = (ans + a) % M;}a = (a + a) % M;b >>= 1;} return ans;}
ll binaryExponentiation(ll a, ll b,ll M=mod){a %= M;ll ans = 1;while (b){if (b & 1){if(M>mod) ans = binaryMultiply(ans, a);else ans = (ans * 1LL * a) % M;}if(M>mod) a = binaryMultiply(a, a);else a = (a * 1LL * a) % M;b >>= 1;}return ans;}
vector<ll> sieve(ll n) {ll *arr = new ll[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void extendgcd(ll a, ll b, vi &v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass a vector of size 3
ll mminv(ll a, ll M) {vi arr(3); extendgcd(a, M, arr); return arr[0];} //for non prime M
ll mminvprime(ll a, ll M) {return binaryExponentiation(a, M - 2, M);}//for prime M
ll phi(ll n){ll result=n;for(ll i=2;i*i<=n;i++){if(n%i==0){while(n%i==0) n/=i;result-=result/i;}}if(n>1) result-=result/n; return result;}
const int MX = 100001;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
const int TWO_MOD_INV = 500000004;
bool sq(ll n){
    ll i = sqrt(n);
    return (i*i == n);
}
bool check(ll i,ll j,ll n,ll m){
    if(i<0 || j<0 || i>=n || j>=m){
        return false;
    }
    return true;
}
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime)); 
    for (int p = 2; p * p <= n; p++)
    {
    if (prime[p] == true)
    {
    for (int i = p * p; i <= n; i += p)
        prime[i] = false;
    }
    }
    for (int p = 2; p <= n; p++)
    if (prime[p])
    cout << p << " ";
}
ll total_sum(ll start,ll end){
    return (
        (((end - start + 1) % MOD) * ((start + end) % MOD) % MOD)
        * TWO_MOD_INV % MOD
    );
}
/* sparse table */
void build(vl &a){
ll sparse[200010][32];
ll lg[200010];
    // memset(sparse,-1,sizeof sparse);
    ll n = a.size();
    for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
    for(int i=0;i<n;i++){
        sparse[i][0] = a[i];
    }
    for(int j=1;j<30;j++){
        for(int i=0;i+(1<<j) <= n;i++){
            sparse[i][j] = max(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
        }
    }
}
/*ncr function*/
ll binexp(ll a,ll b, ll m){
    ll res = 1;
    while(b>0){
        if(b&1){
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b >>= 1;
    }
    return res;
}
vl fact(1e6+1,1);
void factorial(){
    for(int i=1;i<=1e6;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}
ll ncr(ll n,ll k){
    ll ans = fact[n];
    ll den = (fact[n-k]*fact[k])%mod;
    den = binexp(den,mod-2,mod);
    ans = (ans*den)%mod;
    return ans;
}
// important syntaxes here
/* sparse table*/
// ll d = lg[abs(x1-x2)];
// ll max_height = max(sparse[min(x1,x2)-1][d],sparse[max(x1,x2)-(1<<d)][d]);
/*ordered_set*/
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
//cout<<setprecision(15)<<pow(1.1,x)
//*max_element(all(vec))
//count(all(vec),0ll))


void func(vector<vector<string>> &vec,vector<string> vec1,string &s,int i){
        int n = s.length();
        if(i==n){
            vec.push_back(vec1);
            return;
        }
        string num = "";
        if(s[i] == '0'){
            vec1.push_back("0");
            func(vec,vec1,s,i+1);
        }
        else{
           for(;i<n;i++){
                num.push_back(s[i]);
                vec1.push_back(num);
                func(vec,vec1,s,i+1);
                vec1.pop_back();
            } 
        }
    }
    int s_t_i(string &s){
        int num = 0;
        int n = s.length();
        int i = 0;
        if(s[i]=='-') i++;
        for(;i<n;i++){
            num = num*10 + (s[i]-'0');
        }
        if(s[0]=='-') num *= -1;
        return num;
    }
    string i_t_s(int n){
        string s = "";
        int x = abs(n);
        while(x){
            int x1 = x%10;
            s.push_back(char(x1+'0'));
            x /= 10;
        }
        if(n < 0) s.push_back('-');
        reverse(s.begin(),s.end());
        return s;
    }
    int calc(vector<string> &temp){
        int n = temp.size();
        stack<string> nums; 
        stack<string> signs;
        int ans = 0;
        nums.push(temp[0]);
        for(int i=1;i<n;i+=2){
            if(temp[i]=="*"){
                string x = nums.top(); nums.pop();
                string y = temp[i+1];
                int x1 = s_t_i(x);
                int y1 = s_t_i(y);
                nums.push(i_t_s(x1*y1));
            }
            else{
                signs.push(temp[i]);
                nums.push(temp[i+1]);
            }
        }
        while(nums.size() > 1){
            string x = nums.top(); nums.pop();
            string y = nums.top(); nums.pop();
            int x1 = s_t_i(x);
            int y1 = s_t_i(y);
            if(signs.top()=="-"){
                nums.push(i_t_s(y1-x1));
            }
            else{
                nums.push(i_t_s(x1+y1));
            }
            signs.pop();
        }
        ans = s_t_i(nums.top());
        return ans;
    }
    void func1(vector<string> &vec,vector<string> temp,vector<string> &ans,int target,int i){
        int n = vec.size();
        if(i==n-1){
            temp.push_back(vec[i]);
            if(calc(temp) == target){
                string s = "";
                for(auto s1 : temp) s += s1;
                ans.push_back(s);
            }
        }
        else{
            vector<string> sign = {"*","+","-"};
            for(;i<n-1;i++){
                temp.push_back(vec[i]);
                for(auto s : sign){
                    temp.push_back(s);
                    debug(temp)
                    func1(vec,temp,ans,target,i+1);
                    temp.pop_back();
                }
            }
        }

    }
    vector<string> addOperators(string s, int target) {
        // code here
        int n = s.length();
        vector<vector<string>> vec;
        vector<string> vec1;
        func(vec,vec1,s,0);
        // cout<<vec.size()<<endl;
        debug(vec)
        vector<string> ans;
        for(int i=0;i<vec.size();i++){
            vector<string> temp;
            func1(vec[i],temp,ans,target,0);
        }
        debug(ans)
        return ans;
    }
void solve()
{
    st s; cin>>s;
    ll tar; cin>>tar;
    vector<string> ans = addOperators(s,tar);
    
}
int main()
{
    fast
    int	t=1;
    cin>>t;
    factorial();
    while(t--)
    {
        solve();
    }

    return 0;
}

