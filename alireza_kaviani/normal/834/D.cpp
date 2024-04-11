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
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

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
#define file_io                     freopen("in.txt" , "r" , stdin) ; freopen("out.txt" , "w" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 35e3 + 10;
const ll MAXK = 60;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct Node{
    ll val = 0 , lazy = 0;
    Node(ll v = 0 , ll lzy = 0){
        val = v;
        lazy = lzy;
    }

    friend Node merge(const Node &x , const Node &y){
        return Node(max(x.val , y.val));
    }
};

template<class T , ll N>
struct LazySegTree {
    T seg[4 * N];

    void Build(ll id, ll l, ll r, ll arr[]) {
        if (l == r) {
            seg[id].val = arr[l];
            return;
        }
        ll mid = (l + r) >> 1;
        Build(id * 2, l, mid, arr);
        Build(id * 2 | 1, mid + 1, r, arr);
        seg[id] = merge(seg[id * 2], seg[id * 2 | 1]);
    }

    void Modify(ll id, ll l, ll r, ll x, ll val) {
        if (x < l || r < x) return;
        if (l == r) {
            seg[id].val = val;
            return;
        }
        ll mid = (l + r) >> 1;
        Modify(id * 2, l, mid, x, val);
        Modify(id * 2 | 1, mid + 1, r, x, val);
        seg[id] = merge(seg[id * 2], seg[id * 2 | 1]);
    }

    void Shift(ll id, ll l, ll r) {
        seg[id].val += seg[id].lazy;
        if (l != r) {
            seg[id * 2].lazy += seg[id].lazy;
            seg[id * 2 | 1].lazy += seg[id].lazy;
        }
        seg[id].lazy = 0;
    }

    void Add(ll id, ll l, ll r, ll ql, ll qr, ll val) {
        Shift(id, l, r);
        if (qr < l || r < ql || l > r)  return;
        if (ql <= l && r <= qr) {
            seg[id].lazy += val;
            Shift(id, l, r);
            return;
        }

        ll mid = (l + r) >> 1;
        Add(id * 2, l, mid, ql, qr, val);
        Add(id * 2 | 1, mid + 1, r, ql, qr, val);
        seg[id] = merge(seg[id * 2], seg[id * 2 | 1]);
    }

    Node Get(ll id, ll l, ll r, ll ql, ll qr) {
        Shift(id, l, r);
        if (qr < l || r < ql || l > r)  return 0;
        if (ql <= l && r <= qr) return seg[id];

        ll mid = (l + r) >> 1;
        return merge(Get(id * 2, l, mid, ql, qr), Get(id * 2 | 1, mid + 1, r, ql, qr));
    }

    void build(ll arr[]) {
        Build(1, 0, N - 1, arr);
    }
    void modify(ll x, ll val) {
        Modify(1, 0, N - 1, x, val);
    }
    void add(ll ql, ll qr, ll val) {
        Add(1, 0, N - 1, ql, qr, val);
    }
    Node get(ll ql, ll qr) {
        return Get(1, 0, N - 1, ql, qr);
    }
};


ll n , k , a[MAXN] , last[MAXN];
LazySegTree<Node , MAXN> seg[MAXK];

int main() {
    fast_io;

    cin >> n >> k;
    for(ll i = 1 ; i <= n ; i++)    cin >> a[i];

    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= k ; j++){
            seg[j - 1].add(last[a[i]] , i - 1 , 1);
            ll res = seg[j - 1].get(0 , i - 1).val;
            seg[j].modify(i , res);
        }
        last[a[i]] = i;
    }
    cout << seg[k].get(n , n).val;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/