/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-06-13 19:35:04
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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , k , H[MAXN] , par[LOG][MAXN];
vector<ll> adj[MAXN] , vec[2];
vector<pll> E;

void BFS(ll v){
    queue<ll> q;
    fill(H , H + MAXN , MOD);
    H[v] = 0; q.push(v);
    while(!q.empty()){
        v = q.front(); q.pop();
        vec[H[v] % 2].push_back(v);
        for(int u : adj[v]){
            if(H[u] == MOD){
                H[u] = H[v] + 1;
                par[0][u] = v;
                q.push(u);
            }
        }
    }
}

int getPar(int v , int h){
    for(int i = 0 ; i < LOG ; i++)  if(h & (1 << i))    v = par[i][v];
    return v;
}

int LCA(int v , int u){
    u = getPar(u , H[u] - H[v]);
    if(u == v)  return u;
    for(int i = LOG - 1 ; i >= 0 ; i--) if(par[i][v] != par[i][u])  v = par[i][v] , u = par[i][u];
    return par[0][v];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 0 ; i < m ; i++){
        int v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
        E.push_back({v , u});
    }
    BFS(1);
    for(int i = 1 ; i < LOG ; i++)  for(int j = 0 ; j <= n ; j++)   par[i][j] = par[i - 1][par[i - 1][j]];
    ll ansV = 0 , ansU = 0 , mnlen = MOD;
    for(pll i : E){
        ll v = i.X , u = i.Y;
        if(H[v] > H[u]) swap(v , u);
        if(par[0][u] == v)  continue;
        ll lca = LCA(v , u) , len = H[v] + H[u] - 2 * H[lca] + 1;
        if(len < mnlen) mnlen = len , ansV = v , ansU = u;
    }
    if(mnlen == MOD){
        if(SZ(vec[0]) < SZ(vec[1])) vec[0] = vec[1];
        cout << 1 << endl;
        for(int i = 0 ; i < (k + 1) / 2 ; i++)  cout << vec[0][i] << sep;
        cout << endl;
        return 0;
    }
    //for(int i = 0 ; i <= n ; i++)   cout << i << sep << H[i] << sep << par[0][i] << endl;
    ll lca = LCA(ansV , ansU);
    vector<ll> C1 , C2;
    while(ansV != lca){
        C1.push_back(ansV);
        ansV = par[0][ansV];
    }
    while(ansU != lca){
        C2.push_back(ansU);
        ansU = par[0][ansU];
    }
    //cout << lca << endl;
    reverse(all(C2)); C1.push_back(lca);
    for(ll i : C2)  C1.push_back(i);
    if(mnlen <= k){
        cout << 2 << endl;
        cout << SZ(C1) << endl;
        for(ll i : C1)  cout << i << sep;
        return 0;
    }
    cout << 1 << endl;
    for(int i = 0 ; i < (k + 1) / 2 ; i++)  cout << C1[i * 2] << sep;

    return 0;
}
/*

*/