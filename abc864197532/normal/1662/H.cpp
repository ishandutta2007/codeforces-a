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
const int mod = 998244353, N = 1600087, logN = 19, K = 111, M = 1000006, C = 500;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int h, w;
        cin >> h >> w;
        vector <int> ans;
        for (int i = 1; i * i <= h; ++i) if (h % i == 0) {
            if ((w - 2) % i == 0)
                ans.pb(i);
            if ((w - 2) % (h / i) == 0)
                ans.pb(h / i);
        }
        for (int i = 1; i * i <= h - 1; ++i) if ((h - 1) % i == 0) {
            if ((w - 1) % i == 0)
                ans.pb(i);
            if ((w - 1) % ((h - 1) / i) == 0)
                ans.pb((h - 1) / i);
        }
        for (int i = 1; i * i <= h - 2; ++i) if ((h - 2) % i == 0) {
            if (w % i == 0)
                ans.pb(i);
            if (w % ((h - 2) / i) == 0)
                ans.pb((h - 2) / i);
        }
        if (h & 1 && w & 1 ^ 1)
            ans.pb(2);
        if (w & 1 && h % 1 ^ 1)
            ans.pb(2);
        sort(all(ans));
        ans.resize(unique(all(ans)) - ans.begin());
        cout << ans.size();
        for (int i : ans)
            cout << ' ' << i;
        cout << '\n';
    }
}