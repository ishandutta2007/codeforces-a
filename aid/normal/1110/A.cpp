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

const int maxk = (int) 1e5 + 5;
int b, k;
int a[maxk];

bool read() {
  if (scanf("%d%d", &b, &k) < 2) {
    return false;
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

void solve() {
  if (b & 1) {
    int x = 0;
    for (int i = 0; i < k; i++) {
      x ^= (a[i] & 1);
    }
    printf(x ? "odd\n" : "even\n");
  } else {
    printf((a[k - 1] & 1) ? "odd\n" : "even\n");
  }
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