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
const int mod = 998244353, N = 101, logN = 18, B = 1 << 8, M = 1 << 21;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        string a, b;
        for (char c : s) if (c != 'b')
            a.pb(c);
        for (char c : t) if (c != 'b')
            b.pb(c);
        if (a == b) {
            int mn = 0;
            {
                vector <int> pre(n, 0);
                for (int i = 0; i < n; ++i) if (s[i] == 'a')
                    pre[i]++;
                for (int i = 0; i < n; ++i) if (t[i] == 'a')
                    pre[i]--;
                int now = 0;
                for (int i = 0; i < n; ++i)
                    now += pre[i], mn = min(mn, now);
            }
            {
                vector <int> pre(n, 0);
                for (int i = 0; i < n; ++i) if (s[i] == 'c')
                    pre[i]--;
                for (int i = 0; i < n; ++i) if (t[i] == 'c')
                    pre[i]++;
                int now = 0;
                for (int i = 0; i < n; ++i)
                    now += pre[i], mn = min(mn, now);
            }
            cout << (mn < 0 ? "NO\n" : "YES\n");
        } else {
            cout << "NO\n";
        }
    }
}