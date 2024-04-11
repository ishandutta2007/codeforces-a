/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: AmShZ6
 * Time: 2020-05-31 19:05:01
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
typedef pair<int, int> pii;

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

ll n , ans , cost[MAXN] , A[MAXN] , B[MAXN] , sz[MAXN][3];
vector<ll> adj[MAXN];

void DFS(ll v , ll mn , ll p = -1){
    sz[v][A[v]]++;
    for(int u : adj[v]){
        if(u == p)  continue;
        DFS(u , min(mn , cost[v]) , v);
        sz[v][0] += sz[u][0];
        sz[v][1] += sz[u][1];
    }
    if(cost[v] < mn){
        ans += cost[v] * min(sz[v][0] , sz[v][1]) * 2;
        ll x = min(sz[v][0] , sz[v][1]);
        sz[v][0] -= x; sz[v][1] -= x;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> cost[i] >> A[i] >> B[i];
        if(A[i] == B[i])    A[i] = 2;
    }
    for(int i = 1 , v , u ; i < n ; i++){
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    DFS(1 , MOD);
    if(sz[1][0] + sz[1][1] != 0)    return cout << -1 << endl , 0;
    cout << ans << endl;

    return 0;
}
/*

*/