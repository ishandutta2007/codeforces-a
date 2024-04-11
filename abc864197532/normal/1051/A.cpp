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

bool check(string s) {
	int cnt[3] = {0, 0, 0};
	fop (i,0,s.length()) {
		if (s[i] >= '0' && s[i] <= '9') cnt[0]++;
		else if (s[i] >= 'a' && s[i] <= 'z') cnt[1]++;
		else cnt[2]++;
	}
	return *min_element(cnt, cnt + 3) > 0;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();
		int cnt[3] = {0, 0, 0};
		fop (i,0,n) {
			if (s[i] >= '0' && s[i] <= '9') cnt[0]++;
			else if (s[i] >= 'a' && s[i] <= 'z') cnt[1]++;
			else cnt[2]++;
		}
		string ans = s;
		if (cnt[0] == n) {
			s[0] = 'A';
			s[1] = 'a';
			ans = s;
		} else if (cnt[1] == n) {
			s[0] = '0';
			s[1] = 'A';
			ans = s;
		} else if (cnt[2] == n) {
			s[0] = 'a';
			s[1] = '0';
			ans = s;
		} else if (cnt[0] == 0) {
			fop (i,0,n) {
				string t = s;
				t[i] = '0';
				if (check(t)) {
					ans = t;
				}
			}
		} else if (cnt[1] == 0) {
			fop (i,0,n) {
				string t = s;
				t[i] = 'a';
				if (check(t)) {
					ans = t;
				}
			}
		} else if (cnt[2] == 0) {
			fop (i,0,n) {
				string t = s;
				t[i] = 'A';
				if (check(t)) {
					ans = t;
				}
			}
		}
		cout << ans << endl;
	}
}