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
const int mod = 998244353, N = 200087, logN = 19, K = 111, M = 1000006, C = 500;

auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        vector <int> pre0(n + 1), pre1(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre0[i] = pre0[i - 1] + (s[i - 1] == '0');
            pre1[i] = pre1[i - 1] + (s[i - 1] == '1');
        }
        auto ask = [&](int d) {
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n) {
                    if (pre0[j + 1] - pre0[i] <= d)
                        j++;
                    else
                        break;
                }
                if (pre1[i] + pre1[n] - pre1[j] <= d)
                    return true;
            }
            return false;
        };
        int l = -1, r = n + 1;
        while (r - l > 1) {
            int m = l + r >> 1;
            if (ask(m))
                r = m;
            else
                l = m;
        }
        cout << r << '\n';
    }
}