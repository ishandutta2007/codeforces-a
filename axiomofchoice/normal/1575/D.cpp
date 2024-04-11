// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i, a, b) for (int i = (a), ib = (b); i < ib; i++)
#define repeat_back(i, a, b) for (int i = (b) - 1, ib = (a);i >= ib; i--)
#define fi first
#define se second
#define int ll
namespace start {
    typedef long long ll; const int inf = INT_MAX >> 1; const ll INF = INT64_MAX >> 1;
    typedef double lf; const lf pi = acos(-1); typedef pair<int, int> pii;
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        template <int fast = 0> ll read() { // will detect EOF
            if (!fast) { ll x; if (scanf("%lld", &x) != 1) exit(0); return x; }
            ll x = 0, tag = 1; int c = getchar(); for (; !isdigit(c); c = getchar()) { if (c == '-') tag = -1; if (c == EOF) exit(0); }
            for (; isdigit(c); c = getchar()) { x = x * 10 + c - 48; } if (c != EOF) ungetc(c, stdin);
            return x * tag;
        }
        lf readf() { double x; if (scanf("%lf", &x) != 1) exit(0); return x; } // will detect EOF
        template <class T> void write(T x) { if (x < 0) { x = -x, putchar('-'); } if (x >= 10) { write(x / 10); } putchar(x % 10 + 48); }
        void write(double x) { printf("%.12f", x); } void write(long double x) { printf("%.12f", double(x)); }
        template <class A, class B> void write(const pair<A, B> &x) { write(x.first); putchar(' '); write(x.second); }
        template <class T> void print(T x, int e = 1) { write(x); putchar(" \n"[e]); }
        template <class T> void print(const initializer_list<T> &a, int e = 1) { for (auto i = a.begin(), last = prev(a.end()); i != a.end(); i++) print(*i, e && i == last); }
        template <class T> void printArray(const T &a, int e = 1) { for (auto i = a.begin(), last = prev(a.end()); i != a.end(); i++) print(*i, e && i == last); }
        template <class T, int N> void mst(T (&a)[N], char c) { memset(a, c, sizeof a); }
        template <class T> T &MAX(T &a, const T &b) { if (a < b) a = b; return a; } template <class T> T &MIN(T &a, const T &b) { if (b < a) a = b; return a; }
        template <class T> vector<T> &operator<<(vector<T> &a, const T &b) { a.push_back(b); return a; }
        template <class T> T sqr(const T &x) { return x * x; }
        template <class T> void sortunique(T &a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }
        void OK(const char *msg = "Yes") { puts(msg); throw 0; } void GG(const char *msg = "No") { puts(msg); throw 0; }
        // int cansel_sync = (ios::sync_with_stdio(0), cin.tie(0), 0);
    const int N = 10010;
    const lf eps = 1e-9;
    const int mod = (1 ? 1000000007 : 998244353);
        int D(int x, int m = mod) { return x >= m ? x - m : x; }
        int mul(int a, int b, int m = mod) { return 1ll * a * b % m; }
        template <class T> int qpow(int a, T b, int m = mod) {
            int ans = 1;
            for (; b; a = mul(a, a, m), b >>= 1) if (b & 1)
                ans = mul(ans, a, m);
            return ans;
        }
} using namespace start;
const int debug = 1;
char s[10];
int f[10];
int x[10], hasx;
int n;
int calc(int a, int b) {
    int A = a + '0', B = b + '0';
    fill(x, x + 10, 1);
    hasx = 0;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '_') {
            fill(f, f + 10, 1);
            if (i == 0) f[0] = 0;
            if (i == n - 2) {
                repeat (i, 0, 10) if (i != a) f[i] = 0;
            }
            if (i == n - 1) {
                repeat (i, 0, 10) if (i != b) f[i] = 0;
            }
            // orzarr(f, 10);
            ans *= accumulate(f, f + 10, 0);
        } else if (s[i] == 'X') {
            if (i == 0) x[0] = 0;
            if (i == n - 2) {
                repeat (i, 0, 10) if (i != a) x[i] = 0;
            }
            if (i == n - 1) {
                repeat (i, 0, 10) if (i != b) x[i] = 0;
            }
            hasx = 1;
        }
    }
    // if (hasx) orzarr(x, 10);
    if (hasx) ans *= accumulate(x, x + 10, 0);
    // qwq;
    if (s[0] == '0') return 0;
    // orz("1");
    if (s[n - 2] != '_' && s[n - 2] != 'X' && s[n - 2] != A) return 0;
    // orz("1");
    if (s[n - 1] != '_' && s[n - 1] != 'X' && s[n - 1] != B) return 0;
    // orz("1");
    return ans;
}
void Solve() {
    scanf("%s", s);
    n = strlen(s);
    if (n == 1) {
        print(int(s[0] == '_' || s[0] == 'X' || s[0] == '0'));
        return;
    }
    print(calc(0, 0) + calc(2, 5) + calc(5, 0) + calc(7, 5));
}
signed main() {
    // freopen("data.txt", "r", stdin);
    int T = 1; // T = read();
    repeat (ca, 1, T + 1) {
        try { Solve(); } catch (signed) { }
    }
    return 0;
}