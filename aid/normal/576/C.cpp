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

const int maxn = (int) 1e6 + 5;
int n;
int xs[maxn][2];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &xs[i][j]);
    }
  }
  return true;
}

const int X = (int) 1e6, K = 1000;
vector<pair<int, int>> ps[K];

void solve() {
  for (int i = 0; i < K; i++) {
    ps[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int id = xs[i][0] / K;
    if (id >= K) {
      id = K - 1;
    }
    ps[id].push_back(make_pair(xs[i][1], i));
  }
  vector<int> ans;
  for (int i = 0; i < K; i++) {
    sort(ps[i].begin(), ps[i].end());
    if (i & 1) {
      reverse(ps[i].begin(), ps[i].end());
    }
    for (int j = 0; j < sz(ps[i]); j++) {
      ans.push_back(ps[i][j].second);
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i] + 1);
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