#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1 << 20, K = 250;

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> par(n, -1);
    vector <vector <int>> adj(n);
    for (int i = 1; i < n; ++i)
        cin >> par[i], --par[i], adj[par[i]].pb(i);
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    map <pii, ll> table;
    function <ll(int, int)> dfs = [&](int v, int k) {
        if (!k) return 0ll;
        if (table.count({v, k})) return table[{v, k}];
        ll ans = 1ll * a[v] * k;
        vector <ll> diff;
        int sz = adj[v].size();
        if (!sz) return table[{v, k}] = ans;
        if (k % sz == 0) {
            for (int u : adj[v]) {
                ans += dfs(u, k / sz);
            }
        } else {
            for (int u : adj[v]) {
                ll res1 = dfs(u, k / sz), res2 = dfs(u, k / sz + 1);
                diff.pb(res2 - res1), ans += res1;
            }
            sort(rall(diff));
            for (int i = 0; i < k % sz; ++i)
                ans += diff[i];
        }
        return table[{v, k}] = ans;
    };
    cout << dfs(0, k) << '\n'; 
}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}