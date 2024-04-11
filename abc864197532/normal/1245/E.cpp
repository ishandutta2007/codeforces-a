#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, X = 864197532, N = 300000, logN = 18, K = 350;

int get(int a, int b) {
  if (a & 1) return a * 10 + 9 - b;
  return a * 10 + b;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <int> reach[100];
  int tmp;
  FOP (i,10,0) fop (j,0,10) {
    cin >> tmp;
    if (tmp) reach[get(i, j)].pb(get(i + tmp, j));
  }
  ld dp[100][2];
  dp[99][0] = dp[99][1] = 0;
  FOP (i,99,0) {
    dp[i][0] = dp[i][1] = 1 << 30;
    for (int j : reach[i]) {
      dp[i][0] = min(dp[i][0], dp[j][1]);
    }
    ld tmp = 0;
    fop (j,1,7) if (i + j < 100) tmp += min(dp[i + j][0], dp[i + j][1]);
    dp[i][1] = min(dp[i][1], (tmp + 6) / min(99 - i, 6));
    //cout << i << endl;
  }
  cout << fixed << setprecision(10) << min(dp[0][0], dp[0][1]) << endl;
}