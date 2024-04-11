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
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1000007, logN = 20, K = 350;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		fop (i,0,n) cin >> a[i];
		lli ans = 0, pre = 0;
		for (int i = 0; i + 1 < n; i += 2) {
			pre += (a[i + 1] - a[i]);
			if (pre < 0) pre = 0;
			ans = max(ans, pre);
		}
		pre = 0;
		for (int i = 1; i + 1 < n; i += 2) {
			pre += (a[i] - a[i + 1]);
			if (pre < 0) pre = 0;
			ans = max(ans, pre);
		}
		for (int i = 0; i < n; i += 2) ans += a[i];
		cout << ans << endl;
	}
}