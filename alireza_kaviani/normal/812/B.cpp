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

const ll MAXN = 20 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , dp[MAXN][2][2];
string s[MAXN];

ll get1(ll ind){
    for(ll i = m + 1 ; i >= 0 ; i--){
        if(s[ind][i] == '1')    return i;
    }
    return 0;
}

ll get2(ll ind){
    for(ll i = 0 ; i <= m + 1 ; i++){
        if(s[ind][i] == '1')    return m + 1 - i;
    }
    return 0;
}

int main() {
    fast_io;

    cin >> n >> m;
    for(ll i = n ; i >= 1 ; i--)    cin >> s[i];
    while(n >= 2 && get1(n) == 0) n--;

    dp[1][0][0] = get1(1) * 2;
    dp[1][0][1] = m + 1;
    dp[1][1][0] = INF;
    dp[1][1][1] = INF;

    for(ll i = 2 ; i <= n ; i++){
        dp[i][0][0] = min(dp[i - 1][0][0] , dp[i - 1][1][0]) + 1 + get1(i) * 2;
        dp[i][0][1] = min(dp[i - 1][0][0] , dp[i - 1][1][0]) + m + 2;
        dp[i][1][0] = min(dp[i - 1][0][1] , dp[i - 1][1][1]) + m + 2;
        dp[i][1][1] = min(dp[i - 1][0][1] , dp[i - 1][1][1]) + 1 + get2(i) * 2;
    }

    cout << min({dp[n][0][0] - get1(n) , dp[n][0][1] , dp[n][1][0] , dp[n][1][1] - get2(n)}) << endl;

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