#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (lli i=(m);i<(n);i++)
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
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100000;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	vector <int> pos1(100087, 0), pos3(100087, -2);
	vector <int> pos2(100087, 0);
	fop (i,0,n) cin >> a[i], pos1[a[i]]++, pos3[a[i]] = i + 1;
	bool is = true, iss = true;
	fop (i,0,m) {
		cin >> b[i];
		pos2[b[i]]++;
		if (pos1[b[i]] == 0) is = false;
		if (pos1[b[i]] > 1) iss = false;
	}
	if (!is) {
		cout << "Impossible\n";
	} else {
		if (!iss) {
			cout << "Ambiguity\n";
		} else {
			cout << "Possible\n";
			fop (i,0,m) {
				cout << pos3[b[i]] << " \n"[i == n - 1];
			}
		}
	}
}