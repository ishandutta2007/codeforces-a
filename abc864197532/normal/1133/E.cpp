#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100087, logN = 17;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> a(n), pre(n);
  fop (i,0,n) cin >> a[i];
  sort(all(a));
  for (int i = 0, j = 0; j < n; ++j) {
    while (i < j and a[j] - a[i] > 5) i++;
    pre[j] = i;
  }
  int dp[n + 1][k];
  fop (i,0,k) dp[0][i] = 0;
  fop (i,1,n+1) {
    fop (j,0,k) {
      if (j) {
        dp[i][j] = max(dp[i - 1][j], dp[pre[i - 1]][j - 1] + i - pre[i - 1]);
      } else {
        dp[i][j] = max(dp[i - 1][j], i - pre[i - 1]);
      }
    }
  }
  cout << dp[n][k - 1] << endl;
}