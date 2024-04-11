// Author: wlzhouzhuan
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))

template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 20005;
char a[N];
int n;

void solve() {
  scanf("%d%s", &n, a + 1);
  int half = n / 2;
  for (int i = half + 1; i <= n; i++) {
    if (a[i] == '0') {
      printf("%d %d %d %d\n", 1, i, 1, i - 1);
      return ;
    }
  }
  for (int i = half; i >= 1; i--) {
    if (a[i] == '0') {
      printf("%d %d %d %d\n", i, n, i + 1, n);
      return ;
    }
  }
  printf("%d %d %d %d\n", 1, half, 2, half + 1);
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}