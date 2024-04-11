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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;
string s , ans , t;

int main() {
    fast_io;

    cin >> s;
    n = s.size();

    for(ll i = 0 ; i + 1 < n / 2 ; i += 2){
        ll cnt[3] = {0 , 0 , 0};
        string x = s.substr(i , 2) + s.substr(n - i - 2 , 2);
        for(ll j = 0 ; j < x.size() ; j++)  cnt[x[j] - 97]++;
        for(ll j = 0 ; j < 3 ; j++){
            if(cnt[j] >= 2){
                ans += string(1 , j + 97);
                break;
            }
        }
    }
    t = ans;
    reverse(all(t));
    cout << ans + string(ans.size() * 2 < n / 2 , s[n / 2]) + t << endl;

    return 0;
}
/*

*/