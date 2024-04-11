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
const int mod = 998244353, N = 1 << 19, logN = 20;

vector <int> query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    vector <int> a(r - l + 1);
    for (int &i : a)
        cin >> i, assert(i != -1);
    return a;
}

vector <int> Union (vector <int> a, int l, int r) { // [)
    vector <int> res;
    for (int i = l, j = 0; i < r; ++i) {
        while (j < a.size() && a[j] < i)
            j++;
        if (j < a.size() && a[j] == i)
            res.pb(i);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    int l = 1, r = n + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        vector <int> L = query(l, m - 1);
        vector <int> tl = Union(L, l, m);
        test(tl);
        if (int(tl.size()) & 1) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << "! " << l << endl;
}

// 3 4 1 2 5

int main () {
    // owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}