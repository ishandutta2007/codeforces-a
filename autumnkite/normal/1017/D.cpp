#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>

#define debug(...) fprintf(stderr, __VA_ARGS__)

#ifndef AT_HOME
#define getchar() IO::myGetchar()
#define putchar(x) IO::myPutchar(x)
#endif

namespace IO {
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;

	inline char myGetchar() {
		static char buf[IN_BUF], *ps = buf, *pt = buf;
		if (ps == pt) {
			ps = buf, pt = buf + fread(buf, 1, IN_BUF, stdin);
		}
		return ps == pt ? EOF : *ps++;
	}

	template<typename T>
	inline bool read(T &x) {
		bool op = 0;
		char ch = getchar();
		x = 0;
		for (; !isdigit(ch) && ch != EOF; ch = getchar()) {
			op ^= (ch == '-');
		}
		if (ch == EOF) {
			return false;
		}
		for (; isdigit(ch); ch = getchar()) {
			x = x * 10 + (ch ^ '0');
		}
		if (op) {
			x = -x;
		}
		return true;
	}

	inline int readStr(char *s) {
		int n = 0;
		char ch = getchar();
		for (; isspace(ch) && ch != EOF; ch = getchar())
			;
		for (; !isspace(ch) && ch != EOF; ch = getchar()) {
			s[n++] = ch;
		}
		s[n] = '\0';
		return n;
	}

	inline void myPutchar(char x) {
		static char pbuf[OUT_BUF], *pp = pbuf;
		struct _flusher {
			~_flusher() {
				fwrite(pbuf, 1, pp - pbuf, stdout);
			}
		};
		static _flusher outputFlusher;
		if (pp == pbuf + OUT_BUF) {
			fwrite(pbuf, 1, OUT_BUF, stdout);
			pp = pbuf;
		}
		*pp++ = x;
	}

	template<typename T>
	inline void print_(T x) {
		if (x == 0) {
			putchar('0');
			return;
		}
		std::vector<int> num;
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		for (; x; x /= 10) {
			num.push_back(x % 10);
		}
		while (!num.empty()) {
			putchar(num.back() ^ '0');
			num.pop_back();
		}
	}

	template<typename T>
	inline void print(T x, char ch = '\n') {
		print_(x);
		putchar(ch);
	}

	inline void printStr_(const char *s, int n = -1) {
		if (n == -1) {
			n = strlen(s);
		}
		for (int i = 0; i < n; ++i) {
			putchar(s[i]);
		}
	}

	inline void printStr(const char *s, int n = -1, char ch = '\n') {
		printStr_(s, n);
		putchar(ch);
	}
}
using namespace IO;

int n, m, q, w[12];
int a[1 << 12];
int sum[1 << 12];
int f[1 << 12][105];
char tmp[15];

void solve() {
	read(n), read(m), read(q);
	for (int i = 0; i < n; ++i) {
		read(w[i]);
		sum[1 << i] = w[i];
	}
	for (int i = 0; i < m; ++i) {
		readStr(tmp);
		int x = 0;
		for (int j = 0; j < n; ++j) {
			x |= (tmp[j] ^ '0') << j;
		}
		++a[x];
	}
	sum[0] = 0;
	for (int i = 1; i < (1 << n); ++i) {
		sum[i] = sum[i & (i - 1)] + sum[i & -i];
	}
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			int mask = (1 << n) - 1;
			mask ^= i ^ j;
			if (sum[mask] <= 100) {
				f[i][sum[mask]] += a[j];
			}
		}
		for (int j = 1; j <= 100; ++j) {
			f[i][j] += f[i][j - 1];
		}
	}
	while (q--) {
		int x = 0, k;
		readStr(tmp), read(k);
		for (int j = 0; j < n; ++j) {
			x |= (tmp[j] ^ '0') << j;
		}
		print(f[x][k]);
	}
}

int main() {
	int T = 1;
//	read(T);
	while (T--) {
		solve();
	}
}