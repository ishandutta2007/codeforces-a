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
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 18, K = 350;

int main () {
	int n, m;
	cin >> n >> m;
	vector <int> a(n + 1);
	a[0] = 0;
	fop (i,0,n) cin >> a[i + 1];
	int ans = 0, tmp = 0, all = 0;
	a.pb(m);
	fop (i,1,n + 2) if (i & 1) all += a[i] - a[i - 1];
	FOP (i,n + 2,1) {
		if (i & 1) {
			if (a[i] - a[i - 1] > 1) ans = max(ans, tmp - 1);
			tmp -= a[i] - a[i - 1];
		} else {
			if (a[i] - a[i - 1] > 1) ans = max(ans, tmp + a[i] - a[i - 1] - 1);
			tmp += a[i] - a[i - 1];
		}
	}
	cout << ans + all << endl;
}