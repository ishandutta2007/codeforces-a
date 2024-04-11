/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-07-30 19:05:01
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

ll n , A[MAXN] , B[MAXN] , sum[MAXN] , mx[MAXN];
vector<ll> adj[MAXN];

void DFS(int v){
    mx[v] = A[v];
    for(int u : adj[v]){
        DFS(u);
        mx[v] += max(0ll , mx[u]);
        sum[v] += sum[u];
    }
    sum[v] += mx[v];
}

void DFS2(int v){
    for(int u : adj[v]){
        if(mx[u] >= 0)  DFS2(u);
    }
    cout << v << sep;
    for(int u : adj[v]){
        if(mx[u] < 0)   DFS2(u);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1 ; i <= n ; i++)   cin >> A[i];
    for(int i = 1 ; i <= n ; i++){
        cin >> B[i];
        if(B[i] != -1)  adj[B[i]].push_back(i);
    }
    ll ans = 0;
    for(int i = 1 ; i <= n ; i++){
        if(B[i] == -1){
            DFS(i);
            ans += sum[i];
        }
    }
    cout << ans << endl;
    for(int i = 1 ; i <= n ; i++){
        if(B[i] == -1)  DFS2(i);
    }

    return 0;
}
/*

*/