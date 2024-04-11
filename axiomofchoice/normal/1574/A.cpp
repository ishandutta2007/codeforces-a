// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#define repeat(i, a, b) for (int i = (a), ib = (b); i < ib; i++)
#define repeat_back(i, a, b) for (int i = (b) - 1, ib = (a);i >= ib; i--)
#define mst(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define int ll
using namespace std;
namespace start {
	typedef long long ll; const int inf = INT_MAX >> 1; const ll INF = INT64_MAX >> 1;
	typedef double lf; const lf pi = acos(-1);
	typedef pair<int, int> pii;
	mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
		ll read() { ll x; if (scanf("%lld", &x) != 1) exit(0); return x; } // will detect EOF
		ll readfast() {
			ll x = 0, tag = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') tag = -1;
			for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; // ungetc(c, stdin);
			return x * tag;
		}
		template <typename T> void write(T x) {
			if (x < 0) x = -x, putchar('-');
			if (x >= 10) write(x / 10);
			putchar(x % 10 + 48);
		}
		void print(ll x, bool e = 0) { printf("%lld%c", x, " \n"[e]); }
		lf readf() { lf x; if (scanf("%lf",&x) != 1) exit(0); return x; } // will detect EOF
		void printlf(lf x, bool e = 0) { printf("%.12f%c", x, " \n"[e]); }
		template <typename T> vector<T> &operator<<(vector<T> &a, const T &b) { a.push_back(b); return a; }
		template <typename T> T sqr(const T &x) { return x * x; }
		// int cansel_sync = (ios::sync_with_stdio(0), cin.tie(0), 0);
		template <typename T> void sortunique(vector<T> &a) {
			sort(a.begin(), a.end());
			a.erase(unique(a.begin(), a.end()), a.end());
		}
	const int N = 3010;
	const lf eps = 1e-9;
	int mod = (0 ? 1000000007 : 998244353);
		ll D(ll x) { return x >= mod ? x - mod : x; }
		int mul(int a, int b, int m = mod) { return 1ll * a * b % m; }
		int qpow(int a, ll b, int m = mod) {
			int ans = 1;
			for (; b; a = mul(a, a, m), b >>= 1) if (b & 1)
				ans = mul(ans, a, m);
			return ans;
		}
} using namespace start;
#define OK { puts("Yes"); return; }
#define GG { puts("No"); return; }
#define debug 1
bool next_brastr(string &s) {
	int n=s.size(),dep=0;
	repeat_back(i,0,n){
		dep+=(s[i]==')')*2-1;
		if(s[i]=='(' && dep>0){
			dep--;
			int L=(n-i-1-dep)/2;
			int R=n-i-1-L;
			s.resize(i);
			s+=')'+string(L,'(')+string(R,')');
			return 1;
		}
	}
	return 0;
}
string s;
void Solve() {
	int n = read();
	s = "";
	for (int i = 0; i < n; i++) s += '(';
	for (int i = 0; i < n; i++) s += ')';
	for (int i = 0; i < n; i++) {
		printf("%s\n", s.c_str());
		next_brastr(s);
	}
}
signed main() {
	int T = 1; T = read();
	repeat (ca, 1, T + 1) {
		Solve();
	}
	return 0;
}