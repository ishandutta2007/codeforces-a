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
vector<int> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    g[p].push_back(i);
  }
  return true;
}

int dep[maxn];

void getDep(int v) {
  dep[v] = 0;
  int maxi = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    getDep(u);
    if (dep[u] + 1 > dep[v]) {
      dep[v] = dep[u] + 1;
      maxi = i;
    }
  }
  if (maxi != -1) {
    swap(g[v][maxi], g[v].back());
  }
}

vector<int> p;
vector<int> ops;

void dfs(int v) {
  p.push_back(v);
  int k = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    for (int j = 0; j < k; j++) {
      ops.push_back(u);
    }
    dfs(u);
    k = dep[u] + 1;
  }
}

void solve() {
  getDep(0);
  p.clear();
  ops.clear();
  dfs(0);
  for (int i = 0; i < n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
  printf("%d\n", sz(ops));
  for (int i = 0; i < sz(ops); i++) {
    printf("%d ", ops[i]);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}