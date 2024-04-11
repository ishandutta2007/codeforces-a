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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5;
int n, m;
pair<int, pair<int, int> > es[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    v--;
    u--;
    es[i] = make_pair(w, make_pair(v, u));
  }
  return true;
}

int p[maxn], ts[maxn], c[maxn];

int get(int x) {
  return x == p[x] ? x : p[x] = get(p[x]);
}

bool unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    if (!c[x]) {
      c[x] = true;
      return true;
    }
    return false;
  }
  if (c[x] && c[y]) {
    return false;
  }
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  p[y] = x;
  ts[x] += ts[y];
  c[x] |= c[y];
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    p[i] = i;
    ts[i] = 1;
    c[i] = false;
  }
  sort(es, es + m, greater< pair<int, pair<int, int> > >());
  int res = 0;
  for (int i = 0; i < m; i++) {
    int v = es[i].second.first, u = es[i].second.second, w = es[i].first;
    if (unite(v, u)) {
      res += w;
    }
  }
  printf("%d\n", res);
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