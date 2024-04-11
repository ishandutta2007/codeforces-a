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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct Node{
    ll val = 0;
    Node(ll v = 0){
        val = v;
    }

    friend Node merge(Node x , Node y){
        return Node(__gcd(x.val , y.val));
    }
};

template<class T , ll N>
struct SegTree {
    T seg[4 * N];

    void Build(ll id, ll l, ll r, ll arr[]) {
        if (l == r) {
            seg[id].val = arr[l];
            return;
        }
        ll mid = (l + r) / 2;
        Build(id * 2 + 1, l, mid, arr);
        Build(id * 2 + 2, mid + 1, r, arr);
        seg[id] = merge(seg[id * 2 + 1], seg[id * 2 + 2]);
    }

    void Modify(ll id, ll l, ll r, ll x, ll val) {
        if (x < l || r < x) return;
        if (l == r) {
            seg[id].val = val;
            return;
        }
        ll mid = (l + r) / 2;
        Modify(id * 2 + 1, l, mid, x, val);
        Modify(id * 2 + 2, mid + 1, r, x, val);
        seg[id] = merge(seg[id * 2 + 1], seg[id * 2 + 2]);
    }

    ll Get(ll id, ll l, ll r, ll ql, ll qr , ll x) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr){
            if(seg[id].val % x == 0)    return 0;
            if(l == r)  return 1;
            if(seg[id * 2 + 1].val % x != 0 && seg[id * 2 + 2].val % x != 0)    return 2;
        }

        ll mid = (l + r) / 2;
        return Get(id * 2 + 1, l, mid, ql, qr , x) + Get(id * 2 + 2, mid + 1, r, ql, qr , x);
    }

    void build(ll arr[]) {
        Build(0, 0, N - 1, arr);
    }
    void modify(ll x, ll val) {
        Modify(0, 0, N - 1, x, val);
    }
    ll get(ll ql, ll qr , ll x) {
        return Get(0, 0, N - 1, ql, qr , x);
    }
};

ll n , q , type , l , r , x , a[MAXN];
SegTree<Node , MAXN> seg;

int main() {
    fast_io;

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)    cin >> a[i];
    seg.build(a);

    cin >> q;
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> l >> r >> x;
            cout << (seg.get(l , r , x) <= 1 ? "YES" : "NO") << endl;
        }
        if(type == 2){
            cin >> l >> x;
            seg.modify(l , x);
        }
    }

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