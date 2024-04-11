// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 100005;

char s[N];
int n, q;

int ans;
void check(int pos, int dlt) {
  if (pos < 1 || pos + 2 > n) return ;
  if (s[pos] == 'a' && s[pos + 1] == 'b' && s[pos + 2] == 'c') ans += dlt;
}

int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  rep(i, 1, n - 2) check(i, 1);
  while (q--) {
    int pos = read();
    char ch = getchar();
    while (ch != 'a' && ch != 'b' && ch != 'c') ch = getchar();
    check(pos - 2, -1);
    check(pos - 1, -1);
    check(pos, -1);
    s[pos] = ch;
    check(pos - 2, 1);
    check(pos - 1, 1);
    check(pos, 1);
    print(ans, '\n');
  }
  return 0;
}