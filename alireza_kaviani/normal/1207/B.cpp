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

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , A[MAXN][MAXN] , B[MAXN][MAXN];
vector<pll> ans;

int main() {
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < m ; j++) cin >> A[i][j];
    }

    for(ll i = 0 ; i + 1 < n ; i++){
        for(ll j = 0 ; j + 1 < m ; j++){
            if(A[i][j] == 1 && A[i][j + 1] == 1 && A[i + 1][j] == 1 && A[i + 1][j + 1] == 1){
                for(ll k = i ; k <= i + 1 ; k++){
                    for(ll l = j ; l <= j + 1 ; l++){
                        B[k][l] = 1;
                    }
                }
                ans.push_back({i + 1 , j + 1});
            }
        }
    }

    for(ll i = 0 ; i < MAXN ; i++){
        for(ll j = 0 ; j < MAXN ; j++){
            if(A[i][j] != B[i][j])  return cout << -1 << endl , 0;
        }
    }

    cout << ans.size() << endl;
    for(pll i : ans)    cout << i.X << sep << i.Y << endl;

    return 0;
}
/*

*/