/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author /dev/null
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k, ans, ind = 1, x[MAXN], D[MAXN], Q[MAXN], L[MAXN], R[MAXN];
map<int, Tree<pii>> Rtr, Xtr;
set<pii> st;

void compress() {
    vector<ll> vec;
    for (ll i = 1; i <= n; i++) {
        vec.push_back(L[i]);
        vec.push_back(x[i]);
        vec.push_back(R[i]);
    }
    Sort(vec);
    vec.resize(unique(all(vec)) - vec.begin());

    for (ll i = 1; i <= n; i++) {
        L[i] = lower_bound(all(vec), L[i]) - vec.begin();
        x[i] = lower_bound(all(vec), x[i]) - vec.begin();
        R[i] = lower_bound(all(vec), R[i]) - vec.begin();
    }
}

void SORT() {
    vector<pair<pll, pll>> vec;
    for (ll i = 1; i <= n; i++) {
        vec.push_back({{L[i], R[i]},
                       {x[i], Q[i]}});
    }
    Sort(vec);
    for (ll i = 1; i <= n; i++) {
        L[i] = vec[i - 1].X.X;
        R[i] = vec[i - 1].X.Y;
        x[i] = vec[i - 1].Y.X;
        Q[i] = vec[i - 1].Y.Y;
    }
}

int main() {
    fast_io;

    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> x[i] >> D[i] >> Q[i];
        L[i] = x[i] - D[i];
        R[i] = x[i] + D[i];
    }

    compress();
    SORT();

    for (ll i = 1; i <= n; i++) {
        while (st.size() > 0 && (*st.begin()).X < L[i]) {
            ll ind = (*st.begin()).Y;
            Rtr[Q[ind]].erase({R[ind], ind});
            Xtr[Q[ind]].erase({x[ind], ind});
            st.erase(st.begin());
        }
        for (ll j = Q[i] - k; j <= Q[i] + k; j++) {
            if (Rtr.find(j) == Rtr.end()) continue;
            ans += Xtr[j].order_of_key({R[i], INF}) - Rtr[j].order_of_key({x[i], -INF});
        }
        Rtr[Q[i]].insert({R[i], i});
        Xtr[Q[i]].insert({x[i], i});
        st.insert({x[i], i});
    }
    cout << ans << endl;

    return 0;
}
/*

*/