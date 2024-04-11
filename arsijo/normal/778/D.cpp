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
ll MOD = 1e9 + 9;
const ld E = 1e-7;
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
#define left tipa_left
#define right tipa_right
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

const int MAX = 52;
char ar[MAX][MAX];
int n, m;
vector<ii> res;

void change(int x, int y) {
	res.push_back(make_pair(x, y));
	dbg
		cout << "! " << x << " " << y << endl;
	if (ar[x][y] == 'L') {
		assert(ar[x + 1][y] == 'L');
		assert(ar[x][y + 1] == 'R');
		assert(ar[x + 1][y + 1] == 'R');
		ar[x][y] = ar[x][y + 1] = 'U';
		ar[x + 1][y] = ar[x + 1][y + 1] = 'D';
	} else {
		assert(ar[x][y] == 'U');
		assert(ar[x + 1][y] == 'D');
		assert(ar[x][y + 1] == 'U');
		assert(ar[x + 1][y + 1] == 'D');
		ar[x][y] = ar[x + 1][y] = 'L';
		ar[x][y + 1] = ar[x + 1][y + 1] = 'R';
	}
}

void need_left(int, int);

void need_up(int x, int y) {
	dbg
		cout << "up " << x << " " << y << endl;
	if (ar[x][y] == 'U')
		return;
	assert(ar[x][y] == 'L');
	need_left(x + 1, y);
	change(x, y);
}

void need_left(int x, int y) {
	dbg
		cout << "left " << x << " " << y << endl;
	if (ar[x][y] == 'L')
		return;
	assert(ar[x][y] == 'U');
	need_up(x, y + 1);
	change(x, y);
}

char need[MAX][MAX];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> ar[i][j];
		}
	}

	if(n % 2 == 0) {
		for(int i = 1; i <= n; i += 2) {
			for(int j = 1; j <= m; j++) {
				need_up(i, j);
			}
		}
	} else {
		for(int j = 1; j <= m; j += 2) {
			for(int i = 1; i <= n; i++) {
				need_left(i, j);
			}
		}
	}
	vector<ii> ans;
	for(ii a : res) {
		ans.push_back(a);
	}
	res.clear();

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> ar[i][j];
		}
	}
	if(n % 2 == 0) {
		for(int i = 1; i <= n; i += 2) {
			for(int j = 1; j <= m; j++) {
				need_up(i, j);
			}
		}
	} else {
		for(int j = 1; j <= m; j += 2) {
			for(int i = 1; i <= n; i++) {
				need_left(i, j);
			}
		}
	}
	while(!res.empty()){
		ans.push_back(res.back());
		res.pop_back();
	}
	cout << ans.size() << endl;
	for(ii a : ans) {
		cout << a.first << " " << a.second << endl;
	}
}