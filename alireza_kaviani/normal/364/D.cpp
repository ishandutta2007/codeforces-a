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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

mt19937 rng(time(0));
ll n , ans , A[MAXN] , dp[15][MAXN] , cnt[MAXN];
vector<ll> D , P;
map<ll , ll> mark;

void solve(ll x){
    ll y = x;
    D = P = {};
    for(ll i = 1 ; i * i <= x ; i++){
        if(y % i == 0 && i != 1){
            P.push_back(i);
            while(y % i == 0)   y /= i;
        }
        if(x % i == 0){
            D.push_back(i);
            if(i * i != x)  D.push_back(x / i);
        }
    }
    Sort(D);

    for(ll i = 0 ; i < n ; i++){
        ll g = __gcd(A[i] , x) , ind = lower_bound(all(D) , g) - D.begin();
        cnt[ind]++;
    }
    for(ll i = SZ(D) - 1 ; i >= 0 ; i--){
        dp[SZ(P)][i] = cnt[i];
        for(ll j = SZ(P) - 1 ; j >= 0 ; j--){
            ll t = D[i] * P[j] , ind = lower_bound(all(D) , t) - D.begin();
            if(x / D[i] < P[j]) t = INF , ind = 0;
            dp[j][i] = dp[j + 1][i] + (D[ind] == t ? dp[j][ind] : 0);
        }
        //cout << x << sep << i << sep << D[i] << sep << dp[0][i] << sep << cnt[i] << endl;
        if(dp[0][i] >= (n + 1) / 2) ans = max(ans , D[i]);
    }
    for(ll i = 0 ; i < SZ(D) + 5 ; i++){
        for(ll j = 0 ; j < 15 ; j++)    dp[j][i] = 0;
        cnt[i] = 0;
    }
    //cout << "===========" << endl;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(ll i = 0 ; i < n ; i++) cin >> A[i];
    shuffle(A , A + n , rng);

    ll c = 0;
    for(ll i = 0 ; i < n ; i++){
        if(mark[A[i]]) continue;
        mark[A[i]] = 1;
        c++;
        solve(A[i]);
        if(c == 10)   break;
    }
    cout << ans << endl;

    return 0;
}
/*

*/