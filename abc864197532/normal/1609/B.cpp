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
const int mod = 1e9 + 1, N = 200002, logN = 20, K = 600, M = 1e9 + 1;

int main () {
    owo;
    int n, q;
    string s;
    cin >> n >> q >> s;
    int cnt = 0;
    auto add = [&](int i, int v) {
        if (i < 0 || i + 2 >= n)
            return;
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
            cnt += v;
    };
    for (int i = 0; i + 2 < n; ++i)
        add(i, 1);
    int p;
    char c;
    while (q--) {
        cin >> p >> c, --p;
        add(p - 2, -1), add(p - 1, -1), add(p, -1), add(p + 1, -1), add(p + 2, -1);
        s[p] = c;
        add(p - 2, 1), add(p - 1, 1), add(p, 1), add(p + 1, 1), add(p + 2, 1);
        cout << cnt << endl;
    }
}