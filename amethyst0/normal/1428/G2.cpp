//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <limits.h>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e6 + 10;
ll f[6];

ll calc(int x) {
    ll tot = 0;

    for (int i = 0; i < 6; i++) {
        int c = x % 10;
        x /= 10;

        if (c == 3 || c == 6 || c == 9) {
            tot += (c / 3) * f[i];
        }
    }

    return tot;
}

const ll inf = (ll)1e18;

ll dp[7][maxn];

ll solve(int x, int cnt) {
    if (x % 3 != 0) {
        return -inf;
    }

    x /= 3;

    vector <pair <ll, int> > g;
    int pos = 0;
    ll ans = 0;

    while (pos < 6) {
        g.push_back(mp(f[pos], cnt));
        sort(all(g));

        while (x % 10) {
            while (!g.empty() && g.back().second == 0) {
                g.pop_back();
            }
            if (g.empty()) {
                break;
            }

            ans += g.back().first;
            g.back().second--;
            x--;
        }

        if (x % 10) {
            return -inf;
        }

        ll a = 0;
        int b = 0;

        vector <pair <ll, int> > ng;

        for (int i = (int)g.size() - 1; i >= 0; i--) {
            int cnt = 10 - b;
            if (g[i].second < cnt) {
                b += g[i].second;
                a += g[i].first * g[i].second;
                continue;
            }

            b += cnt;
            assert(b == 10);
            a += cnt * g[i].first;
            ng.push_back(mp(a, b / 10));
            g[i].second -= cnt;
            if (g[i].second >= 10) {
                ng.push_back(mp(g[i].first * 10, g[i].second / 10));
            }

            b = g[i].second % 10;
            a = g[i].first * b;
        }

        g = ng;
        x /= 10;

        pos++;
    }

    assert(x == 0);

    return ans;
}

int main() {
    int k;
    cin >> k;

    for (int i = 0; i < 6; i++) {
        cin >> f[i];
    }

    for (int i = 0; i <= 999999; i++) {
        dp[0][i] = solve(i, 3 * k - 3);
        for (int j = 1; j <= 6; j++) {
            dp[j][i] = -inf;
        }
    }

    for (int i = 0; i < 6; i++) {
        int val = 1;

        for (int j = 0; j < i; j++) {
            val *= 10;
        }

        for (int j = 0; j <= 999999; j++) {
            if (dp[i][j] == -inf) {
                continue;
            }

            int cur = 0;

            for (int p = 0; p <= 9; p++) {
                ll sc = (p % 3 != 0 ? 0 : (p / 3) * f[i]);
                if (j + cur > 999999) {
                    break;
                }

                dp[i + 1][j + cur] = max(dp[i + 1][j + cur], dp[i][j] + sc);
                cur += val;
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;

        printf("%lld\n", dp[6][x]);
    }
}