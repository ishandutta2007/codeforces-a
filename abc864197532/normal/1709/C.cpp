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
const int mod = 998244353, N = 200005, logN = 18, G = 3;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        int cnt0 = n / 2, cnt1 = n / 2;
        for (char c : s) {
            if (c == '(')
                cnt0--;
            if (c == ')')
                cnt1--;
        }
        if (!cnt0 || !cnt1) {
            cout << "YES\n";
            continue;
        }
        vector <int> q;
        for (int i = 0; i < n; ++i) if (s[i] == '?')
            q.pb(i);
        string a = s;
        for (int i = 0; i < cnt0; ++i)
            a[q[i]] = '(';
        for (int i = cnt0; i < cnt0 + cnt1; ++i)
            a[q[i]] = ')';
        swap(a[q[cnt0 - 1]], a[q[cnt0]]);
        auto chk = [&](string s) {
            int now = 0, mn = 0;
            for (char c : s) {
                if (c == '(')
                    now++;
                else
                    now--;
                mn = min(mn, now);
            }
            return mn == 0;
        };
        if (chk(a))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}