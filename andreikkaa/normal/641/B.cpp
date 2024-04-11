/*
* C++11 code template for contests.
* @author: Andrey Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

/*______ DEFINES _______*/

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
//#define ANDREIKKAA_ALLOCATOR
//#define ANDREIKKAA_UNSAFE_VECTOR

#ifdef ANDREIKKAA_UNSAFE_VECTOR
#define vec vector
#endif // ANDREIKKAA_UNSAFE_VECTOR

typedef long long ll;
typedef long double ld;

const int MEMORY_LIMIT_MB = 250;
const int TIME_LIMIT_S = 1;

const char input_filename[] =
#ifdef ANDREIKKAA
"input.txt"
#else
""
#endif
;
const char output_filename[] =
#ifdef ANDREIKKAA
""
#else
""
#endif
;

/* ______ INCLUDES ______ */

#include <cassert>
#include <cctype>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdint>
#include <ctgmath>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <forward_list>
#include <initializer_list>
#include <regex>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*_______ TYPES ________*/

template<typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
	out << p.first << ' ' << p.second;
	return out;
}

template<typename T, typename U>
istream &operator>>(istream &in, pair<T, U> &p)
{
	in >> p.first >> p.second;
	return in;
}

#ifndef ANDREIKKAA_UNSAFE_VECTOR
template<typename T>
class vec : public vector<T>
{
public:
	using vector<T>::vector;
	inline const T operator[](size_t x) const
	{
		return this->at(x);
	}
	inline T& operator[](size_t x)
	{
		return this->at(x);
	}
};

template<>
class vec<bool> : public vector<bool>
{
	using vector<bool>::vector;
public:
	inline const_reference operator[](size_t x) const
	{
		return this->at(x);
	}
	inline reference operator[](size_t x)
	{
		return this->at(x);
	}
};

template<typename T>
inline ostream &operator<<(ostream &out, const vec<T> &v)
{
	if (v.empty())
		return out;
	out << v.front();
	for (auto it = ++v.begin(); it != v.end(); ++it)
		out << ' ' << *it;
	return out;
}

template<typename T>
inline istream &operator>>(istream &in, vec<T> &v)
{
	for (auto &i : v)
		in >> i;
	return in;
}
#endif // !ANDREIKKAA_UNSAFE_VECTOR

template<typename T>
inline ostream &operator<<(ostream &out, const vector<T> &v)
{
	if (v.empty())
		return out;
	out << v.front();
	for (auto it = ++v.begin(); it != v.end(); ++it)
		out << ' ' << *it;
	return out;
}

template<typename T>
inline istream &operator>>(istream &in, vector<T> &v)
{
	for (auto &i : v)
		in >> i;
	return in;
}

/* _____ ALLOCATION _____ */

#ifdef ANDREIKKAA_ALLOCATOR
char alloc_memory[MEMORY_LIMIT_MB * 1000 * 1000];
size_t alloc_pointer = 0;
inline void* operator new(size_t x)
{
	alloc_pointer += x;
return alloc_memory + alloc_pointer - x;
}
inline void operator delete(void* x)
{

}
#endif

/* _______ INPUT _________*/

class Reader
{
public:
	inline Reader(const string &filename)
	{
		cin.tie(nullptr);
		ios_base::sync_with_stdio(false);
		if (not filename.empty())
			assert(freopen(filename.c_str(), "r", stdin) != nullptr);
	}

	template<typename T>
	inline void operator()(T &x)
	{
		cin >> x;
	}

	template<typename T, typename... Args>
	inline void operator()(T &x, Args &... args)
	{
		operator()(x), operator()(args...);
	}
};
Reader rd(input_filename);

/* _______ OUTPUT ________*/

class Printer
{
public:
	inline Printer(const string &filename)
	{
		//cout.precision(20);
		//cout << fixed;
		if (not filename.empty())
			assert(freopen(filename.c_str(), "w", stdout) != nullptr);
	}

	template<typename T>
	inline void out(const T x)
	{
		cout << x;
	}

	template<typename T, typename... Args>
	inline void out(const T x, const Args... args)
	{
		out(x), out(args...);
	}

	inline void operator()()
	{
		out('\n');
	}

	template<typename T>
	inline void operator()(const T x)
	{
		out(x), out('\n');
	}

	template<typename T, typename... Args>
	inline void operator()(const T x, const Args... args)
	{
		out(x), out(' '), operator()(args...);
	};
};
Printer pr(output_filename);

/* ________ CODE ________ */

class Solution
{
public:

	inline void solve()
	{
		int n, m, q;
		rd(n, m, q);

		int a[100][100];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				a[i][j] = 0;

		vec<int> v;
		for (int i = 0; i < q; ++i)
		{
			int t, x;
			rd(t, x);
			--x;

			if (t == 1)
			{
				v.push_back(x + 1);
				for (int j = 0; j + 1 < m; ++j)
				{
					a[x][j] ^= a[x][j + 1] ^= a[x][j] ^= a[x][j + 1];
				}
			}
			else if (t == 2)
			{
				v.push_back(-(x + 1));
				for (int j = 0; j + 1 < n; ++j)
				{
					a[j][x] ^= a[j + 1][x] ^= a[j][x] ^= a[j + 1][x];
				}
			}
			else
			{
				int y, val;
				rd(y, val);
				--y;
				if (a[x][y] != 0)
				{
					if (a[x][y] != val)
					{
						//assert(false);
					}
				}
				else
				{
					a[x][y] = val;
				}
			}
		}

		reverse(v.begin(), v.end());
		for (auto i : v)
		{
			if (i > 0)
			{
				--i;
				for (int j = m - 2; j >= 0; --j)
					a[i][j] ^= a[i][j + 1] ^= a[i][j] ^= a[i][j + 1];
			}
			else
			{
				i = -i - 1;
				for (int j = n - 2; j >= 0; --j)
					a[j][i] ^= a[j + 1][i] ^= a[j][i] ^= a[j + 1][i];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				pr.out(a[i][j], ' ');
			}
			pr();
		}
	}

	Solution()
	{
#ifdef ANDREIKKAA
		start = clock();
#endif // ANDREIKKAA
	}

	~Solution()
	{
#ifdef ANDREIKKAA
		cerr << "Time: " << (clock() - start) / (ld)CLOCKS_PER_SEC << endl;
#endif // ANDREIKKAA
	}
private:
#ifdef ANDREIKKAA
	time_t start;
#endif // ANDREIKKAA
};

int main()
{
	auto s = new Solution;
	s->solve();
	delete s;
#ifdef ANDREIKKAA 
#ifdef _WIN32
	while (true);
#endif // _WIN32
#endif // ANDREIKKAA
}