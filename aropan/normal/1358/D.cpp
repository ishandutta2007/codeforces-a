#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#define idbg(x) #x " = " << x
#include "pretty_print.h"
#else
#define dbg(x)
#define idbg(x) ""
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    ll x;
    while (cin >> n >> x) {
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        reverse(all(d));
        ll t = 0;
        ll res = 0;
        ll ans = 0;

        auto get_sum = [](ll l, ll r) -> ll {
            return (l + r) * (abs(r - l) + 1) / 2;
        };

        for (int l = 0, r = 0; l < n; ++l) {
            while (t + d[r] < x) {
                t += d[r];
                res += get_sum(1, d[r]);
                r = (r + 1) % n;
            }
            chmax(ans, res + get_sum(d[r], d[r] - (x - t) + 1));
            t -= d[l];
            res -= get_sum(1, d[l]);
        }
        cout << ans << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}