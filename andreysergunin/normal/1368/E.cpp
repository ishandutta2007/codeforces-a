#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;
 
    int tests = 1;
    cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

const int MAXN = 200200;

vector<int> g[MAXN];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }

    for (int i = 0; i < n; ++i) {
        sort(all(g[i]));
    }

    vector<int> used(n);
    vector<int> res;

    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            for (int u : g[i]) {
                used[u] = max(used[u], 1);
            }
        } else if (used[i] == 1) {
            for (int u : g[i]) {
                used[u] = max(used[u], 2);
            }
        } else {
            res.push_back(i);
        }
    }

    cout << sz(res) << "\n";
    for (int x : res) {
        cout << x + 1 << " ";
    }
    cout << "\n";

    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }

}