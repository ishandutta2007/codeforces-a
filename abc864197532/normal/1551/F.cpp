/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 105, logN = 20, K = 1000;

int C[N][N];

int main () {
    owo;
    for (int i = 1; i < N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            if (C[i][j] >= mod) C[i][j] -= mod;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <vector <int>> adj(n);
        for (int i = 0, u, v; i < n - 1; ++i) {
            cin >> u >> v, --u, --v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        if (k == 2) {
            cout << n * (n - 1) / 2 << endl;
            continue;
        }
        vv <int> dp(n, n, 0);
        function<void(int, int)> dfs = [&](int v, int pa) {
            dp[v][0]++;
            for (int u : adj[v]) if (u != pa) {
                dfs(u, v);
                for (int j = 0; j + 1 < n; ++j) dp[v][j + 1] += dp[u][j];
            }
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            dp = vv <int>(n, n, 0);
            dfs(i, -1);
            for (int d = 0; d < n; ++d) {
                vector <int> dp2(k + 1, 0);
                dp2[0] = 1;
                for (int j : adj[i]) {
                    for (int t = k - 1; ~t; --t) {
                        dp2[t + 1] += 1ll * dp2[t] * dp[j][d] % mod;
                        if (dp2[t + 1] >= mod) dp2[t + 1] -= mod;
                    }
                }
                ans += dp2[k];
                if (ans >= mod) ans -= mod;
            }
        }
        cout << ans << endl;
    }
}