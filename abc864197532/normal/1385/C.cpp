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
const int mod = 1e9 + 7, x = 864197532, N = 2087, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		fop (i,0,n) cin >> a[i];
		int pre = 0, ans = 0;
		bool is = true;
		FOP (i,n,0) {
			if (is) {
				if (a[i] < pre) {
					is = false;
					pre = a[i];
				} else {
					pre = a[i];
				}
			} else {
				if (a[i] > pre) {
					ans = i + 1;
					break;
				} else {
					pre = a[i];
				}
			}
		}
		cout << ans << endl;
	}
}