#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
namespace fastIO{
#define getchar() my_getchar()
#define putchar(x) my_putchar(x)
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;
	char buf[IN_BUF], *ps = buf, *pt = buf;
	inline char my_getchar() {
		return ps == pt && (pt = (ps = buf) + fread(buf, 1, IN_BUF, stdin), ps == pt) ? EOF : *ps++;
	}
	template<typename T> inline bool read(T &x){
		char op = 0, ch = getchar();
		for (x = 0; !isdigit(ch) && ch != EOF; ch = getchar()) if (ch == '-') op ^= 1;
		if (ch == EOF) return false;
		for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ '0');
		if (ch != '.') return op ? x = -x : 0, true; else ch = getchar();
		T t = 1;
		for (; isdigit(ch); ch = getchar()) t /= 10, x += (ch ^ '0') * t;
		return op ? x = -x : 0, true;
	}
	inline int reads(char *s){
		int n = 0;
		char ch = getchar();
		for (; isspace(ch) && ch != EOF; ch = getchar()) ;
		for (; !isspace(ch) && ch != EOF; ch = getchar()) s[n++] = ch;
		return s[n] = '\0', n;
	}
	char pbuf[OUT_BUF], *pp = pbuf;
	struct _flusher{ ~_flusher(){ fwrite(pbuf, 1, pp - pbuf, stdout); } } OutputFlusher;
	inline void my_putchar(char x){
		pp == pbuf + OUT_BUF ? fwrite(pbuf, 1, OUT_BUF, stdout), pp = pbuf : 0, *pp++ = x;
	}
	template<typename T> inline void print_(T x){
		if (x == 0) return putchar('0'), void(0);
		int cnt = 0, num[25];
		for (x < 0 ? putchar('-'), x = -x : 0; x; x /= 10) num[++cnt] = x % 10;
		while (cnt) putchar(num[cnt] ^ '0'), --cnt;
	}
	template<typename T> inline void print(T x, char ch = '\n'){
		print_(x), putchar(ch);
	}
	inline void prints_(const char *s, int n = -1){
		if (n == -1) n = strlen(s);
		for (register int i = 0; i < n; ++i) putchar(s[i]);
	}
	inline void prints(const char *s, int n = -1, char ch = '\n'){
		prints_(s, n), putchar(ch);
	}
	template<typename T> inline void printd_(T x, int n){
		if (x < 0) x = -x, putchar('-');
		long long a, b;
		if (n == 0) return a = x + 0.5, print_(a), void(0);
		a = x, x -= a;
		while (n--) x *= 10;
		b = x + 0.5;
		print_(a), putchar('.'), print_(b);
	}
	template<typename T> inline void printd(T x, int n, char ch = '\n'){
		printd_(x, n), putchar(ch);
	}
}
using namespace fastIO;
int n, m;
char s[105][55];
std::vector< std::pair<int, int> > v;
bool check(int x, int y){
	for (register int i = 1; i <= m; ++i)
		if (s[x][i] != s[y][m - i + 1]) return 0;
	return 1;
}
void solve(){
	read(n), read(m);
	for (register int i = 1; i <= n; ++i) reads(s[i] + 1);
	v.clear();
	int id = 0;
	for (register int i = 1; i <= n; ++i){
		int k = 0;
		for (register int j = i; j <= n; ++j)
			if (check(i, j)){ k = j; break; }
		if (k == i) id = i;
		else if (k) v.push_back(std::make_pair(i, k));
	}
	int ans = v.size() * 2;
	if (id) ++ans;
	print(ans * m);
	for (auto p : v) prints_(s[p.first] + 1, m);
	if (id) prints_(s[id] + 1, m);
	std::reverse(v.begin(), v.end());
	for (auto p : v) prints_(s[p.second] + 1, m);
	putchar('\n');
}
int main(){
	int T;
	T = 1;
	// read(T);
	while (T--) solve();
}