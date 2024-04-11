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
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  return true;
}

void solve() {
  sort(a, a + n);
  sort(b, b + n);
  int k = n - (n / 4);
  int as = 0;
  for (int i = 0; i < k; ++i) {
    as += a[n - 1 - i];
  }
  int bs = 0;
  for (int i = 0; i < k; ++i) {
    bs += b[n - 1 - i];
  }
  int m = n;
  while (as < bs) {
    ++m;
    if (m % 4) {
      ++k;
      as += 100;
      if (k <= n) {
        bs += b[n - k];
      }
    } else {
      if (m - k - 1 < n) {
        as += 100 - a[m - k - 1];
      }
    }
  }
  printf("%d\n", m - n);
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