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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 18, K = 350;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	fop (i,0,n) cin >> a[i];
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 1 << 30;
	fop (i,-1,2) {
		fop (j,-1,2) {
			int tmp = (i ? 1 : 0) + (j ? 1 : 0);
			vector <int> b = a;
			b[0] += i;
			b.back() += j;
			if ((b.back() - b[0]) % (n - 1) == 0) {
				int d = (b.back() - b[0]) / (n - 1);
				bool is = false;
				fop (i,1,n - 1) {
					int aa = b[i - 1] + d;
					if (aa != b[i]) {
						if (abs(aa - b[i]) == 1) tmp++;
						else is = true;
					}
					b[i] = aa;
				}
				if (!is) ans = min(ans, tmp);
			}
		}
	}
	if (ans == 1ll << 30) ans = -1;
	cout << ans << endl;
}