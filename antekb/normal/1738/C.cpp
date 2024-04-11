#include<bits/stdc++.h>
 
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("trapv")
 
#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
#define rsz(x) resize(x)
 
using namespace std;
 
///~~~~~~~~~~~~~~~~~~~~~~~~~~
 
template <typename H, typename T> 
ostream& operator<<(ostream& os, pair<H, T> m){
	return os <<"("<< m.st<<", "<<m.nd<<")";
}
template <typename H> 
ostream& operator<<(ostream& os, vector<H> V){
	os<<"{";
	for(int i=0; i<V.size(); i++){
		if(i)os<<" ";
		os<<V[i];
	}
	os<<"}";
	return os;
}
 
void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);
 
///~~~~~~~~~~~~~~~~~~~~~~~~~
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;
 
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
const int N=105, INF=1e9+5, mod=1e9+7;
int dp[2][2][N][N];//kto, ile, ile0, ile1
int main(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i+j==0){
				dp[0][1][i][j]=dp[1][1][i][j]=0;
				dp[0][0][i][j]=dp[1][0][i][j]=1;
			}
			else{
			dp[1][0][i][j]=dp[1][1][i][j]=1;
			if(i){
				dp[1][0][i][j]=min(dp[1][0][i][j], dp[0][0][i-1][j]);
				dp[1][1][i][j]=min(dp[1][1][i][j], dp[0][1][i-1][j]);
			}
			if(j){
				dp[1][0][i][j]=min(dp[1][0][i][j], dp[0][0][i][j-1]);
				dp[1][1][i][j]=min(dp[1][1][i][j], dp[0][1][i][j-1]);
			}
			dp[0][0][i][j]=dp[0][1][i][j]=0;
			if(i){
				dp[0][0][i][j]=max(dp[0][0][i][j], dp[1][0][i-1][j]);
				dp[0][1][i][j]=max(dp[0][1][i][j], dp[1][1][i-1][j]);
			}
			if(j){
				dp[0][0][i][j]=max(dp[0][0][i][j], dp[1][1][i][j-1]);
				dp[0][1][i][j]=max(dp[0][1][i][j], dp[1][0][i][j-1]);
			}
			}
		}
	}
	//BOOST;
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		int k=0, l=0;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			if(x&1)l++;
			else k++;
		}
		if(dp[0][0][k][l])cout<<"Alice\n";
		else cout<<"Bob\n";
	}
}