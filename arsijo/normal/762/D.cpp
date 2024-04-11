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
inline ld sqr(ld t) {
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

const int MAX = 1e5 + 10;
ll dp[MAX][8][3];
int ar[MAX][3];

inline void upd(ll &a, ll b) {
	a = max(a, b);
}

inline bool in(int a, int i) {
	return ((a & (1 << i)) != 0);
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < 8; j++) {
			for(int z = 0; z < 3; z++) {
				dp[i][j][z] = -1e18;
			}
		}
	}

	int n;
	cin >> n;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < n; j++) {
			cin >> ar[j][i];
		}
	}

	dp[0][1][0] = ar[0][0];

	for(int i = 0; i < n; i++) {
		upd(dp[i + 1][7][2], dp[i][1][0] + ar[i][1] + ar[i][2] + ar[i + 1][0] + ar[i + 1][1] + ar[i + 1][2]);
		upd(dp[i + 1][7][0], dp[i][4][2] + ar[i][1] + ar[i][0] + ar[i + 1][0] + ar[i + 1][1] + ar[i + 1][2]);
		for(int j = 1; j < 8; j++) {
			for(int z = 0; z < 3; z++) {
				if(z && !in(j, z - 1)) {
					upd(dp[i][j ^ (1 << (z - 1))][z - 1], dp[i][j][z] + ar[i][z - 1]);
				}
				if(z < 2 && !in(j, z + 1)) {
					upd(dp[i][j ^ (1 << (z + 1))][z + 1], dp[i][j][z] + ar[i][z + 1]);
				}
				upd(dp[i + 1][1 << z][z], dp[i][j][z] + ar[i + 1][z]);
			}
		}
	}

	ll ans = -1e18;
	for(int i = 1; i < 8; i++) {
		ans = max(ans, dp[n - 1][i][2]);
	}

	cout << ans << endl;

}