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
const int mod = 1e9 + 7, N = 2e5 + 101, logN = 18;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <lli> a(n), pre(n + 1);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0, x; i < n; ++i)
            cin >> x, a[i] -= x;
        for (int i = 1; i <= n; ++i)
            pre[i] = pre[i - 1] + a[i - 1];
        vector <vector <pii>> adj(n + 1);
        while (m--) {
            int l, r; cin >> l >> r, --l;
            adj[l].eb(l, r), adj[r].eb(l, r);
        }
        set <int> unvis;
        for (int i = 0; i <= n; ++i)
            unvis.insert(i);
        queue <int> q;
        for (int i = 0; i <= n; ++i) if (!pre[i])
            q.push(i), unvis.erase(i);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto [l, r] : adj[v]) if (!unvis.count(l ^ r ^ v)) {
                while (true) {
                    auto it = unvis.lower_bound(l);
                    if (it == unvis.end() || *it > r)
                        break;
                    q.push(*it), unvis.erase(it);
                }
            }
        }
        cout << (unvis.empty() ? "YES\n" : "NO\n");
    }
}