#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long int
#define vi vector
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define node pair<int,char>

#define loop(i,x,y) for(int i=x;i<y;i++)
#define deb(x) cout<< #x <<" "<<x<<endl;
#define print(x) cout<<x<<endl;
#define endl '\n' 

#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()

#define pi 3.14159265358979323846
const int MOD = 998244353 ;
const int N =  3e5+5 ;
const int INF = 1e18 ;

int len(string s){ int x = s.length(); return x;} 
 
/*-------------------------------------------------------------------------------------------------------------------------------*/
void test(int t){cin>>t;while(t--){}}
 
void read(vi<int>&v , int n){
	for(int i=0;i<n;i++){ cin>>v[i];}}

void read(int arr[],int n){
	for(int i=0;i<n;i++){ cin>>arr[i];}}
 
void write(vi<int>v ){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

void write(int arr[],int n){
	for(int i=0;i<n;i++){ cout<<arr[i]<<" "; }
	cout<<endl; 
}

void write(vi<pair<int,int>> v){
	for(int i=0;i<v.size();i++){ cout<<v[i].ff<<" "<<v[i].ss<<endl ; }
}

int ceill(int n,int x){

	if(n % x){ return (n/x) + 1LL ; }

	else{ return n/x ; }
}

int power(int a,int m){

	if(m==0) return 1;

	int x = power(a,m/2);

	if(m & 1){ 
		return (a*((x*x)));
	}

	return (x*x);
}

/*--------------------------------------------------------------------------------*/

int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

bool cmp( pair<int,int> a , pair<int,int> b){

	if(a.ff != b.ff){

		return a.ff > b.ff ;
	}

	return a.ss < b.ss ;
}

bool solve(int A){

	if(A==1 || A == -1){ return 1; }

	int num = abs(A) ;

    for(int i = 2 ; i*i<=num ; i++){

        for(int j=2 ; power(i,j) <= num ; j++){

        	int x = power(i,j) ;

        	//cout<<i<<" "<<j<<" "<<x<<" "<<num<<" "<<(x==num)<<endl;

            if(x == num){

                if(num==A){ return 1 ; }

                if((j % 2)==1){ return 1;}
            }
        }
    }

    return 0 ;
}


/*---------------------------------------------------------------------------------------------*/

int32_t main(){

	ios_base::sync_with_stdio(false);
		cin.tie(NULL);
 
	#ifndef ONLINE_JUDGE
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
			freopen("error.txt", "w", stderr);
	#endif

	int t=1;

	cin>>t ;

	while(t--){

		string s ;
		cin >>  s;

		vi<int> cnt = { 0 , 0 } ;

		loop(i,0,len(s)){

			cnt[s[i]-'0']++ ;
		}

		if(cnt[0]==cnt[1]){ cout<< cnt[0]-1 << endl ; }

		else{ cout<<min(cnt[0],cnt[1])<<endl;  }
	}

}






