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
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

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
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 1e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m ,  k , ans = -INF , c[50][50] , dp[MAXN][MAXN][50];
string s;

int main() {
    fast_io;
    memset(dp , -63 , sizeof(dp));

    cin >> s >> k >> m;
    n = s.size();

    for(ll i = 0 ; i < m ; i++){
        char a , b;
        cin >> a >> b;
        cin >> c[a - 97][b - 97];
    }

    s = "." + s;
    for(ll i = 0 ; i < 26 ; i++)    dp[1][1][i] = 0;
    dp[1][0][s[1] - 97] = 0;

    for(ll i = 2 ; i <= n ; i++){
        for(ll j = 0 ; j <= k ; j++){
            for(ll l = 0 ; l < 26 ; l++){
                for(ll o = 0 ; o < 26 ; o++){
                    dp[i][j + (l != s[i] - 97)][l] = max(dp[i][j + (l != s[i] - 97)][l] , dp[i - 1][j][o] + c[o][l]);
                }
            }
        }
    }

    for(ll i = 0 ; i <= k ; i++) {
        for (ll j = 0; j < 26; j++) {
            ans = max(ans, dp[n][i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/