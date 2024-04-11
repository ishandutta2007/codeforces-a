#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn][2];
vector<int> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%d", &a[i][j]);
    }
    g[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

long long dp[maxn][2];

void dfs(int v, int p) {
  dp[v][0] = 0;
  dp[v][1] = 0;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
    for (int t = 0; t < 2; ++t) {
      long long cur = 0;
      for (int s = 0; s < 2; ++s) {
        cur = max(cur, dp[u][s] + abs(a[u][s] - a[v][t]));
      }
      dp[v][t] += cur;
    }
  }
}

void solve() {
  dfs(0, -1);
  printf("%lld\n", max(dp[0][0], dp[0][1]));
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}