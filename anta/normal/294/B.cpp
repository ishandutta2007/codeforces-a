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
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER)
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
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

int main() {
    int n;
    scanf("%d", &n);
    static int t[101], w[101];
    rep(i, n) scanf("%d%d", &t[i], &w[i]);
    static int dp[101][201];    //(i * ) 
    mset(dp, INF);
    dp[0][0] = 0;
    rep(i, n) rep(j, 201) if(dp[i][j] != INF) {
        dp[i+1][j+t[i]] = min(dp[i+1][j+t[i]], dp[i][j]);
        dp[i+1][j] = min(dp[i+1][j], dp[i][j] + w[i]);
    }
    int r = INF;
    rep(j, 201) if(dp[n][j] <= j) r = min(r, j);
    printf("%d\n", r);
    return 0;
}