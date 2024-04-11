#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
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
const int mod = 998244353, x = 864197532, N = 8000, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    lli p;
    cin >> n >> m >> p;
    lli pp = p;
    vector <lli> a(n);
    vector <lli> b(m);
    fop (i,0,n) cin >> a[i];
    fop (i,0,m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    auto ask = [&](int k) {
    	lli ans = 0;
    	int now = n - 1;
    	while (k--) {
    		ans += max(b[k] - a[now], 0ll);
    		now--;
		}
		return ans;
	};
	int l = 0, r = min(n, m) + 1;
	while (r - l > 1) {
		int mid = l + r >> 1;
		if (ask(mid) <= p) l = mid;
		else r = mid;
	}
	int ans1 = l;
	cout << ans1 << ' ' << max(0ll, accumulate(b.begin(), b.begin() + ans1, 0ll) - pp) << endl;
}