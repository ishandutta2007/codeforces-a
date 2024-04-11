#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())
#define sz(v) ((int)(v).size())

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

#define ivec1d(x, n, v) vec1d(x)(n, v)
#define ivec2d(x, n, m, v) vec2d(x)(n, ivec1d(x, m, v))
#define ivec3d(x, n, m, k, v) vec3d(x)(n, ivec2d(x, m, k, v))
#define ivec4d(x, n, m, k, l, v) vec4d(x)(n, ivec3d(x, m, k, l, v))

#ifdef LOCAL
#include "pretty_print.h"
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define nl "\n"

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    int n, m;
    while (cin >> n >> m) {
    // for (int n = 5; n <= 10; ++n) {
    //     int m = n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            // A[i] = rand() % 1000000000;
        }

        vector<int> a;
        ll ans;
        size_t k = n / m;
        ll answer;
        for (int cnt = 0; cnt < 1; ++cnt) {
            a = A;
            ans = 0;
            vector<stack<int>> c(m);
            for (int i = 0; i < n; ++i) {
                c[a[i] % m].push(i);
            }

            // for (int i = 0; i < n; ++i) {
            //     cerr << c[i].size() << nl;
            // }
            // cerr << endl;
            ans = 0;
            // int st = rand() % m;
            // dbg(st);
            int st = 0;
            for (int iter = 0, i = st, j = st; iter < m; iter += 1, i = (i + 1) % m) {
                while (c[i].size() > k) {
                    while (c[j].size() >= k) {
                        j = (j + 1) % m;
                    }
                    ll d = (j - i + m) % m;
                    // dbg(i, j, d);
                    ll x = c[i].top();
                    c[i].pop();
                    a[x] += d;
                    c[j].push(x);
                    ans += d;
                }
                if (i == j) {
                    j = (j + 1) % m;
                }
            }
            if (cnt == 0) {
                answer = ans;
            } else {
                dbg(A);
                assert(answer == ans);
            }
        }
        // cerr << nl;

        cout << ans << nl;
        for (int i = 0; i < n; ++i) {
            i && cout << " ";
            cout << a[i];
        }
        cout << nl;
    }



#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}