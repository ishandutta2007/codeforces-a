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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<ll> as(n);
        for (ll &a : as) {
            cin >> a;
        }
        sort(as.begin(), as.end());
        ll best = as[n - 1] - as[0];
        for (ll i = 2; i < n; i++) {
            best = max(best, as[i] - as[i - 1] + as[i] - as[0]);
        }
        for (ll i = n - 3; i >= 0; i--) {
            best = max(best, as[i + 1] - as[i] + as[n - 1] - as[i]);
        }
        // ll res =
        // max(as[1]-as[0]+as[n-1]-as[0],as[n-1]-as[n-2]+as[n-1]-as[0]); for(ll
        // i = 1; i < n - 1; i ++) {
        //     res =
        //     max(res,min(as[i]-as[i-1],as[i+1]-as[i])+max(as[i]-as[0],as[n-1]-as[i]));
        // }
        cout << best << "\n";
    }
    return 0;
}