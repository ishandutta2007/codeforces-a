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
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }

// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out

#define MAXN 112
#define MAXM 112345

pair<int,int> a[MAXN];
int n, m;

bool been[MAXN][MAXM];
int tab[MAXN][MAXM];

int pd(int i, int c)
{
	if (i == n || c > m)
		return max(0, m + 1 - c);

	if (been[i][c])
		return tab[i][c];	

	int retv = pd(i + 1, c);
	if (a[i].first + a[i].second >= c)
	{
		int sz = max(a[i].second, abs(a[i].first - c));
		int cst = sz - a[i].second;
		retv = min(retv, pd(i + 1, a[i].first + sz + 1) + cst);
	}

	been[i][c] = true;
	return tab[i][c] = retv;	
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	
	sort(a, a + n);

	cout << pd(0, 1) << endl;
}