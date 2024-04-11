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
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5e5 + 10;
const ll LOG = 30;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

ll n , k , m , ans = 1 , l[MAXN] , r[MAXN] , x[MAXN] , dp[MAXN][2] , ps[MAXN] , L[MAXN] , cnt[MAXN];
vector<pll> vec , vec2;

ll solve(vector<pll> &v , vector<pll> &v2){
    fill(L , L + MAXN , 0);
    fill(cnt , cnt + MAXN , 0);
    for(pll i : v)  L[i.Y] = max(L[i.Y] , i.X);
    for(pll i : v2) cnt[i.X]++ , cnt[i.Y + 1]--;
    partial_sum(cnt , cnt + MAXN , cnt);
    dp[0][0] = 1; ll mx = 0;
    for(ll i = 1 ; i <= n ; i++){
        mx = max(mx , L[i]);
        if(L[i] == 0){
            dp[i][0] = dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        }
        else{
            dp[i][0] = (ps[i - 1] - ps[mx - 1] + MOD) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        }
        if(cnt[i])  dp[i][1] = 0;
        ps[i] = (ps[i - 1] + dp[i][1]) % MOD;
    }
    return (dp[n][0] + dp[n][1]) % MOD;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> k >> m;
    for(ll i = 0 ; i < m ; i++){
        cin >> l[i] >> r[i] >> x[i];
    }
    for(ll i = 0 ; i < k ; i++){
        for(ll j = 0 ; j < m ; j++){
            if(x[j] & (1 << i)) vec2.push_back({l[j] , r[j]});
            else    vec.push_back({l[j] , r[j]});
        }
        ans = ans * solve(vec , vec2) % MOD;
        vec = vec2 = {};
    }
    cout << ans << endl;

    return 0;
}
/*

*/