#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
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
const int mod = 998244353, x = 864197532, N = 50, logN = 17, K = 350;
long long modpow(int a, int b) {
	long long ans = 1;
	for (long long aa = a; b; b >>= 1, aa = aa * aa % mod) {
		if (b & 1) ans = ans * aa % mod;
	}
	return ans;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a, tmp, pre = 0;
    cin >> n >> m >> a;
    lli ans = 1;
    fop (i,0,m) {
    	cin >> tmp;
    	int b = tmp - pre;
    	lli k = modpow(a, b);
    	ans = ans * (k + ((k * k % mod + mod - k) % mod * ((mod + 1) / 2) % mod)) % mod;
    	pre = tmp;
	}
	ans = ans * modpow(a, n - 2 * pre) % mod;
	cout << ans << endl;
}