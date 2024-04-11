#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=1000010, LOG=20;

ll ans;
int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], sieve[MAXN];
int dp[MAXN][2];
string S;

inline int Check(int i){
	if (i<0 || i+3>n) return 0;
	return (S[i]=='a' && S[i+1]=='b' && S[i+2]=='c');
}
void Solve(){
	cin>>n>>k;
	ans=0;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		if (A[i]==1) A[i]=0;
		else if (sieve[A[i]]) A[i]=2;
		else A[i]=1;
	}
	for (int i=n; i; i--){
		dp[i][0]=1;
		dp[i][1]=0;
		if (A[i]==2) continue ;
		if (A[i]==1){
			if (i+k<=n) dp[i][1]+=dp[i+k][0];
			else dp[i][1]++;
		}
		else{
			if (i+k<=n){
				dp[i][0]+=dp[i+k][0];
				dp[i][1]+=dp[i+k][1];
			}
			else dp[i][0]++;
		}
		ans+=dp[i][1]-(A[i]==1);
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for (int i=2; i<MAXN; i++) if (!sieve[i]) for (int j=i*2; j<MAXN; j+=i) sieve[j]=1;
	int T=1;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}