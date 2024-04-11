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
#include <complex>
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

int p[1000];
int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    s = 1000000 - s;
    vector<int> dists(n);
    int total = 0;
    rep(i, n) {
        int x, y;
        scanf("%d%d%d", &x, &y, &p[i]);
        dists[i] = x * x + y * y;
        total += p[i];
    }
    if(total < s) {
        puts("-1");
        return 0;
    }
    double l = 0, u = 1e10;
    rep(ii, 100) {
        double mid = (l + u) / 2;
        int sum = 0;
        rep(i, n) if(dists[i] <= mid)
            sum += p[i];
        if(sum >= s) u = mid; else l = mid;
    }
    printf("%.10f\n", sqrt(l));
    return 0;
}