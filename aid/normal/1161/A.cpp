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
int n, k;
int x[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &x[i]);
    x[i]--;
  }
  return true;
}

int fst[maxn], lst[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    fst[i] = inf;
    lst[i] = -1;
  }
  for (int i = 0; i < k; i++) {
    fst[x[i]] = min(fst[x[i]], i);
    lst[x[i]] = max(lst[x[i]], i);
  }
  int res = 0;
  for (int a = 0; a < n; a++) {
    for (int b = a - 1; b <= a + 1; b++) {
      if (b < 0 || b >= n) {
        continue;
      }
      if (lst[a] == -1 || lst[b] == -1) {
        res++;
        continue;
      }
      if (b == a) {
        continue;
      }
      if (lst[b] < fst[a]) {
        res++;
      }
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