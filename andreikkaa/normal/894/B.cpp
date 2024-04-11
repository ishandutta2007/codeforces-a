/*
* C++11 code template for contests.
* @author: Andrei Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

#ifndef ANDREIKKAA
#pragma GCC optimize ("O3")
#endif
//#define ANDREIKKAA_ALLOCATOR
//#define ANDREIKKAA_INTERACTIVE
const int _ML = 500;
const char _inpf[] =
#ifdef ANDREIKKAA
"input.txt"
#else
""
#endif
;
const char _outf[] =
#ifdef ANDREIKKAA
""
#else
""
#endif
;

#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define rand rd
#define random_shuffle abcdefghijklmnopqrstuvwxyz
#ifndef ANDREIKKAA_INTERACTIVE
#define endl '\n'
#endif
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef double ld;
const ld PI = 3.14159265358979323846;
mt19937 rd(228);

#if defined(ANDREIKKAA_ALLOCATOR)
char _mem[_ML * 1024 * 1024];
size_t _ptr = 0;
inline void* operator new (size_t _x) { _ptr += _x; return _mem + _ptr - _x; }
inline void operator delete (void*) { }
#endif

template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }

/* ________ CODE ________ */

const int M = 1000 * 1000 * 1000 + 7;

ll bp(ll a, ll b)
{
	ll r = 1;
	while(b)
	{
		if(b & 1)
		{
			r = (r * a) % M;
		}
		
		b >>= 1;
		a = (a * a) % M;
	}
	
	return r;
}

inline void mainFunction()
{
	ll n, m, p;
	cin >> n >> m >> p;
	
	if(p == 1 || (n + m) % 2 == 0)
	{
		cout << bp(bp(2, n - 1), m - 1) << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	/*
	
	for(int i = 1; i < 10; ++i)
	{
		for(int j = 1; j < 10; ++j)
		{
			if(i * j > 25)
			{
				continue;
			}
			
			int ans = 0;
			for(int m = 0; m < (1 << (i * j)); ++m)
			{
				
				for(int x = 0; x < i; ++x)
				{
					int p = 1;
					for(int y = 0; y < j; ++y)
					{
						if((m >> (x * j + y)) & 1)
						{
							p *= -1;
						}
					}
					if(p == 1)
					{
						goto bad;
					}
				}
				for(int y = 0; y < j; ++y)
				{
					int p = 1;
					for(int x = 0; x < i; ++x)
					{
						if((m >> (x * j + y)) & 1)
						{
							p *= -1;
						}
					}
					if(p == 1)
					{
						goto bad;
					}
				}
				
				++ans;
				bad:;
			}
			
			cout << i << " " << j << " " << ans << " " << (1 << ((i - 1) * (j - 1))) << endl;
		}
	}*/
}

/* ________ CODE ________ */

int main()
{
#if defined(ANDREIKKAA)
	time_t _start = clock();
#endif
	if (_inpf[0] != '\0') assert(freopen(_inpf, "r", stdin) != nullptr);
	if (_outf[0] != '\0') assert(freopen(_outf, "w", stdout) != nullptr);
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << setprecision(18);
	//cout << fixed;	
	mainFunction();
#if defined(ANDREIKKAA)
	cout << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl;
#endif
}