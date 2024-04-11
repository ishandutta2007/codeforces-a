#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-8;
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

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n, m;
	cin >> n >> m;

	int ar[n + 1];
	ms(ar);

	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		ar[a] = i;
	}

	int t[n + 2];
	ms(t);

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a = ar[a];
		b = ar[b];
		if(a > b)
			swap(a, b);
		t[b - 1] = max(t[b - 1], a);
	}

	ll ans = 0;
	for(int l = 0, r = 0; r < n; r++){
		l = max(l, t[r]);
		ans += r - l + 1;
	}
	cout << ans;

}