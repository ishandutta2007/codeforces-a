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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17;
const double eps = 1e-11;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	set <lli> square;
	fop (i,1,45001) square.insert(1ll * i * i);
	string s;
	cin >> s;
	int n = s.length();
	int ans = 864197532;
	fop (ss,0,1<<n) {
		lli now = 0;
		fop (i,0,n) {
			if (ss & (1 << i)) {
				now = (now * 10) + (s[i] - '0');
				if (now == 0) break;
			}
		}
		if (now == 0) continue;
		if (square.count(now)) {
			ans = min(ans, n - __builtin_popcount(ss));
		}
	}
	if (ans == 864197532) ans = -1;
	cout << ans << endl; 
	
}