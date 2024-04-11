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

const int N = 1e6 + 5;

int n, c, a[N], ap[N], buc[N];
void solve() {
	cin >> n >> c, mem(buc, 0, c + 2), mem(ap, 0, c + 2);
	for(int i = 1; i <= n; i++) a[i] = read(), ap[a[i]] = 1;
	sort(a + 1, a + n + 1);
	if(a[1] != 1) return puts("NO"), void();
	n = unique(a + 1, a + n + 1) - a - 1;
	for(int i = 1; i <= n; i++) buc[a[i]]++;
	for(int i = 1; i <= c; i++) buc[i] += buc[i - 1];
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j * a[i] <= c; j++)
			if(ap[j]) ans += buc[min(c, j * a[i] + a[i] - 1)] - buc[j * a[i] - 1];
	if(ans == 1ll * n * (n + 1) / 2) puts("YES");
	else puts("NO");
}
int main() {
	int T; cin >> T;
	while(T--) solve();
	return 0;
}