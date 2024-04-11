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

const int maxn = 1005;
int n, m;
string a[maxn], b[maxn];
char tmp[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    a[i] = tmp;
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", tmp);
    b[i] = tmp;
  }
  return true;
}

void solve() {
  if (n != m) {
    printf(n > m ? "YES\n" : "NO\n");
    return;
  }
  int cnt = 0;
  set<string> st;
  for (int i = 0; i < n; i++) {
    st.insert(a[i]);
  }
  for (int j = 0; j < m; j++) {
    cnt += (st.find(b[j]) != st.end());
  }
  if (cnt & 1) {
    printf("YES\n");
    return;
  }
  printf("NO\n");
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