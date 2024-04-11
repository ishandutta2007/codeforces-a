/*

















*/

#include <cstdio>

/** Interface */

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;

inline void readWord( char *s ) {
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}






#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define sz(a) (int)((a).size())
#define all(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
//#define int ll
#define NAME ""

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;

const int maxn = 1e5;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 3e18L;
const ld pi = acos((ld)-1.0);
const ld eps = (ld)1e-6;
const int di[] = {0, 0, 1,-1, 0};
const int dj[] = {1,-1, 0, 0, 0};
const int SQ = 1000;

int n, dep[maxn], ans[maxn + 1];
vi g[maxn], tps;

void pdfs(int v, int p) {
    int id = -1;
    for(int i = 0; i < sz(g[v]); i++)
        if(g[v][i] == p) id = i;
        else pdfs(g[v][i], v);
    if(id != -1) g[v].erase(g[v].begin() + id);
    tps.pb(v);
}

inline int solve(int len) {
    int res = 0;
    for(int v : tps) {
        int d1 = 0, d2 = 0;
        for(int to : g[v]) {
            if(dep[to] > d1) d2 = d1, d1 = dep[to];
            else if(dep[to] > d2) d2 = dep[to];
        }
        if(d1 + d2 + 1 >= len) {
            res++;
            dep[v] = 0;
        } else dep[v] = d1 + 1;
    }
    return res;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    n = readInt();
    for(int i = 0; i < n - 1; i++) {
        int u = readInt(), v = readInt(); u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    tps.reserve(n);
    pdfs(0, -1);
    for(int len = 1; len <= SQ; len++) ans[len] = solve(len);
    int pt = SQ + 1;
    while(pt <= n) {
        int mem = solve(pt); if(!mem) break;
        int lf = pt, rg = n;
        while(lf < rg) {
            int md = (lf + rg + 1) >> 1;
            if(solve(md) == mem) lf = md;
            else rg = md - 1;
        }
        for(int i = pt; i <= lf; i++) ans[i] = mem;
        pt = lf + 1;
    }
    for(int len = 1; len <= n; len++) writeInt(ans[len], '\n');
}