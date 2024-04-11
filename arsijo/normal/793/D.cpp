#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e13 + 7;
const ld E = 1e-8;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef M_PI
#define M_PI 3.141592653589793238462643383
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
	putchar(' ');
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n, k, m;

const int MAX = 100;

vector<ii> vec[MAX];

int dp[MAX][MAX][MAX][2];

inline void upd(int &a, int b) {
	if (a == 0)
		a = b;
	else
		a = min(a, b);
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(12);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> k >> m;

	while(m--) {
		int a, b, d;
		cin >> a >> b >> d;
		vec[b].push_back(make_pair(a, d));
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i][1][0] = 1;
		dp[i][i][1][1] = 1;
	}
	for (int len = 0; len < n; len++) {
		for (int j = 1; j + len <= n; j++) {
			int l = j, r = j + len;
			for(int size = 1; size - 1 <= len; size++) {
				if(dp[l][r][size][0]) {
					for (ii a : vec[l]) {
						if (a.first < l) {
							upd(dp[a.first][r][size + 1][0], dp[l][r][size][0] + a.second);
						} else if (a.first > r) {
							upd(dp[l][a.first][size + 1][1], dp[l][r][size][0] + a.second);
						}

					}
				}
				if (dp[l][r][size][1]) {
					for (ii a : vec[r]) {
						if (a.first < l) {
							upd(dp[a.first][r][size + 1][0], dp[l][r][size][1] + a.second);
						} else if (a.first > r) {
							upd(dp[l][a.first][size + 1][1], dp[l][r][size][1] + a.second);
						}
					}
				}
			}

		}
	}
	int ans = 1e9;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			if(dp[i][j][k][0]) {
				upd(ans, dp[i][j][k][0]);
			}
			if(dp[i][j][k][1]) {
				upd(ans, dp[i][j][k][1]);
			}

		}
	}
	if(ans == 1e9){
		cout << -1 << endl;
	}else{
		cout << ans - 1 << endl;
	}


}