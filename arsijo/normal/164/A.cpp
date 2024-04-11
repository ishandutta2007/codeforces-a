#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
char ccc;
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 1e5;
vector<int> v1[MAX], v2[MAX];
bool ok1[MAX], ok2[MAX];
int ar[MAX];

void dfs1(int pos){
	ok1[pos] = true;
	for(int i = 0; i < (int) v1[pos].size(); i++){
		if(!ok1[v1[pos][i]]){
			dfs1(v1[pos][i]);
		}
	}
}

void dfs2(int pos){
	ok2[pos] = true;
	if(ar[pos] == 1)
		return;
	for(int i = 0; i < (int) v2[pos].size(); i++){
		if(!ok2[v2[pos][i]]){
			dfs2(v2[pos][i]);
		}
	}
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> ar[i];

	while(m--){
		int a, b;
		cin >> a >> b;
		a--, b--;
		v1[a].push_back(b);
		v2[b].push_back(a);
	}

	for(int i = 0; i < n; i++){
		if(ar[i] == 1 && !ok1[i]){
			dfs1(i);
		}else if(ar[i] == 2 && !ok2[i]){
			dfs2(i);
		}
	}

	for(int i = 0; i < n; i++)
		cout << (ok1[i] && ok2[i] ? 1 : 0) << endl;

}