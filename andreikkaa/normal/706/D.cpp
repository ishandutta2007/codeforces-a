/*
* C++11 code template for contests.
* @author: Andrey Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

/*______ DEFINES _______*/

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
//#define ANDREIKKAA_TOPCODER
//#define ANDREIKKAA_ALLOCATOR
#define ANDREIKKAA_CLASS Solution
#define ANDREIKKAA_METHOD solve
#define ANDREIKKAA_PARAMETERS 
#define ANDREIKKAA_CALL 
#define ANDREIKKAA_RETURN_TYPE void
#define forn(i, n) for(auto i = 0; i < (n); ++i)
#define fori(n) for(auto _ = 0; _ < (n); ++_)

typedef long long ll;
typedef long double ld;
const int MEMORY_LIMIT_MB = 200;
const int TIME_LIMIT_S = 1;
const char input_filename[] =
#if defined(ANDREIKKAA)
"input.txt"
#else
""
#endif
;
const char output_filename[] =
#if defined(ANDREIKKAA)
""
#else
""
#endif
;

/* ______ INCLUDES ______ */
#include <cassert>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <regex>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

/* _____ ALLOCATION _____ */

#if defined(ANDREIKKAA_ALLOCATOR)
char alloc_memory[MEMORY_LIMIT_MB * 1000 * 1000];
size_t alloc_pointer = 0;
inline void* operator new(size_t x) { alloc_pointer += x; return alloc_memory + alloc_pointer - x; }
inline void operator delete(void*) { }
#endif

/*____ I-O OPERATORS ____*/
template<typename T, typename U> inline ostream &operator<<(ostream &out, const pair<T, U> &p) { out << p.first << ' ' << p.second; return out; }
template<typename T, typename U> inline istream &operator >> (istream &in, pair<T, U> &p) { in >> p.first >> p.second; return in; }
template<typename T> inline ostream &operator<<(ostream &out, const vector<T> &v) { if (v.empty()) return out; out << v.front(); for (auto it = ++v.begin(); it != v.end(); ++it) out << ' ' << *it; return out; }
template<typename T> inline istream &operator >> (istream &in, vector<T> &v) { for (auto &i : v) in >> i; return in; }

/* _______ INPUT _________*/
class Reader
{
public:
	inline Reader(const string &filename) { if (not filename.empty()) assert(freopen(filename.c_str(), "r", stdin) != nullptr); }
	template<typename T> inline void operator()(T &x) { cin >> x; }
	template<typename T, typename... Args> inline void operator()(T &x, Args &... args) { operator()(x), operator()(args...); }
	template<typename T> inline T r() { T x; cin >> x; return x; }
};
Reader rd(input_filename);

/* _______ OUTPUT ________*/

class Printer
{
public:
	inline Printer(const string &filename) { if (not filename.empty()) assert(freopen(filename.c_str(), "w", stdout) != nullptr); }
	template<typename T> inline void p(const T x) { cout << x; }
	template<typename T, typename... Args> inline void p(const T x, const Args... args) { p(x), p(args...); }
	inline void operator()() { p('\n'); }
	template<typename T> inline void operator()(const T x) { p(x), p('\n'); }
	template<typename T, typename... Args> inline void operator()(const T x, const Args... args) { p(x), p(' '), operator()(args...); };
	inline void f() { cout.flush(); }
};
Printer pr(output_filename);

/* ________ CODE ________ */

struct
{
	int ptr[2];
	int cnt;
} t[10000000];
int mem = 2;

int add_t(int v, int x, int d)
{
	if (v == 0)
	{
		v = mem++;
	}
	++t[v].cnt;

	if (d != -1)
	{
		t[v].ptr[(x >> d) & 1] = add_t(t[v].ptr[(x >> d) & 1], x, d - 1);
	}
	return v;
}

void del_t(int v, int x, int d)
{
	assert(v != 0);
	--t[v].cnt;

	if (d != -1)
	{
		del_t(t[v].ptr[(x >> d) & 1], x, d - 1);
	}
}

int ask_t(int v, int x, int d)
{
	if (d == -1)
		return 0;

	assert(v != 0);

	int b = 1 - ((x >> d) & 1);
	if (t[t[v].ptr[b]].cnt == 0)
	{
		b = 1 - b;
	}
	assert(t[t[v].ptr[b]].cnt != 0);

	return (b << d) | ask_t(t[v].ptr[b], x, d - 1);
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	add_t(1, 0, 30);
	int q;
	rd(q);
	fori(q)
	{
		char c;
		int x;
		rd(c, x);

		if (c == '-')
		{
			del_t(1, x, 30);
		}
		else if (c == '+')
		{
			add_t(1, x, 30);
		}
		else
		{
			pr(x ^ ask_t(1, x, 30));
		}
	}
}

class ANDREIKKAA_CLASS
{
public:
	ANDREIKKAA_RETURN_TYPE ANDREIKKAA_METHOD(ANDREIKKAA_PARAMETERS)
	{
		cin.tie(nullptr);
		ios_base::sync_with_stdio(false);
		//cout << setprecision(20);
		//cout << fixed;
		return mainFunction(ANDREIKKAA_CALL);
	}
#if defined(ANDREIKKAA)
	inline ANDREIKKAA_CLASS() { _start = clock(); }
	inline ~ANDREIKKAA_CLASS() { cerr << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl; }
private:
	time_t _start;
#endif
};

#if defined(ANDREIKKAA) || !defined(ANDREIKKAA_TOPCODER)
int main()
{
	vector<int> x = { 0 };
	vector<int> y = { 1 };
	auto _s = new ANDREIKKAA_CLASS; _s->ANDREIKKAA_METHOD(ANDREIKKAA_CALL); delete _s;
#if defined(ANDREIKKAA)
	while (true);
#endif
}
#endif