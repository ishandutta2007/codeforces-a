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

const ll MAXN = 1e3 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<char> vec;
ll q, n, m, k, ans[MAXN][MAXN];
string s[MAXN];

int main() {
    fast_io;

    for (ll i = 0; i < 10; i++) vec.push_back(i + '0');
    for (ll i = 0; i < 26; i++) vec.push_back(i + 'A');
    for (ll i = 0; i < 26; i++) vec.push_back(i + 'a');

    cin >> q;
    while (q--) {
        cin >> n >> m >> k;
        ll cntR = 0;
        for (ll i = 0; i < n; i++) {
            cin >> s[i];
            for (ll j = 0; j < m; j++) cntR += (s[i][j] == 'R');
        }

        ll cnt = cntR / k, ind = 0;
        for (ll i = 0; i < n; i++) {
            if (i % 2 == 0) {
                for (ll j = 0; j < m; j++) {
                    ans[i][j] = ind;
                    cnt -= (s[i][j] == 'R');
                    cntR -= (s[i][j] == 'R');
                    if (cnt == 0 && ind != k - 1) {
                        ind++;
                        cnt = cntR / (k - ind);
                    }
                }
            } else {
                for (ll j = m - 1; j >= 0; j--) {
                    ans[i][j] = ind;
                    cnt -= (s[i][j] == 'R');
                    cntR -= (s[i][j] == 'R');
                    if (cnt == 0 && ind != k - 1) {
                        ind++;
                        cnt = cntR / (k - ind);
                    }
                }
            }
        }

        for (ll i = 0; i < n; i++, cout << endl) {
            for (ll j = 0; j < m; j++) cout << vec[ans[i][j]];
        }
    }

    return 0;
}
/*

*/