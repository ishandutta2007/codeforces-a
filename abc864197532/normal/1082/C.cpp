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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 50, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector <int> num[m];
    fop (i,0,n) {
    	cin >> a >> b;
    	num[a - 1].pb(b);
	}
	fop (i,0,m) sort(all(num[i]));
	vector <int> pre[m];
	fop (i,0,m) {
		pre[i].pb(0);
		while (num[i].size()) {
			pre[i].pb(pre[i].back() + num[i].back());
			num[i].pop_back();
		}
		while (pre[i].back() < 0) pre[i].pop_back();
	}
	vector <int> cnt(n + 1, 0);
	fop (i,0,m) {
		fop (j,0,pre[i].size()) {
			cnt[j] += pre[i][j];
		}
	}
	cout << *max_element(all(cnt)) << endl;
}