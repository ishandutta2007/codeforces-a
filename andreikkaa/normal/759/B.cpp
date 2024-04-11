/*
* C++11 code template for contests.
* @author: Andrey Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

//#define ANDREIKKAA_TOPCODER
//#define ANDREIKKAA_ALLOCATOR
#define ANDREIKKAA_CLASS Solution
#define ANDREIKKAA_METHOD solve
#define ANDREIKKAA_PARAMETERS void
#define ANDREIKKAA_CALL
#define ANDREIKKAA_RETURN_TYPE void

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;
#define x first
#define y second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
const ld PI = acos(-1);

const int _ML = 200;
const char _inpf[] =
#if defined(ANDREIKKAA)
"input.txt"
#else
""
#endif
;
const char _outf[] =
#if defined(ANDREIKKAA)
""
#else
""
#endif
;

#if defined(ANDREIKKAA_ALLOCATOR)
char _mem[_ML * 1024LL * 1024LL];
size_t _ptr = 0;
inline void* operator new(size_t _x) { _ptr += _x; return _mem + _ptr - _x; }
inline void operator delete(void*) { }
#endif

template<typename T, typename U> inline ostream &operator << (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator >> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const vector<T> &_v) { if (_v.empty()) return _out; _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline istream &operator >> (istream &_in, vector<T> &_v) { for (auto &_i : _v) _in >> _i; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const map<T, U> &_m) { if (_m.empty()) return _out; _out << _m.begin()->first << ": " << _m.begin()->second; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", " << _it->first << ": " << _it->second; return _out; }

/* ________ CODE ________ */

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n;
	cin >> n;

	vector<int> t(n);
	cin >> t;

	const int INF = 30 * 1000 * 1000;
	vector<int> dp(n, INF);
	dp[0] = 20;
	cout << 20 << endl;
	int sum = 20;

	for (int i = 1; i < n; ++i)
	{
		dp[i] = dp[i - 1] + 20;
		int p1 = lower_bound(t.begin(), t.end(), t[i] - 89) - t.begin();
		--p1;
		int p2 = lower_bound(t.begin(), t.end(), t[i] - 1439) - t.begin();
		--p2;

		if (0 <= p1 && p1 < i)
			dp[i] = min(dp[i], dp[p1] + 50);
		if (p1 == -1)
			dp[i] = min(dp[i], 50);

		if (0 <= p2 && p2 < i)
			dp[i] = min(dp[i], dp[p2] + 120);
		if (p2 == -1)
			dp[i] = min(dp[i], 120);

		cout << dp[i] - sum << endl;
		sum += dp[i] - sum;
	}
}

/* ________ CODE ________ */

#if defined(ANDREIKKAA) || !defined(ANDREIKKAA_TOPCODER)
int main()
{
#if defined(ANDREIKKAA)
	time_t _start = clock();
#endif
#pragma warning(push)
#pragma warning(disable: 4127)
	if (sizeof(_inpf) > 1)
		freopen(_inpf, "r", stdin);
	if (sizeof(_outf) > 1)
		freopen(_outf, "w", stdout);
#pragma warning(pop)
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << setprecision(20);
	//cout << fixed;
	mainFunction(ANDREIKKAA_CALL);
#if defined(ANDREIKKAA)
	cerr << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl;
	while (true);
#endif
}
#else
class ANDREIKKAA_CLASS { public: ANDREIKKAA_RETURN_TYPE ANDREIKKAA_METHOD(ANDREIKKAA_PARAMETERS) { return mainFunction(ANDREIKKAA_CALL); } };
#endif