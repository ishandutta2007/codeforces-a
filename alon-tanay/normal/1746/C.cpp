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
        vector<int> as(n);
        for (int &a : as) {
            cin >> a;
        }
        vector<pi> dif;
        for (int i = 1; i < n; i++) {
            dif.push_back({as[i - 1] - as[i], i});
        }
        sort(dif.begin(), dif.end());
        vector<int> res(n, 1);
        int idx = 1;
        for (pi d : dif) {
            // cout << "  " << d.f << " " << d.s << "\n";
            res[idx] = d.second + 1;
            idx++;
        }

        for (int r : res) {
            cout << r << " ";
        }
        cout << "\n";
    }
    return 0;
}