#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 25) - 1;
const int maxn = (int) 3e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
vector< int > g[maxn], A[4];
int n;
int u[maxn];
int m;

void dfs(int v, int l) {
	A[l].pb(v);
	u[v] = 1;
	for(int to: g[v]) {
		if(u[to] == 0) dfs(to, 1-l);
	}
}


void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		g[i].clear();
		u[i] = 0;
	}
	A[0].clear();
	A[1].clear();
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0);
	if(A[0].size() > A[1].size()) A[0].swap(A[1]);
	printf("%d\n",(int)A[0].size());
	for(auto x: A[0]) printf("%d ", x);
	printf("\n");

}

int main () {
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}