#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#endif
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int dp[105][105][105][2];
int p[105];
bool no[105];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		cin>>p[i];
		no[p[i]]=1;
	}
	int odd=0,even=0;
	fr(i,1,n)
		if(no[i]==0) {
			if(i&1)
				odd++;
			else
				even++;
		}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0][0]=dp[0][0][0][1]=0;
	fr(i,1,n) {
		fr(j,0,odd) {
			fr(k,0,even) {
				fr(l,0,1) {
					if(p[i]) {
						if((p[i]&1)==l&1) {
							dp[i][j][k][p[i]&1]=min(dp[i][j][k][p[i]&1],dp[i-1][j][k][l]);
						} else {
							dp[i][j][k][p[i]&1]=min(dp[i][j][k][p[i]&1],dp[i-1][j][k][l]+1);
						}
					} else {
						dp[i][j+l][k+(l^1)][l]=min(dp[i][j+l][k+(l^1)][l],dp[i-1][j][k][l]);
						dp[i][j+l][k+(l^1)][l]=min(dp[i][j+l][k+(l^1)][l],dp[i-1][j][k][l^1]+1);
					}
				}
			}
		}
	}
	cout<<min(dp[n][odd][even][0],dp[n][odd][even][1])<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}