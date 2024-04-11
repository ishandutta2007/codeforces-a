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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , cnt[4] , mnx = INF , mny = INF , mxx = -INF , mxy = -INF;
pll p[MAXN];

ll in(pll p , ll x1 , ll x2 , ll y1 , ll y2){
    ll ans = 0;
    if(p.X == x1 || p.X == x2){
        if(p.Y >= y1 && p.Y <= y2){
            cnt[(p.X == x2)]++;
            ans = 1;
        }
    }
    if(p.Y == y1 || p.Y == y2){
        if(p.X >= x1 && p.X <= x2){
            cnt[2 + (p.Y == y2)]++;
            ans = 1;
        }
    }
    return ans;
}

int main() {
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < 4 * n + 1 ; i++){
        cin >> p[i].X >> p[i].Y;
    }

    for(ll i = 0 ; i < 4 * n + 1 ; i++){
        mnx = INF , mny = INF , mxx = -INF , mxy = -INF;
        cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
        for(ll j = 0 ; j < 4 * n + 1 ; j++){
            if(i == j) continue;
            mnx = min(mnx , p[j].X);
            mny = min(mny , p[j].Y);
            mxx = max(mxx , p[j].X);
            mxy = max(mxy , p[j].Y);
        }

        if(in(p[i] , mnx , mxx , mny , mxy)) continue;
        ll ok = 1;
        for(ll j = 0 ; j < 4 * n + 1 ; j++){
            if(in(p[j] , mnx , mxx , mny , mxy) == 0 && i != j)   ok = 0;
        }
        if(ok && *min_element(cnt , cnt + 4) >= n){
            cout << p[i].X << sep << p[i].Y << endl;
        }
    }

    return 0;
}
/*

*/