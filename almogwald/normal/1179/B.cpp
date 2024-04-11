#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <math.h>
using namespace std;
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define forrb(i,a,b,c) for(int i=a;i>b;i-=c)
#define fori(i,n) forr(i,0,n,1)
#define forib(i,n) forrb(i,n-1,-1,1)
#define forn(i,n) forr(i,1,n,1)
#define fornb(i,n) forrb(i,n-1,0,1)
#define fort(i,m,n) forr(i,m,n,1)
#define fortb(i,m,n) forrb(i,n-1,m-1,1)
#define forin(i,arr) fori(i,arr.size())
#define forinb(i,arr) forib(i,arr.size())
#define into(i) cin >> i;
#define def(i) lol i; into(i)
#define deft(t,i) t i; into(i)
#define defn def(n)
#define defp def(p)
#define defm def(m)
#define defk def(k)
#define defa def(a)
#define defb def(b)
#define defc def(c)
#define defd def(d)
#define vec(a) vector<a>
#define co cout <<
#define cas(p) co "Case #" << p+1 <<": ";
#define el << endl;
#define ell << '\n';
#define ex return 0;
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define con continue;
#define br break;
#define out(i) co i <<' ';
#define outv(a,n) fori(iere,n){out(a[iere])} co "" el;
#define maxi 1000000013
#define mod %1000000009;
#define wne(arr) while(!arr.empty())
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<lol, lol> point;
typedef pair<point, int> poin;
#define all(a) a.begin(),a.end()
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
bool myfunc(point i, point j) {
	return i.first > j.first || (i.first == j.first && i.second > j.second);
}
int lca(int a, int b, vector<veci> & f, veci & d,int c) {
	if (a == b) {
		return a;
	}
	while (d[a] > d[b]) {
		while (d[f[c][a]] < d[b]) {
			c--;
		}
		a = f[c][a];
		if (d[a] == d[b]) {
			c = 19;
		}
	}
	if (d[a] < d[b]) {
		while (d[f[c][b]] < d[a]) {
			c--;
		}
		b = f[c][b];
		if (d[a] == d[b]) {
			c = 19;
		}
	}
	while (c >= 0) {
		if (f[c][b] != f[c][a]) {
			b = f[c][b];
			a = f[c][a];
		}
		c--;
	}
	return f[0][a];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	defn defm
		int addx = 1;
	int addy = 1;
	int side = 0;
	while (n > 0 && m > 0) {
		if (n == 1) {
			if (side == 0) {
				out(addx) co addy ell
					addy++;
			}
			else {
				out(addx) co addy+m-1 ell
			}
			m--;
			side = 1 - side;
			con
		}
		if (m == 1) {
			if (side == 0) {
				out(addx) co addy ell
					addx++;
			}
			else {
				out(addx + n - 1) co addy ell
			}
			n--;
			side = 1 - side;
			con
		}
		fori(i, n) {
			if (side == 0) {
				out(addx+i) co addy ell
					out(addx+n-1-i) co addy+m-1 ell
			}
			else {
				out(addx + n - 1 - i) co addy + m - 1 ell
				out(addx + i) co addy ell
			}
		}
		forn(i, m-1) {
			if (side == 0) {
				out(addx + n - 1) co addy+i ell
					out(addx) co addy + m - 1-i ell
			}
			else {
				out(addx) co addy + m - 1 - i ell
				out(addx + n - 1) co addy + i ell
					
			}
		}
		n -= 2;
		m -= 2;
		addx++;
		addy++;
		side = 1 - side;
	}
	ex
}