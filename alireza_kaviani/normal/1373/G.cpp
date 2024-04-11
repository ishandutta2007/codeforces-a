/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-06-25 19:05:02
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

int n , k , q , seg[MAXN << 2] , lz[MAXN << 2];
map<pll , ll> mark;
set<pair<ll , pll> , greater<pair<ll , pll>>> st;

void build(int id = 1 , int l = 0 , int r = MAXN){
    if(r - l == 1){
        seg[id] = l - n - 1;
        return;
    }
    int mid = l + r >> 1;
    build(id << 1 , l , mid);
    build(id << 1 | 1 , mid , r);
    seg[id] = max(seg[id << 1] , seg[id << 1 | 1]);
}

void shift(int id){
    lz[id << 1] += lz[id];
    lz[id << 1 | 1] += lz[id];
    seg[id << 1] += lz[id];
    seg[id << 1 | 1] += lz[id];
    lz[id] = 0;
}

void update(int ql , int qr , int x , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql)  return;
    if(ql <= l && r <= qr){
        seg[id] += x;
        lz[id] += x;
        return;
    }
    shift(id);
    int mid = l + r >> 1;
    update(ql , qr , x , id << 1 , l , mid);
    update(ql , qr , x , id << 1 | 1 , mid , r);
    seg[id] = max(seg[id << 1] , seg[id << 1 | 1]);
}

int get(int ql , int qr , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql)  return -MOD;
    if(ql <= l && r <= qr)  return seg[id];
    shift(id);
    int mid = l + r >> 1;
    return max(get(ql , qr , id << 1 , l , mid) , get(ql , qr , id << 1 | 1 , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> k >> q;
    build();
    while(q--){
        int x , y;
        cin >> x >> y;
        int A = y + abs(x - k) , val = (mark[{x , y}] ? -1 : 1);
        if(mark[{x , y}])   st.erase({A , {x , y}});
        else    st.insert({A , {x , y}});
        mark[{x , y}] ^= 1;
        update(0 , A + 1 , val);
        ll mx = (SZ(st) ? ((*st.begin()).X) : -INF);
        //cout << A << sep << val << endl;
        //for(int i = 0 ; i <= 15 ; i++)  cout << get(i , i + 1) << sep;
        //cout << endl;
        int l = -1 , r = MAXN;
        while(r - l > 1){
            int mid = l + r >> 1;
            if(n + mid >= mx && (n + mid >= MAXN || get(0 , n + mid + 1) <= mid))  r = mid;
            else    l = mid;
        }
        cout << r << endl;
    }

    return 0;
}
/*

*/