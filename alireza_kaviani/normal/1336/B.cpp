/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-04-15 19:05:03
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

ll q , n , m , k , ans;
vector<ll> A , B , C;

ll solve(vector<ll> A , vector<ll> B , vector<ll> C){
    ll res = INF;
    for(ll i : A){
        ll x = lower_bound(all(B) , i) - B.begin() , y = upper_bound(all(C) , i) - C.begin() - 1;
        //cout << i << sep << x << sep << y << endl;
        if(x < 0 || x >= SZ(B)) continue;
        if(y < 0 || y >= SZ(C)) continue;
        ll v1 = i - B[x] , v2 = i - C[y] , v3 = B[x] - C[y];
      //  cout << v1 * v1 + v2 * v2 + v3 * v3 << endl;
        res = min(res , v1 * v1 + v2 * v2 + v3 * v3);
    }
    //cout << "=======" << endl;
    return res;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> m >> k;
        ll x;
        ans = INF; A = {} ; B = {} ; C = {};
        for(ll i = 0 ; i < n ; i++) cin >> x , A.push_back(x);
        for(ll i = 0 ; i < m ; i++) cin >> x , B.push_back(x);
        for(ll i = 0 ; i < k ; i++) cin >> x , C.push_back(x);
        Sort(A) ; Sort(B) ; Sort(C);
        ans = min(ans , solve(A , B , C));
        ans = min(ans , solve(A , C , B));
        ans = min(ans , solve(B , A , C));
        ans = min(ans , solve(B , C , A));
        ans = min(ans , solve(C , A , B));
        ans = min(ans , solve(C , B , A));
        cout << ans << endl;
    }

    return 0;
}
/*

*/