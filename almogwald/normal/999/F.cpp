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
#define def(i) int i; into(i)
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
#define out(a) cout << a <<' ';
#define el << endl;
#define outv(arr,n) fori(i,n){out(arr[i])} co "" el
#define cas(p) co "Case #" << p+1 <<": ";
#define ex return 0; 
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define con continue;
#define br break;
#define maxi 1000000013
#define mod %1000000009;
#define wne(arr) while(!arr.empty())
#define _230 1073741824
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<lol, lol> point;
typedef pair<point, point> poin;
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
struct poing {
	int x;
	int y;
	int comp(poing a) {
		if (x == a.x) {
			if (y == a.y) {
				return -1;
			}
			return x;
		}
		if (x == a.y) {
			if (y == a.x) {
				return -1;
			}
			return x;
		}
		if (y == a.x || y == a.y) {
			return y;
		}
		return -1;
	}
};
#define num 100000
int main() {
	ios::sync_with_stdio(false);
	defn defk
	vector<vecl> are(n+1, vecl(n*k+1));
	vecl has(num);
	vecl likes(num);
	fori(i, n*k) {
		defa
			a--;
			has[a]++;
	}
	fori(i, n) {
		defa
			a--;
			likes[a]++;
	}
	vecl dif(k+1);
	forn(i, k+1) {
		into(dif[i])
	}
	forn(i, n+1) {
		forn(j, n*k+1) {
			fori(p, k+1) {
				if (j - p < 0) {
					br
				}
				are[i][j] = max(are[i][j], are[i - 1][j - p] + dif[p]);
			}
		}
	}
	lol ans = 0;
	fori(i, num) {
		ans += are[likes[i]][has[i]];
	}
	co ans el
	ex
}