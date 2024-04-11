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
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    if (a.empty())
        return o << "{}";
    bool is = false;
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
const int mod = 1e9 + 7, N = 1100005, logN = 18;

int main () {
    // owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto ask = [&](int i, int j, int k) {
            cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
            cin >> i;
            assert(i != -1);
            return i;
        };
        vector <int> id(n / 3);
        int a = -1, b = -1;
        for (int i = 0; i < n; i += 3) {
            id[i / 3] = ask(i, i + 1, i + 2);
            if (!id[i / 3])
                a = i / 3;
            else
                b = i / 3;
        }
        int zero = -1, one = -1;
        if (ask(a * 3, a * 3 + 1, b * 3) || ask(a * 3, a * 3 + 1, b * 3 + 1)) {
            zero = a * 3 + 2;
        } else {
            zero = a * 3;
        }
        if (ask(zero, b * 3, b * 3 + 1)) {
            one = b * 3;
        } else {
            one = b * 3 + 2;
        }
        vector <int> ans(n);
        for (int i = 0; i < n; i += 3) {
            if (id[i / 3]) {
                if (ask(zero, i, i + 1)) {
                    ans[i] = ans[i + 1] = 1;
                    ans[i + 2] = ask(zero, one, i + 2);
                } else {
                    ans[i + 2] = 1;
                    if (ask(zero, one, i))
                        ans[i] = 1;
                    else
                        ans[i + 1] = 1;
                }
            } else {
                if (!ask(one, i, i + 1)) {
                    ans[i] = ans[i + 1] = 0;
                    ans[i + 2] = ask(zero, one, i + 2);
                } else {
                    if (ask(zero, one, i))
                        ans[i] = 1;
                    else
                        ans[i + 1] = 1;
                }
            }
        }
        vector <int> v;
        for (int i = 0; i < n; ++i) if (!ans[i])
            v.pb(i + 1);
        cout << "! " << v.size();
        for (int i : v)
            cout << ' ' << i;
        cout << endl;
    }
}
// 9
// 001011