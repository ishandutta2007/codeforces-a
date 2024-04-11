/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-03-27 17:37:48
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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , q , par[LOG][MAXN] , H[MAXN] , downD[MAXN] , totD[MAXN] , sz[MAXN];
vector<ll> adj[MAXN];

void DFS(ll v , ll p = 0){
    par[0][v] = p;
    sz[v] = 1;
    H[v] = H[p] + 1;
    for(ll u : adj[v]){
        if(u == p)  continue;
        DFS(u , v);
        downD[v] += downD[u];
        sz[v] += sz[u];
    }
    downD[v] += sz[v] - 1;
}

void DFS2(ll v , ll p , ll val){
    totD[v] = val;
    for(ll u : adj[v]){
        if(u == p)  continue;
        DFS2(u , v , val + n - 2 * sz[u]);
    }
}

ll getPar(ll v , ll h){
    for(ll i = 0 ; i < LOG ; i++)   if(h & (1 << i))    v = par[i][v];
    return v;
}

ll LCA(ll v , ll u){
    if(H[v] > H[u]) swap(v , u);
    u = getPar(u , H[u] - H[v]);
    if(u == v)  return v;
    for(ll i = LOG - 1 ; i >= 0 ; i--)  if(par[i][v] != par[i][u]){
        v = par[i][v];
        u = par[i][u];
    }
    return par[0][v];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for(ll i = 1 ; i < n ; i++){
        ll v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    DFS(1);
    DFS2(1 , 0 , downD[1]);

    for(ll i = 1 ; i < LOG ; i++){
        for(ll j = 0 ; j <= n ; j++){
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    while(q--){
        ll v , u;
        cin >> v >> u;
        if(H[v] > H[u]) swap(v , u);
        ll lca = LCA(v , u);
        //printf("%lld\n" , lca);
        if(lca == v){
            ll x = getPar(u , H[u] - H[v] - 1);
            ll S = (totD[v] - downD[x] - sz[x]) * sz[u] + downD[u] * (n - sz[x]) + (H[u] - H[v]) * sz[u] * (n - sz[x]);
            //cout << S << sep << x << sep << sz[v] << sep << sz[u] << sep << sz[x] << sep << totD[v] << sep << downD[x] << sep << downD[u] << endl;
            //printf("%lld %lld\n" , H[v] , H[u]);
            //printf("%lld %lld\n" , S , x);
            printf("%.10f\n" , double(S) / double(sz[u] * (n - sz[x])) + 1);
        }
        else{
            ll S = downD[v] * sz[u] + downD[u] * sz[v] + (H[v] + H[u] - 2 * H[lca]) * sz[v] * sz[u];
            //printf("%lld\n" , S);
            printf("%.10f\n" , double(S) / double(sz[v] * sz[u]) + 1);
        }   
    }

    return 0;
}
/*

*/