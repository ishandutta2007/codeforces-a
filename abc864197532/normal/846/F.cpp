#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 1000001, logN = 17;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tmp;
  cin >> n;
  vector <int> pos[N];
  fop (i,0,N) pos[i].pb(-1);
  fop (i,0,n) {
    cin >> tmp;
    pos[tmp].pb(i);
  }
  fop (i,0,N) pos[i].pb(n);
  ld ans = 1ll * N * n * n;
  fop (i,0,N) {
    fop (j,1,pos[i].size()) {
      int d = pos[i][j] - pos[i][j - 1] - 1;
      ans -= 1ll * d * d;
    }
  }
  cout << fixed << setprecision(8) << ans / (1ll * n * n) << endl;
}