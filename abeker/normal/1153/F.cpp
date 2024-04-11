#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;
const int MOD = 998244353;
const int INV_TWO = (MOD + 1) / 2;
const int INV_THREE = (MOD + 1) / 3;
const int LOG = 20;

int N, K, L;
int pw_root[LOG], pw_inv[LOG];
int fact[2 * MAXN], inv[2 * MAXN];

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int pot(int x, int y) {
  int res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      res = mul(res, x);
    x = mul(x, x);
  }
  return res;
}

void rec(vector <int> &a, int omega, bool invert) {
  int n = a.size();
  if (n == 1)
    return;
  vector <int> even(n / 2), odd(n / 2);
  for (int i = 0; i < n / 2; i++) {
    even[i] = a[2 * i];
    odd[i] = a[2 * i + 1];
  }
  int curr = 1;
  int nxt = mul(omega, omega);
  rec(even, nxt, invert);
  rec(odd, nxt, invert);
  for (int i = 0; i < n / 2; i++) {
    int tmp = mul(odd[i], curr);
    a[i] = add(even[i], tmp);
    a[i + n / 2] = add(even[i], -tmp);
    curr = mul(curr, omega);
  }
  if (invert)
    for (auto &it : a)
      it = mul(it, INV_TWO);
}

void ntt(vector <int> &a, int lg, bool invert) {
  a.resize(1 << lg);
  rec(a, invert ? pw_root[lg] : pw_inv[lg], invert);
}

vector <int> conv(vector <int> a, vector <int> b) {
  int ex = 1;
  int len_a = a.size(), len_b = b.size();
  while ((1 << ex - 1) < max(len_a, len_b))
    ex++;
  ntt(a, ex, false);
  ntt(b, ex, false);
  for (int i = 0; i < 1 << ex; i++)
    a[i] = mul(a[i], b[i]);
  ntt(a, ex, true);
  a.resize(len_a + len_b - 1);
  return a;
}

void load() {
  scanf("%d%d%d", &N, &K, &L);
}

int solve() {
  for (int i = 0; i < LOG; i++) {
    pw_root[i] = pot(3, MOD - 1 >> i);
    pw_inv[i] = pot(INV_THREE, MOD - 1 >> i);
  }
  fact[0] = inv[0] = 1;
  for (int i = 1; i <= 2 * N + 1; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv[i] = pot(fact[i], MOD - 2);
  }
  vector <int> h1(N + 1), h2(N + 1);
  for (int i = 0; i <= N; i++) {
    h1[i] = i < K ? 0 : inv[i];
    h2[i] = i % 2 ? MOD - inv[i] : inv[i];
  }
  int sol = 0, curr = 1;
  vector <int> h = conv(h1, h2);
  for (int i = 0; i <= N; i++) {
    sol = add(sol, mul(mul(curr, mul(mul(fact[i], fact[i]), mul(inv[2 * i + 1], inv[N - i]))), h[i]));
    curr = mul(curr, 2);
  }
  return mul(sol, mul(fact[N], L));
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}