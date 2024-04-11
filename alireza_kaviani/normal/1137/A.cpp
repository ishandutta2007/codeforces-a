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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

set_random;

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , a[MAXN][MAXN];
Tree<ll> x[MAXN] , y[MAXN];

int main() {
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < m ; j++){
            cin >> a[i][j];
            x[i].insert(a[i][j]);
            y[j].insert(a[i][j]);
        }
    }

    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < m ; j++){
            ll x1 = x[i].order_of_key(a[i][j] + 1) , x2 = x[i].size() - x1;
            ll y1 = y[j].order_of_key(a[i][j] + 1) , y2 = y[j].size() - y1;
            cout << max(x1 , y1) + max(x2 , y2) << sep;
        }
        cout << endl;
    }

    return 0;
}
/*

*/