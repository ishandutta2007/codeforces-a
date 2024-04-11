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

int xorsum[1000002];
int main() {
    int n;
    scanf("%d", &n);
    xorsum[0] = 0;
    rer(i, 0, 1000000)
        xorsum[i+1] = xorsum[i] ^ i;
    int Q = 0;
    rer(i, 1, n) {
        //x mod i = 0..y
        int mid = (n+1) % i;
        if(((n+1) / i + 1) % 2 != 0) {
            Q ^= xorsum[mid] ^ xorsum[0];
        }
        if(((n+1) / i) % 2 != 0) {
            Q ^= xorsum[i] ^ xorsum[mid];
        }
    }
    rep(i, n) {
        int p;
        scanf("%d", &p);
        Q ^= p;
    }
    printf("%d\n", Q);
    return 0;
}