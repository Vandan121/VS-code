#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define cd complex<ld>
#define pi pair<int, int>
#define pl pair<ll,ll>
#define pd pair<ld,ld>
#define vi vector<int>
#define vd vector<ld>
#define vl vector<ll>
#define vpi vector<pi> 
#define vpl vector<pl> 
#define vcd vector<cd>
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
#define endl "\n" 
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
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
candy(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n,1);
    for(int i=1;i<n;i++){
        if(A[i] > A[i-1]) ans[i] = ans[i-1]+1;
    }
    for(int i=n-2;i>=0;i--){
        if(A[i] > A[i+1]) ans[i] = ans[i+1]+1;
    }
    int ret = 0;
    for(int i=0;i<n;i++) ret += ans[i];
    return ret;
}
int candy(vector<ll> &ratings) {
    int candies = 0;
    int size = ratings.size();
    vector<int> left(size, 1);
    vector<int> right(size, 1);
    
    for (auto l = 1; l<size; ++l)
        if (ratings[l] > ratings[l-1])
            left[l] = left[l-1] + 1;
    
    for (auto r = size-2; r>=0; --r)
        if (ratings[r] > ratings[r+1])
            right[r] = right[r+1] + 1;
            
    for (auto i = 0; i<size; ++i)
        candies += max(left[i], right[i]);
        
    return candies;
}
void solve()
{
    
    vl a = {-255, 369, 319, 77, 128, -202, -147, 282, -26, -489, -443, -401, 385, 465, -134, 126, 304, 179, 16, 112, 473, -467, 279, -233, 66, 76, 408, 148, -369, 328, 138, -164, 492, -276, -326, 170, 168, 189, 13, 383, 341, 426, 219, 337, -62, -197, 263, 338, -324, 261, 273, -74, -8, -133, 318, -100, 487, -196, -465, -495, -136, 94, -201, 491, 204, 323, 156, -337, -99, 115, 179, 184, -249, 76, -396, 265, 500, -83, 270, 438, -418, 401, -184, -247, -203, 190, 191, -282, -248, 465, 146, 7, -381, 326, -409, 474, 186, -206, 447, 17, 156, -273, 381, -307, -206, 164, -147, 58, -224, 284, 204, 267, 123, 141, -8, 225, -246, 12, 399, -261, -104, 191, 390, 152, 313, -91, 8, -476, -363, -183, -280, -282, -431, 366, 89, -166, -257, 132, 98, -387, 389, -219, -332, 227, 386, -33, 361, -308, -494, -33, 110, 423, -465, -417, 496, -333, -259, 402, 36, 380, -385, -329, 283, 389, 396, -161, 466, -405, -293, 442, 259, 377, -386, -386, 329, 204, 438, 346, -185, -401, -219, 213, 351, -18, -20, 364, 319, 187, 197, 122, -182, -126, -211, -448, 44, -360, -345, -147, 480, -387, 222, 92, -262, -409, 163, 323, -291, -61, -431, -288, -309, -490, -494, 328, -207, 398, 475, -228, -37, 44, 227, -371, -91, -440, 220, 39, -73, 80, -189, 37, 94, -96, -400, -380, 172, -179, -442, -119, 411, -184, 218, -18, 170, 430, -157, 345, 418, 390, -39, -85, 216, -197, -421, 328, -311, 160, 432, 104, -419, -140, -115, -202, 58, 415, 473, -87, 475, 430, 114, -314, 430, -419, 375, 258, 255, 42, -63, 54, -352, -337, -180, -31, 441, -382, -176, 209, -137, 171, -89, 155, 421, 308, -153, 254, -210, -245, 373, -435, -29, -398, 326, 297, 81, -157, 254, 52, 479, 356, -497, -16, 109, -353, -20, -122, -172, 23, 20, -344, 203, 372, -306, -9, 238, -190, 495, 9, -2, 125, 150, -180, -340, -1, -347, -269, -181, -15, 83, -304, -365, 490, -475, 161, 422, 440, -414, 380, -446, -404, -352, -144, -297, -62, -23, -223, 359, 127, 183, -20, 93, -285, -477, 223, 1, 131, -359, -74, 321, 197, 452, -338, 367, -337, 183, -41, 218, -75, -212, 208, 188, -38, 91, 332, 388, -185, -247, 405, -390, -371, 313, -471, 457, 307, 494, -467, -225, -3, -271, -164, -120, 101, 385, -12, 234, -368, -317, 167, 241, -494, -279, -288, 452, -499, 372, 464, 234, 16, 40, 264, -474, -400, 429, 33, 495, -285, 201, 190, 328, 127, 286, 312, 100, -24, 409, -392, 183, -69, -352, -56, -304, -261, -296, -140, 453, 253, -215, 195, 288, -300, 10, -104, -491, 275, -275, 175, 24, 387, 408 };
    int n = a.size();
    cout<<candy(a);
}
int main()
{
    fast
    int	t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}