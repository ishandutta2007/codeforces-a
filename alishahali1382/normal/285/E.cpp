#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b;
ll dp[MAXN][MAXN];
ll C[MAXN][MAXN], F[MAXN];
ll res[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	dp[0][0]=dp[1][0]=1;
	for (int i=2; i<=n; i++){
		dp[i][0]=1;
		for (int j=1; 2*j<=i; j++) dp[i][j]=(dp[i-1][j] + dp[i-2][j-1])%mod;
	}
	for (int i=0; i<=n; i++) for (int j=0; j<=i; j++) res[i]=(res[i]+dp[n][j]*dp[n][i-j])%mod;
	for (int i=0; i<=n; i++){
		C[i][0]=C[i][i]=1;
		for (int j=1; j<i; j++) C[i][j]=(C[i-1][j] + C[i-1][j-1])%mod;
	}
	F[0]=1;
	for (int i=1; i<=n; i++) F[i]=F[i-1]*i%mod;
	for (int i=0; i<=n; i++) res[i]=res[i]*F[n-i]%mod;
	//for (int i=0; i<=n; i++) debug2(i, res[i])
	/*
	debug(dp[4][0])
	debug(dp[4][1])
	debug(dp[4][2])
	*/
	for (int i=n; i>=0; i--){
		for (int j=i+1; j<=n; j++) res[i]=(res[i]-C[j][i]*res[j])%mod;
	}
	if (res[k]<0) res[k]+=mod;
	cout<<res[k]<<'\n';
	
	return 0;
}