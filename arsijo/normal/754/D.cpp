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
ll MOD = 1e9 + 7;
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
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n, k;
	cin >> n >> k;

	vector<pair<ii, int> > v;
	for(int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		v.push_back(make_pair(make_pair(l, -r), i + 1));
	}

	int best = 0;

	sort(v.begin(), v.end());
	set<ii> s;

	for(pair<ii, int> a : v) {
		int l = a.first.first;
		s.insert(make_pair(-a.first.second, a.second));
		while(!s.empty() && s.begin()->first < l) {
			s.erase(s.begin());
		}
		while((int) s.size() > k) {
			s.erase(s.begin());
		}
		if((int) s.size() == k) {
			best = max(best, s.begin()->first - l + 1);
		}
	}

	cout << best << endl;
	s.clear();
	bool printed = false;
	for(pair<ii, int> a : v) {
		int l = a.first.first;
		s.insert(make_pair(-a.first.second, a.second));
		while(!s.empty() && s.begin()->first < l) {
			s.erase(s.begin());
		}
		while((int) s.size() > k) {
			s.erase(s.begin());
		}
		if((int) s.size() == k) {
			if(best == s.begin()->first - l + 1){
				for(ii v : s){
					cout << v.second << " ";
				}
				printed = true;
				break;
			}
		}
	}
	if(!printed){
		for(int i = 1; i <= k; i++){
			cout << i << " ";
		}
	}

}