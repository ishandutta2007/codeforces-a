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
const int mod = 998244353, x = 864197532, N = 100000, logN = 17, K = 350;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		vector <int> ans(n, -1);
		int tmp = 1;
		set <int> s1, s0;
		fop (i,0,n) {
			if (s[i] == '0') {
				if (s1.size()) {
					int x = *s1.begin();
					ans[i] = x;
					s0.insert(x);
					s1.erase(x);
				} else {
					s0.insert(tmp);
					ans[i] = tmp++;
				}
			} else {
				if (s0.size()) {
					int x = *s0.begin();
					ans[i] = x;
					s1.insert(x);
					s0.erase(x);
				} else {
					s1.insert(tmp);
					ans[i] = tmp++;
				}
			}
		}
		cout << tmp - 1 << endl;
		printv(ans);
	}
}