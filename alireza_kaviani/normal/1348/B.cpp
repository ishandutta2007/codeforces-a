/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-05-01 19:05:10
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

const ll MAXN = 100 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll q , k , n , A[MAXN] , mark[MAXN];
vector<ll> vec;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> k;
        vec = {};
        fill(mark , mark + MAXN , 0);
        for(ll i = 1 ; i <= n ; i++){
            cin >> A[i];
            if(!mark[A[i]]) vec.push_back(A[i]);
            mark[A[i]] = 1;
        }
        if(SZ(vec) > k){
            cout << -1 << endl; continue;
        }
        for(ll i = 1 ; i <= n ; i++)    if(!mark[i] && SZ(vec) < k) vec.push_back(i);
        vector<ll> ans;
        for(ll i = 0 ; i < 100 ; i++){
            for(ll j : vec){
                ans.push_back(j);
                if(i == 99 && j == A[n]) break;
            }
        }
        cout << SZ(ans) << endl;
        for(ll j : ans) cout << j << sep;
        cout << endl;
    }

    return 0;
}
/*

*/