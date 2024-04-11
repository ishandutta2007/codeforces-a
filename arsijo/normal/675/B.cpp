#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ui MOD = 1e9 + 7;
const ld E = 1e-15;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
inline void read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
char wwww[12];
int kkkk;
inline void write(int x) {
	kkkk = 0;
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	while (x) {
		++kkkk;
		wwww[kkkk] = char(x % 10 + '0');
		x /= 10;
	}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar(' ');
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

void yes() {
	cout << "YES" << endl;
	exit(0);
}

void no() {
	cout << "NO" << endl;
	exit(0);
}

int n;

bool check(int v) {
	return 1 <= v && v <= n;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(9);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	cin >> n;

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		int l = 1, r = n;
		int min_sum = a + b + i + 1;
		int max_sum = a + b + i + n;
		l = max(l, min_sum - a - c - i);
		r = min(r, max_sum - a - c - i);
		l = max(l, min_sum - d - c - i);
		r = min(r, max_sum - d - c - i);
		l = max(l, min_sum - d - b - i);
		r = min(r, max_sum - d - b - i);
		ans += max(0, r - l + 1);
	}

	cout << ans << endl;

}