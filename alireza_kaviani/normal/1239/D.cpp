/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-04-04 15:24:10
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

ll q , n , m , cnt , mark[MAXN] , comp[MAXN] , C[MAXN];
vector<ll> ts , adj[MAXN] , radj[MAXN];

void DFS1(ll v){
    mark[v] = 1;
    for(ll u : adj[v])  if(!mark[u])    DFS1(u);
    ts.push_back(v);
}

void DFS2(ll v){
    comp[v] = cnt;
    C[cnt]++;
    mark[v] = 2;
    for(ll u : radj[v]) if(mark[u] == 1)    DFS2(u);
}

void SCC(){
    ts = {} , cnt = 0;
    for(ll i = 1 ; i <= n ; i++)    if(!mark[i])    DFS1(i);
    reverse(all(ts));
    for(ll i : ts){
        if(mark[i] == 1){
            cnt++;
            C[cnt] = 0;
            DFS2(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> m;
        fill(mark , mark + n + 5 , 0);
        fill(comp , comp + n + 5 , 0);
        fill(adj , adj + n + 5 , vector<ll>());
        fill(radj , radj + n + 5 , vector<ll>());
        for(ll i = 0 ; i < m ; i++){
            ll v , u;
            cin >> v >> u;
            adj[v].push_back(u);
            radj[u].push_back(v);
        }
        SCC();
        if(cnt == 1)    cout << "No" << endl;
        else{
            cout << "Yes" << endl;
            cout << C[cnt] << sep << n - C[cnt] << endl;
            for(ll i = 1 ; i <= n ; i++)    if(comp[i] == cnt)  cout << i << sep;
            cout << endl;
            for(ll i = 1 ; i <= n ; i++)    if(comp[i] != cnt)  cout << i << sep;
            cout << endl;
        }
    }

    return 0;
}
/*

*/