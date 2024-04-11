#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double; 
// using ld = __float128;
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

const int MAXN = 100100;
vector<int> g[MAXN];

int dfs0(int v, int t, int p = -1) {
    if (v == t) {
        return 0;
    }

    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        int d = dfs0(u, t, v);
        if (d != -1) {
            return d + 1;
        }
    }

    return -1;
}

pii dfs1(int v, int p = -1) {
    pii bst = {0, v};
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        pii cur = dfs1(u, v);
        ++cur.first;
        bst = max(bst, cur);
    }
    return bst;
}

void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    --a; --b;


    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (2 * da >= db) {
        cout << "Alice\n";
        return;
    }

    int d = dfs0(a, b);
    if (d <= da) {
        cout << "Alice\n";
        return;
    }

    int x = dfs1(0).second;
    int diam = dfs1(x).first;

    if (diam <= 2 * da) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}