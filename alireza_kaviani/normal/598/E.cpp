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

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 31;
const ll MAXK = 51;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll t , n , m , k , dp[MAXN][MAXN][MAXK];

int main() {
    fast_io;
    for(ll i = 0 ; i < MAXN ; i++){
        for(ll j = 0 ; j < MAXN ; j++){
            for(ll k = 0 ; k < MAXK ; k++){
                dp[i][j][k] = INF;
            }
        }
    }

    for(ll i = 1 ; i < MAXN ; i++){
        for(ll j = 1 ; j < MAXN ; j++){
            dp[i][j][0] = 0;
            if(i * j < MAXK)    dp[i][j][i * j] = 0;
            for(ll k = 1 ; k < min(i * j , MAXK) ; k++){
                for(ll l = 0 ; l <= k ; l++){
                    for(ll m = 1 ; m < i ; m++){
                        dp[i][j][k] = min(dp[i][j][k] , dp[m][j][l] + dp[i - m][j][k - l] + j * j);
                    }
                    for(ll m = 1 ; m < j ; m++){
                        dp[i][j][k] = min(dp[i][j][k] , dp[i][m][l] + dp[i][j - m][k - l] + i * i);
                    }
                }
            }
        }
    }

    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cout << dp[n][m][k] << endl;
    }

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