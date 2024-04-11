#include <bits/stdc++.h>
using namespace std;
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

string add(string s){
	for(int i = (int) s.size() - 1; i >= 0; i--){
		if(s[i] == '9'){
			s[i] = '0';
		}else{
			s[i]++;
			return s;
		}
	}
	return "1" + s;
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

	int m, t;
	cin >> m >> t;

	string s;
	cin >> s;

	int p = s.find(".");
	string a = s.substr(0, p);
	string b = s.substr(p + 1);

	int n = (int) b.size();

	int dp[n + 1];
	dp[n - 1] = (b[n - 1] < '5' ? 2e9 : 1);
	for(int i = n - 2; i >= 0; i--){
		if(b[i] >= '5'){
			dp[i] = 1;
		}else if(b[i] == '4'){
			dp[i] = dp[i + 1] + 1;
		}else{
			dp[i] = 2e9;
		}
	}

	if(dp[0] <= t){
		cout << add(a) << endl;
		return 0;
	}
	string c = "";
	for(int i = 1; i < n; i++){
		c += b[i - 1];
		if(dp[i] <= t){
			cout << a << "." << add(c) << endl;
			return 0;
		}
	}

	cout << a << "." << b << endl;

}