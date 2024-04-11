#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;  

    int tests = 1;
    cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 100100;

vector<int> g[MAXN];
int a[MAXN];

void dfs(int v, int sign = 1, int p = -1) {
    a[v] = sz(g[v]) * sign;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, -sign, v);
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);


    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
        g[i].clear();
    }
    cout << "\n";
}