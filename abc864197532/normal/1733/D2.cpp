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
const int mod = 1e9 + 7, N = 1 << 20;

void solve() {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector <int> diff;
    {
        string s, t; cin >> s >> t;
        for (int i = 0; i < n; ++i) if (s[i] ^ t[i])
            diff.pb(i);
    }
    if (int(diff.size()) & 1) {
        cout << "-1\n";
        return;
    }
    int m = diff.size();
    x = min(x, y * 2);
    if (x >= y) {
        if (m == 2 && diff[1] - diff[0] == 1) cout << x << '\n';
        else cout << 1ll * y * m / 2 << '\n';
    } else {
        vv <ll> dp(m + 1, 2, 1ll << 60);
        dp[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] - 1ll * diff[i] * x * 2);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 1ll * diff[i] * x * 2);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + y);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + y);
        }
        cout << dp[m][0] / 2 << '\n';
    }
}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}