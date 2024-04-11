#pragma once

#include <bits/stdc++.h>
using namespace std;

template <class TH>
void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }

template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a)
{
	while (*sdbg != ',')
		cerr << *sdbg++;
	cerr << '=' << h << ',';
	_dbg(sdbg + 1, a...);
}

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

template <class Iterable, class = typename enable_if<!is_same<string, Iterable>::value>::type>
auto operator<<(ostream &os, Iterable v) -> decltype(os << *begin(v))
{
	os << "[";
	for (auto vv : v)
		os << vv << ", ";
	return os << "]";
}

#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }

// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	vector<int> d(n, inf);
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (s[i] == s[(i + 1) % n] || s[i] == s[(i - 1 + n) % n])
		{
			q.push(i);
			d[i] = 0;
		}

	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		if (d[(i + 1) % n] == inf)
		{
			q.push((i + 1) % n);
			d[(i + 1) % n] = d[i] + 1;
		}

		if (d[(i - 1 + n) % n] == inf)
		{
			q.push((i - 1 + n) % n);
			d[(i - 1 + n) % n] = d[i] + 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int x = min(d[i], k) % 2;
		cout << (((s[i] == 'W') ^ (x % 2)) ? 'W' : 'B');
	}

	cout << endl;

}