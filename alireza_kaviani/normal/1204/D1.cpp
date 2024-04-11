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

const ll MAXN = 2e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , LIS[MAXN][MAXN][2][2];
string s;

int main() {
    fast_io;

    cin >> s;
    n = s.size();

    for(ll i = 0 ; i < n ; i++) LIS[i][i][0][1] = 1 , LIS[i][i][s[i] - 48][s[i] - 48] = 1;

    for(ll l = n - 1 ; l >= 0 ; l--){
        for(ll r = l + 1 ; r < n ; r++){
            for(ll i = 0 ; i < 2 ; i++){
                for(ll j = 0 ; j < 2 ; j++){
                    LIS[l][r][i][j] = LIS[l][r - 1][i][j];
                }
            }

            if(s[r] == '1'){
                LIS[l][r][0][1] = max(LIS[l][r][0][1] , LIS[l][r - 1][0][1] + 1);
                LIS[l][r][1][1] = max(LIS[l][r][1][1] , LIS[l][r - 1][1][1] + 1);
            }
            else{
                LIS[l][r][0][1] = max(LIS[l][r][0][1] , LIS[l][r - 1][0][0] + 1);
                LIS[l][r][0][0] = max(LIS[l][r][0][0] , LIS[l][r - 1][0][0] + 1);
            }
        }
    }

    for(ll i = 0 ; i < n ; i++){
        if(s[i] == '0') continue;
        ll ok = 1;
        for(ll j = 0 ; j < i ; j++){
            if(LIS[j][i - 1][0][0] + 1 > LIS[j][i][0][1])  ok = 0;
        }
        for(ll j = i + 1 ; j < n ; j++){
            if(LIS[i + 1][j][1][1] + 1 > LIS[i][j][0][1] || LIS[i + 1][j][0][1] + 1 > LIS[i][j][0][1])  ok = 0;
        }
        if(ok == 0) continue;
        for(ll j = 0 ; j <= i ; j++){
            LIS[j][i][0][0]++;
        }
        for(ll j = i + 1 ; j < n ; j++) LIS[i][j][0][0]++;
        s[i] = '0';
    }
    cout << s << endl;

    return 0;
}
/*

*/