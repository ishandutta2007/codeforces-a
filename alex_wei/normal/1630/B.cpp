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

template <class T1, class T2> void cmin(T1 &a, T2 b) {a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b) {a = a > b ? a : b;}

const int N = 2e5 + 5;
int n, k, x, y, buc[N], a[N], lim;
struct BIT {
	int c[N];
	void clear() {mem(c, 0, n + 2);}
	void add(int x, int v) {while(x <= n) c[x] += v, x += x & -x;}
	int query(int x) {int s = 0; while(x) s += c[x], x -= x & -x; return s;}
} tr;
void solve() {
	cin >> n >> k, lim = n + k + 1 >> 1;
	tr.clear(), mem(buc, 0, n + 2), y = n, x = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), buc[a[i]]++;
	for(int i = 1; i <= n; i++) if(buc[i]) tr.add(i, buc[i]);
	for(int i = 1; i <= n; i++) if(tr.query(n) >= lim) {
		int l = i, r = n;
		while(l < r) {
			int m = l + r >> 1;
			if(tr.query(m) >= lim) r = m;
			else l = m + 1;
		} if(r - i < y - x) x = i, y = r;
		tr.add(i, -buc[i]);
	} cout << x << " " << y << "\n";
	for(int i = 1, lst = 1, cur = 0; i <= n; i++) {
		if(a[i] >= x && a[i] <= y) cur++; else cur--;
		if(cur > 0 && k > 1) k--, cout << lst << " " << i << "\n", lst = i + 1, cur = 0;
		if(i == n) cout << lst << " " << n << "\n";
	}
	
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	return 0;
}