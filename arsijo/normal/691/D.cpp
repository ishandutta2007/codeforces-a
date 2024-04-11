#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-10;
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

const int MAX = 1e6 + 1;
vector<int> vec[MAX], now;
int ar[MAX], n, m;
bool used[MAX];
void dfs(int pos){
	used[pos] = true;
	now.push_back(pos);
	for(int i = 0; i < (int) vec[pos].size(); i++){
		if(!used[vec[pos][i]]){
			dfs(vec[pos][i]);
		}
	}
}
int main() {

	sync;
	srand(time(NULL));
	cout.precision(5);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	read(n);
	read(m);
	for(int i = 1; i <= n; i++)
		read(ar[i]);
	for(int i = 1; i <= m; i++){
		int a, b;
		read(a);
		read(b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	vector<int> v;
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			now.clear();
			dfs(i);
			v.clear();
			for(int i = 0; i < (int) now.size(); i++)
				v.push_back(ar[now[i]]);
			sort(v.rbegin(), v.rend());
			sort(now.begin(), now.end());
			for(int i = 0; i < (int) now.size(); i++)
				ar[now[i]] = v[i];
		}
	}

	for(int i = 1; i <= n; i++)
		write(ar[i]);

}