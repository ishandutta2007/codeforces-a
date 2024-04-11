#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

class Solver {
public:

  void solve() {
    int n;
    cin>> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    int ans = -INF;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, a[i] - a[(i + 1) % n]);
    }
    for (int i = 1; i < n; ++i) {
      ans = max(ans, a[i] - a[0]);
    }
    for (int i = 0; i < n - 1; ++i) {
      ans = max(ans, a[n - 1] - a[i]);
    }
    cout << ans << "\n";
  }

private:

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    Solver{}.solve();
  }
}