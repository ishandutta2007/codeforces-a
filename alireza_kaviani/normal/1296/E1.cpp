/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
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
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, ans[MAXN];
string s;
vector<ll> ind[26];
set<pll> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (ll i = n - 1; i >= 0; i--) ind[s[i] - 97].push_back(i);

    for (ll i = 25; i >= 0; i--) {
        for (ll j : ind[i]) {
            auto it = st.lower_bound({j, -INF});
            if (it == st.end()) {
                ans[j] = SZ(st) + 1;
                st.insert({j, SZ(st) + 1});
            } else {
                ans[j] = (*it).Y;
                st.erase(it);
                st.insert({j, ans[j]});
            }
        }
    }
    if (*max_element(ans, ans + MAXN) > 2) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    for (ll i = 0; i < n; i++) cout << ans[i] - 1;

    return 0;
}
/*

*/