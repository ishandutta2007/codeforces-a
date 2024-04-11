/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-04-28 19:56:26
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
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , ans = 1 , A[MAXN] , x[MAXN];
vector<ll> vec , primes = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67};

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(ll i = 0 ; i < n ; i++){
        cin >> x[i];
        for(ll j = 0 ; j < SZ(primes) ; j++){
            ll C = 0;
            while(x[i] % primes[j] == 0)    C++ , x[i] /= primes[j];
            if(C & 1)   A[i] ^= (1 << j);
        }
        for(ll j : vec){
            ll x = (1 << 31 - __builtin_clz(j));
            if(A[i] & x)    A[i] ^= j;
        }
        if(A[i] != 0)   vec.push_back(A[i]);
        else    ans = ans * 2 % MOD;
    }
    cout << ans - 1 << endl;

    return 0;
}
/*

*/