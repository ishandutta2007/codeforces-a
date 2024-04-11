#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 200000, logN = 18, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    lli dp[n + 1][n + 1];
    fop (i,0,n + 1) fop (j,0,n + 1) dp[i][j] = !i;
	fop (i,1,n + 1) fop (j,1,n + 1) {
		fop (k,1,j + 1) if (i >= k) {
			dp[i][j] = (dp[i][j] + dp[i - k][j]) % mod;
		}
	}
	lli tmp[n + 1];
	fop (i,0,n + 1) tmp[i] = dp[n][i];
	FOP (i,n + 1,1) dp[n][i] = (dp[n][i] + mod - dp[n][i - 1]) % mod; 
	lli ans = 0;
	fop (i,1,n + 1) {
		lli cur = dp[n][i];
		lli all = tmp[min((k - 1) / i, n)];
		ans += (cur * all % mod);
		ans %= mod;
	}
	cout << ans * 2 % mod << endl;
}