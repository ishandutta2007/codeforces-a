#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	// = sum - row * p * m - col * p
	//(x) = sum * x - (x*(x-1)/2) * p * m - C * p * x
	//row, col k
	int n, m, k, p;
	scanf("%d%d%d%d", &n, &m, &k, &p);
	vector<vector<int> > a(n, vector<int>(m));
	rep(i, n) rep(j, m) scanf("%d", &a[i][j]);
	vector<long long> row(k+1), col(k+1);
	{	priority_queue<pair<long long,int> > q;
		vector<long long> sum(n);
		rep(y, n) {
			int s = 0;
			rep(x, m) s += a[y][x];
			sum[y] = s;
			q.push(mp(sum[y], y));
		}
		int i = 0;
		while(i < k) {
			long long t = q.top().first; int y = q.top().second; q.pop();
			row[i+1] = row[i] + t;
			++ i;
			sum[y] -= p * m;
			q.push(mp(sum[y], y));
		}
	}
	{	priority_queue<pair<long long,int> > q;
		vector<long long> sum(m);
		rep(x, m) {
			int s = 0;
			rep(y, n) s += a[y][x];
			sum[x] = s;
			q.push(mp(sum[x], x));
		}
		int i = 0;
		while(i < k) {
			long long t = q.top().first; int x = q.top().second; q.pop();
			col[i+1] = col[i] + t;
			++ i;
			sum[x] -= p * n;
			q.push(mp(sum[x], x));
		}
	}
	long long ans = -INFL;
	rer(R, 0, k) {
		long long x = row[R] + col[k - R] - (long long)R * (k - R) * p;
		amax(ans, x);
	}
	cout << ans << endl;
    return 0;
}