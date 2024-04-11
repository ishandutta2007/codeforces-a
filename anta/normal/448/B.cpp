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
#include <cassert>
#include <limits>
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
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	bool ans1 = false, ans2 = false, ans3 = false;
	{	int j = 0;
		for(int i = 0; i < n; i ++) {
			if(j < m && s[i] == t[j])
				++ j;
		}
		ans1 = j == m;
	}
	{	string ss = s, st = t;
		sort(all(ss)); sort(all(st));
		ans2 = ss == st;
		{	int j = 0;
			for(int i = 0; i < n; i ++) {
				if(j < m && ss[i] == st[j])
					++ j;
			}
			ans3 = j == m;
		}
	}
	if(!ans3) puts("need tree");
	else if(ans1) puts("automaton");
	else if(ans2) puts("array");
	else puts("both");
	return 0;
}