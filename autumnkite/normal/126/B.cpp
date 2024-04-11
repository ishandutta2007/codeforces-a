#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <bitset>
char buf[1 << 23], *ps = buf, *pt = buf;
#define getchar() (ps == pt && (pt = (ps = buf) + fread(buf, 1, 1 << 23, stdin), ps == pt) ? EOF : *ps++)
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
char pbuf[1 << 23], *pp = pbuf;
#define putchar(x) (pp == pbuf + (1 << 23) ? fwrite(pbuf, 1, 1 << 23, stdout), pp = pbuf : 0, *pp++ = x)
struct __IO_flusher{ ~__IO_flusher(){ fwrite(pbuf, 1, pp - pbuf, stdout); } } IO_flusher;
void print(int x, char ch = '\n'){
	if (x == 0) return putchar('0'), putchar(ch), void(0);
	int cnt = 0, num[25];
	for (x < 0 ? putchar('-'), x = -x : 0; x; x /= 10) num[++cnt] = x % 10;
	while (cnt) putchar(num[cnt] ^ '0'), --cnt;
	putchar(ch);
}
void print(const char *s){
	int len = strlen(s);
	for (register int i = 0; i < len; ++i) putchar(s[i]);
	putchar('\n');
}
const int N = 1000005;
int n, fail[N];
char s[N];
int main(){
	char ch;
	while (islower(ch = getchar())) s[++n] = ch;
	for (register int i = 2, j = 0; i <= n; ++i){
		while (j && s[j + 1] != s[i]) j = fail[j];
		fail[i] = j += (s[j + 1] == s[i]);
	}
	if (fail[n] == 0) return print("Just a legend"), 0;
	int ans = 0;
	for (register int i = 1; i < n; ++i)
		if (fail[i] == fail[n]) ans = fail[n];
	if (!ans) ans = fail[fail[n]];
	if (!ans) return print("Just a legend"), 0;
	for (register int i = 1; i <= ans; ++i) putchar(s[i]);
	putchar('\n');
}