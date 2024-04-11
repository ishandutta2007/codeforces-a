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
const int mod = 1e9 + 7, N = 1002, logN = 19, K = 111, M = 1000006, INF = 1e9 + 87;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector <bool> ok(26, false);
        int m; cin >> m;
        char c;
        for (int i = 0; i < m; ++i) {
            cin >> c, ok[c - 'a'] = true;
        }
        vector <bool> now(n, false);
        for (int i = 0; i < n; ++i)
            now[i] = ok[s[i] - 'a'];
        {
            vector <bool> nxt;
            for (int i = 0; i < n; ++i) if (i == n - 1 || !now[i + 1])
                nxt.pb(now[i]);
            if (now == nxt) {
                cout << 0 << endl;
                continue;
            }
            now = nxt;
        }
        vector <int> pos = {0};
        for (int i = 1; i < now.size(); ++i) if (now[i])
            pos.pb(i);
        int ans = 0;
        for (int i = 1; i < pos.size(); ++i) 
            ans = max(ans, pos[i] - pos[i - 1]);
        cout << ans + 1 << endl;
    }
}