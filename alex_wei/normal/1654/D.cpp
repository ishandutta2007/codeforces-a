
//#pragma GCC optimize(3)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int, int>
#define pll pair <ll, ll>
#define fi first
#define se second
#define pb emplace_back
#define all(x) begin(x), end(x)
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define FileI(x) freopen(x, "r", stdin)
#define FileO(x) freopen(x, "w", stdout)
#define y1 y_chenxiaoyan_1

bool Mbe;
namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
 	#define gc getchar()
//	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*O++ = x)
	#define flush() fwrite(Obuf, 1, O - Obuf, stdout)
	inline ll read() {
		ll x = 0; bool sgn = 0; char s = gc;
		while(!isdigit(s)) sgn |= s == '-', s = gc;
		while(isdigit(s)) x = x * 10 + s - '0', s = gc;
		return sgn ? -x : x;
	}
	template <class T>
		inline void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
	template <class T>
		inline void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int mod = 998244353;
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	} return s;
}

const int N = 3e5 + 5;
int cnt, pr[N], rev[N], vis[N], inv[N];
int n, mn[N], curp[N], ans;
struct edge {int v, x, y;};
vector <edge> e[N];
void dfs(int id, int fa, int cur) {
	ans = (ans + cur) % mod;
	for(auto it : e[id]) {
		if(it.v == fa) continue;
		int tmpx = it.x, tmpy = it.y;
		for(int i = 1; pr[i] * pr[i] <= tmpy; i++) while(tmpy % pr[i] == 0) cmin(mn[i], ++curp[i]), tmpy /= pr[i];
		curp[rev[tmpy]]++;
		for(int i = 1; pr[i] * pr[i] <= tmpx; i++) while(tmpx % pr[i] == 0) cmin(mn[i], --curp[i]), tmpx /= pr[i];
		cmin(mn[rev[tmpx]], --curp[rev[tmpx]]);
		dfs(it.v, id, 1ll * cur * it.y % mod * inv[it.x] % mod);
		tmpx = it.x, tmpy = it.y;
		for(int i = 1; pr[i] * pr[i] <= tmpy; i++) while(tmpy % pr[i] == 0) curp[i]--, tmpy /= pr[i];
		for(int i = 1; pr[i] * pr[i] <= tmpx; i++) while(tmpx % pr[i] == 0) curp[i]++, tmpx /= pr[i];
		curp[rev[tmpy]]--, curp[rev[tmpx]]++;
	}
}
void solve() {
	cin >> n, ans = 0;
	for(int i = 1; i <= n; i++) e[i].clear();
	for(int i = 0; pr[i] <= n; i++) mn[i] = curp[i] = 0;
	for(int i = 1; i < n; i++) {
		int u = read(), v = read(), x = read(), y = read();
		e[u].push_back({v, x, y}), e[v].push_back({u, y, x});
	}
	dfs(1, 0, 1);
	for(int i = 1; pr[i] <= n; i++) ans = 1ll * ans * ksm(pr[i], -mn[i]) % mod;
	cout << ans << endl;
}
int main() {
	for(int i = 2; i < N; i++)
		if(!vis[i]) {
			pr[++cnt] = i, rev[i] = cnt;
			for(int j = i + i; j < N; j += i) vis[j] = 1;
		}
	for(int i = 1; i < N; i++) inv[i] = ksm(i, mod - 2);
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}
/*
10
2
1 2 10 5
2
1 2 1 2
2
1 2 1 2333
*/