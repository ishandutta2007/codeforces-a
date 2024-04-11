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
const int mod = 998244353, N = 2e6 + 5, logN = 20, M = 6e6;

bitset <100000001> BS;

int main () {
    owo;
    int n;
    unsigned int A, B, C, D;
    cin >> n >> A >> B >> C >> D;
    unsigned int ans = 0;
    auto get = [&](int n, int x) {
        lli now = x;
        unsigned int ans = 0;
        while (now <= n)
            ans += n / now, now *= x;
        return ans;
    };
    auto f = [&](unsigned int x) {
        return A * x * x * x + B * x * x + C * x + D;
    };
    // p = 2
    ans += get(n, 2) * f(2);
    // p = 3
    ans += get(n, 3) * f(3);
    for (int i = 4; i <= n; ++i) if (i % 6 == 1 || i % 6 == 5) {
        if (i % 6 == 1 && BS[(i / 6) * 2])
            continue;
        if (i % 6 == 5 && BS[(i / 6) * 2 + 1])
            continue;
        ans += get(n, i) * f(i);
        int j = i * 5;
        while (j <= n) {
            if (j % 6 == 1)
                BS[(j / 6) * 2] = 1;
            else
                BS[(j / 6) * 2 + 1] = 1;
            if ((i % 6 == 1) ^ (j % 6 == 1)) {
                j += i * 2;
            } else {
                j += i * 4;
            }
        }
    }
    cout << ans << endl;
}