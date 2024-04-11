#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

const int maxn = 2e5 + 10;
int n, P, a[maxn];

int main() {
  n = read(), P = read();
  rep(i, 1, n) a[i] = read();
  if (n > 3000) {
    puts("0");
    return 0;
  }
  int res = 1;
  rep(i, 1, n) {
    rep(j, i + 1, n) {
      res = 1ll * res * abs(a[i] - a[j]) % P;
    }
  }
  cout << res;
  return 0;
}