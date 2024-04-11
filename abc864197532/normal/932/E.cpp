#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second
const long long mod = 1e9 + 7;

lli mypow(lli a, int b) {
  if (b < 0) return 0;
  lli ans = 1;
  for (; b; b >>= 1, a = a * a % mod) {
    if (b & 1) ans = ans * a % mod;
  }
  return ans;
}

void add(lli &a, lli b) {
  a += b;
  if (a >= mod) a -= mod;
}

int main () {
  int n, k;
  cin >> n >> k;
  lli dp[k + 1][k + 1];
  fop (i,0,k+1) {
    fop (j,0,k+1) {
      if (i) {
        dp[i][j] = 0;
        add(dp[i][j], j * dp[i-1][j] % mod);
        if (n > j) add(dp[i][j], (n - j) * dp[i-1][j+1] % mod);
      } else {
        dp[i][j] = mypow(2, n - j);
      }
    }
  }
  cout << dp[k][0] << endl;
}