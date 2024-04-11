#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT =
#define enl "\n";
#define debug(k)                             \
    for (int _ = 0; _ < DEBUG_INDENT; _++) { \
        cout << "  ";                        \
    }                                        \
    cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template <typename T>
using pbds =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

ll res(ll n) {
    ll ans = 0;
    {
        ll l = 0, r = 1e9;
        while (l < r) {
            ll mid = (l + r + 1) / 2;
            if (mid * mid <= n) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans += l;
    }
    {
        ll l = 0, r = 1e9;
        while (l < r) {
            ll mid = (l + r + 1) / 2;
            if (mid * (mid + 1) <= n) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans += l;
    }
    {
        ll l = 0, r = 1e9;
        while (l < r) {
            ll mid = (l + r + 1) / 2;
            if (mid * (mid + 2) <= n) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans += l;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << res(r) - res(l - 1) << "\n";
    }
    return 0;
}