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
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 5e5 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct Node{
    ll val = INF , lazy = 0;
    Node(ll v = INF , ll lzy = 0){
        val = v;
        lazy = lzy;
    }

    friend Node merge(const Node &x , const Node &y){
        return Node(min(x.val , y.val));
    }
};

template<class T , ll N>
struct LazySegTree {
    T seg[4 * N];

    void Build(ll id, ll l, ll r, ll arr[]) {
        if (l == r) {
            seg[id] = T(arr[l]);
            return;
        }
        ll mid = (l + r) >> 1;
        Build((id << 1), l, mid, arr);
        Build((id << 1) | 1, mid + 1, r, arr);
        seg[id] = merge(seg[(id << 1)], seg[(id << 1) | 1]);
    }

    void Shift(ll id, ll l, ll r) {
        seg[id].val += seg[id].lazy;
        if (l != r) {
            seg[(id << 1)].lazy += seg[id].lazy;
            seg[(id << 1) | 1].lazy += seg[id].lazy;
        }
        seg[id].lazy = 0;
    }

    void Update(ll id, ll l, ll r, ll ql, ll qr, ll val) {
        Shift(id, l, r);
        if (qr < l || r < ql || ql > qr)  return;
        if (ql <= l && r <= qr) {
            seg[id].lazy += val;
            Shift(id, l, r);
            return;
        }

        ll mid = (l + r) >> 1;
        Update((id << 1), l, mid, ql, qr, val);
        Update((id << 1) | 1, mid + 1, r, ql, qr, val);
        seg[id] = merge(seg[(id << 1)], seg[(id << 1) | 1]);
    }

    T Get(ll id, ll l, ll r, ll ql, ll qr) {
        Shift(id, l, r);
        if (qr < l || r < ql || ql > qr)  return T();
        if (ql <= l && r <= qr) return seg[id];

        ll mid = (l + r) >> 1;
        return merge(Get((id << 1), l, mid, ql, qr), Get((id << 1) | 1, mid + 1, r, ql, qr));
    }

    void build(ll arr[]) {
        Build(1, 0, N - 1, arr);
    }
    void update(ll ql, ll qr, ll val) {
        Update(1, 0, N - 1, ql, qr, val);
    }
    T get(ll ql, ll qr) {
        return Get(1, 0, N - 1, ql, qr);
    }
};

vector<pll> adj[MAXN];
vector<pair<pll , ll>> query[MAXN];
ll n , q , p , w , v , l , r , t = 1 , arr[MAXN] , dist[MAXN] , sz[MAXN] , ans[MAXN] , pos[MAXN];
LazySegTree<Node , MAXN> seg;

void PreDFS(ll v){
    sz[v] = 1;
    pos[v] = t++;
    for(pll i : adj[v]){
        ll u = i.X , w = i.Y;
        dist[u] = dist[v] + w;
        PreDFS(u);
        sz[v] += sz[u];
    }
}

void DFSAns(ll v , ll w = 0){
    seg.update(0 , n + 10 , w);
    seg.update(pos[v] , pos[v] + sz[v] - 1 , -w * 2);

    for(pair<pll , ll> i : query[v]){
        ans[i.Y] = seg.get(i.X.X , i.X.Y).val;
    }
    for(pll i : adj[v]){
        ll u = i.X , w = i.Y;
        DFSAns(u , w);
    }
    seg.update(0 , n + 10 , -w);
    seg.update(pos[v] , pos[v] + sz[v] - 1 , w * 2);
}

int main() {
    fast_io;

    cin >> n >> q;
    for(ll i = 2 ; i <= n ; i++){
        cin >> p >> w;
        adj[p].push_back({i , w});
    }
    for(ll i = 0 ; i < q ; i++){
        cin >> v >> l >> r;
        query[v].push_back({{l , r} , i});
    }
    PreDFS(1);

    for(ll i = 1 ; i <= n ; i++){
        if(sz[i] != 1)  dist[i] = INF;
        arr[pos[i]] = dist[i];
    }
    seg.build(arr);

    DFSAns(1);
    for(ll i = 0 ; i < q ; i++) cout << ans[i] << endl;


    return 0;
}
/*

*/