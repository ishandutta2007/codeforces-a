/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-05-05 12:30:57
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

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
const ll MOD = 1111211111; // 998244353; // 1e9 + 9;
const ll base = 1e6 + 81;

ll n , h1 , h2 , pw[MAXN];
string s , t;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    pw[0] = 1;
    for(int i = 1 ; i < MAXN ; i++) pw[i] = pw[i - 1] * base % MOD;

    cin >> n >> s >> t;
    for(int i = 0 ; i < n ; i++){
        if(t[i] == 'N') t[i] = 'S';
        else if(t[i] == 'S')    t[i] = 'N';
        else if(t[i] == 'W')    t[i] = 'E';
        else if(t[i] == 'E')    t[i] = 'W';
    }

    reverse(all(s)) ; reverse(all(t));
    for(int i = 0 ; i < n ; i++){
        ll x = s[i] - 64 , y = t[i] - 64;
        h1 = (h1 * base + x) % MOD;
        h2 = (h2 + pw[i] * y) % MOD;
        if(h1 == h2)    return cout << "NO" << endl , 0;
    }
    cout << "YES" << endl;

    return 0;
}
/*

*/