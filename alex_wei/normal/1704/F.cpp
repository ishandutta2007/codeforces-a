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
  // #define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
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
}
using namespace IO;

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

#define alice return puts("Alice"), void()
#define bob return puts("Bob"), void()
constexpr int N = 5e5 + 5;
int n, R, B, f[N];
char s[N];
void solve() {
	scanf("%d%s", &n, s + 1);
	R = B = 0;
	for(int i = 1; i <= n; i++)
		if(s[i] == 'R') R++;
		else B++;
	if(R > B) alice;
	if(R < B) bob;
	int m = n / 2, ans = 0;
	for(int i = 1; i < n; i++) {
		if(s[i] == s[i + 1]) continue;
		int r = i + 1;
		while(r < n && s[r + 1] != s[r]) r++;
		ans ^= f[r - i + 1];
		i = r;
	}
	if(ans) alice;
	else bob;
}

int main() {
	for(int i = 2; i <= 200; i++) {
		static int buc[205];
		memset(buc, 0, sizeof(buc));
		for(int j = 2; j <= i; j++) buc[f[j - 2] ^ f[i - j]]++;
		while(buc[f[i]]) f[i]++;
	}
	for(int i = 201; i < N; i++) f[i] = f[i - 34];
  int T = 1;
  cin >> T;
  while(T--) solve();
  return 0;
}
/*
 RB 
 
*/