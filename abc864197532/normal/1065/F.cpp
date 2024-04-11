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
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
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
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 1000001, logC = 30;

vector <int> adj[N];
int dp[N][2], mn_leaf[N], dep[N], k;

void dfs(int v) {
    bool ch = true;
    mn_leaf[v] = 1 << 30;
    int oth_mx = 0;
    for (int u : adj[v]) {
        dep[u] = dep[v] + 1;
        dfs(u);
        ch = false;
        mn_leaf[v] = min(mn_leaf[v], mn_leaf[u]);
        if (mn_leaf[u] - k <= dep[v])
            dp[v][0] += dp[u][0], dp[v][1] = max(dp[v][1], dp[u][1]);
        else
            dp[v][1] = max(dp[v][1], dp[u][0] + dp[u][1]);
    }
    if (ch)
        mn_leaf[v] = dep[v], dp[v][0] = 1;
}

int main () {
    owo;
    int n;
    cin >> n >> k;
    for (int i = 1, p; i < n; ++i) {
        cin >> p, --p;
        adj[p].pb(i);
    }
    dfs(0);
    cout << dp[0][0] + dp[0][1] << endl;
}