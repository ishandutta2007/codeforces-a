#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-11;
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
//#define DEBUG
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

	string a, b, c, d;
	cin >> a >> b >> c >> d;
	reverse(b.begin(), b.end());
	reverse(d.begin(), d.end());
	string x = a + b, y = c + d;
	x.erase(x.find('X'), 1);
	y.erase(y.find('X'), 1);

	for(int i = 0; i < 3; i++){
		if(x == y){
			cout << "YES";
			return 0;
		}
		string s;
		s += x[1];
		s += x[2];
		s += x[0];
		x = s;
	}

	cout << "NO";

}