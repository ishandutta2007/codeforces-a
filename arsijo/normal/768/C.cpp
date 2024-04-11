#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define prev time_prev
#define M_PI acos(-1)
#define remove tipa_remove
#define next tipa_next
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
template<typename T>
inline T sqr(T t) {
	return (t * t);
}
inline void read(ll &n) {
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
inline bool read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n') {
			if (ccc == '\n')
				return true;
			break;
		}
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
	return false;
}
char wwww[19];
int kkkk;
inline void write(ll y) {
	long long x = y;
	kkkk = 0;
	if (x < 0) {
		putchar('-');
		x *= -1;
	}
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	else
		while (x) {
			++kkkk;
			wwww[kkkk] = char(x % 10 + '0');
			x /= 10;
		}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
}

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif
#ifndef LOCAL
#define map unordered_map
#endif

int ar[1 << 10], ar2[1 << 10];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n, k, x;
	cin >> n >> k >> x;

	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ar[a]++;
	}

	int s = 0;

	while(k--) {
		s = 0;
		for(int i = 0; i < (1 << 10); i++) {
			if(ar[i]) {
				if(s) {
					ar[i]--;
					ar2[i]++;
					s = 0;
				}
			}
			if(ar[i]) {
				ar2[i] += ar[i] / 2;
				ar2[i ^ x] += ar[i] / 2;
				ar[i] &= 1;
			}
			if(ar[i]) {
				if(s == 1) {
					ar2[i]++;
				} else {
					ar2[i ^ x]++;
				}
				s ^= 1;
			}
		}
		for(int i = 0; i < (1 << 10); i++) {
			ar[i] = ar2[i];
			ar2[i] = 0;
		}
	}

	int ans1 = 10000;
	int ans2 = 0;

	for(int i = 0; i < (1 << 10); i++) {
		if(ar[i]) {
			ans1 = min(ans1, i);
			ans2 = max(ans2, i);
		}
	}

	cout << ans2 << " " << ans1 << endl;

}