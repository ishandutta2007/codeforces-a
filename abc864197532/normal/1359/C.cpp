#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 1000001, logN = 17;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		lli c, h, t;
		cin >> h >> c >> t;
		if (t == h) {
			cout << 1 << endl;
		} else if (h + c >= 2 * t) {
			cout << 2 << endl;
		} else {
			lli k = (h - t) / (2 * t - h - c);
			lli now = (h * k + c * (k - 1));
			lli id = 2 * k - 1;
			for (lli i = max(k - 500, 1ll); i <= k + 500; ++i) {
				lli tmp = h * i + c * (i - 1);
				if (abs(now - t * id) * (2 * i - 1) > abs(tmp - t * (2 * i - 1)) * id) {
				    now = tmp;
				    id = 2 * i - 1;
				}
 			}
 			cout << id << endl;
		}
	}
}