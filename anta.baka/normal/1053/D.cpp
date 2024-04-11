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

const int maxn = 2e6;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e4;
const ll inf64 = 3e18L;
const ld pi = acos((ld)-1.0);
const ld eps = (ld)1e-6;
const int di[] = {0, 0, 1,-1, 0};
const int dj[] = {1,-1, 0, 0, 0};
const int SQ = 1000;

vi lp(maxn + 1);
vector<bool> on(maxn + 1, false);
vi hi(maxn + 1, 0);

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    iota(all(lp), 0);
    for(int i = 2; i * i <= maxn; i++)
        if(lp[i] == i)
            for(int j = i * i; j <= maxn; j += i)
                if(i < lp[j])
                    lp[j] = i;
    int n; cin >> n; vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    for(int i = n - 1; i >= 0; i--)
        if(on[a[i]]) {
            int x = --a[i];
            while(x != 1) on[lp[x]] = true, x /= lp[x];
        } else on[a[i]] = true;
    bool flag = false;
    for(int x : a) {
        bool bad = true;
        while(x != 1) {
            int pr = lp[x], pw = 0;
            while(x % pr == 0) x /= pr, pw++;
            if(pw > hi[pr]) bad = false, hi[pr] = pw;
        }
        if(bad) flag = true;
    }
    ll ans = 1;
    for(int i = 2; i <= maxn; i++)
        while(hi[i]--)
            ans = (ans * i) % M;
    cout << (ans + flag) % M;
}