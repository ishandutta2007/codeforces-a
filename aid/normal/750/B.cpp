#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 55;
int n;
int xx[maxn];
char tmp[100];
string ss[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%s", &xx[i], tmp);
    ss[i] = tmp;
  }
  return true;
}

const int X = 20000;

void solve() {
  int x = 0;
  for (int i = 0; i < n; i++) {
    int dx = xx[i];
    string s = ss[i];
    if (s[0] == 'W' || s[0] == 'E') {
      if (x == 0 || x == X) {
        printf("NO\n");
        return;
      }
    } else {
      if (s[0] == 'N') {
        dx *= -1;
      }
      x += dx;
      if (x < 0 || x > X) {
        printf("NO\n");
        return;
      }
    }
  }
  if (x) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}