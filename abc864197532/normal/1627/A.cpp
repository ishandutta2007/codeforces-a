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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 1000087, logN = 20, K = 48763;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y, --x, --y;
        vector <string> s(n);
        bool fail = true;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            fail &= count(all(s[i]), 'B') == 0;
        }
        if (fail) {
            cout << -1 << endl;
        } else {
            if (s[x][y] == 'B')
                cout << 0 << endl;
            else {
                bool is = false;
                for (int i = 0; i < n; ++i)
                    is |= s[i][y] == 'B';
                for (int i = 0; i < m; ++i)
                    is |= s[x][i] == 'B';
                cout << (is ? 1 : 2) << endl;
            }
        }
    }
}