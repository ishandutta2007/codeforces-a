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

const int N = 2e5 + 5;
const int mod = 998244353;
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	} return s;
}

int n, m, buc[N], t;
int ans, tag = 1, prod = 1, fc[N], ifc[N];
struct BIT {
	int c[N];
	void add(int x, int v) {while(x < N) c[x] = (c[x] + v) % mod, x += x & -x;}
	int query(int x) {int s = 0; while(x) s = (s + c[x]) % mod, x -= x & -x; return s;}
} tr;
int main() {
	cin >> n >> m;
	for(int i = fc[0] = 1; i < N; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
	ifc[N - 1] = ksm(fc[N - 1], mod - 2);
	for(int i = N - 2; ~i; i--) ifc[i] = 1ll * ifc[i + 1] * (i + 1) % mod;
	for(int i = 1; i <= n; i++) buc[read()]++;
	for(int i = 1; i < N; i++) prod = 1ll * prod * ifc[buc[i]] % mod;
//	for(int i = 1; i < N; i++) c[i] = (c[i - 1] + 1ll * prod * fc[buc[i]] % mod * ifc[buc[i] - 1]) % mod;
	for(int i = 1; i < N; i++) if(buc[i]) tr.add(i, 1ll * prod * fc[buc[i]] % mod * ifc[buc[i] - 1] % mod);
	for(int i = 1; i <= m; i++) {
		t = read();
//		int coef = 1ll * tag * c[t - 1] % mod;
		int coef = 1ll * tag * tr.query(t - 1) % mod;
		ans = (ans + 1ll * coef * fc[n - i]) % mod;
		if(!buc[t]) break;
		int origin = (tr.query(t) - tr.query(t - 1) + mod) % mod;
		int nw = 1ll * origin * tag % mod;
		tag = 1ll * tag * fc[buc[t]] % mod * ifc[buc[t] - 1] % mod;
		if(--buc[t]) tr.add(t, (1ll * nw * fc[buc[t]] % mod * ifc[buc[t] - 1] % mod * ksm(tag, mod - 2) % mod - origin + mod) % mod);
		else tr.add(t, mod - origin);
		if(i == n) {ans = (ans + (n < m)) % mod; break;}
	}
	cout << ans << endl;
	return 0;
}