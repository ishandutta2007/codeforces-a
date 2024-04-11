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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17, K = 350;

lli modpow(lli a, lli b) {
	lli ans = 1;
	for (; b; b >>= 1, a = a * a % mod) {
		if (b & 1) ans = ans * a % mod;
	}
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	lli frac[n + 1], fracp[n + 1];
	frac[0] = fracp[0] = 1;
	fop (i,1,n + 1) frac[i] = frac[i - 1] * i % mod, fracp[i] = modpow(frac[i], mod - 2);
	lli ans = 0;
	fop (i,0,n) {
		(ans += (frac[n - 1] * fracp[i] % mod * fracp[n - 1 - i] % mod)) % mod;
	}
    ans = (frac[n] + mod - ans) % mod;
	cout << (ans + mod) % mod << endl;
}