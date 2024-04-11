/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-08-21 19:05:02
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

const ll MAXN = 1 << 20;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , q , A[MAXN] , val[MAXN] , seg[MAXN] , lz[MAXN] , lc[MAXN] , rc[MAXN];

void build(int id = 1 , int l = 0 , int r = m , int v = m / 2){
	val[id] = v;
	lc[id] = (id << 1);
	rc[id] = (lc[id] | 1);
	if(r - l == 1){
		seg[id] = A[l];
		return;
	}
	int mid = l + r >> 1;
	build(lc[id] , l , mid , v / 2);
	build(rc[id] , mid , r , v / 2);
	seg[id] = seg[lc[id]] + seg[rc[id]];
}

void shift(int id){
	lz[lc[id]] ^= lz[id];
	lz[rc[id]] ^= lz[id];
	if(lz[id] & val[id]){
		swap(lc[id] , rc[id]);
	}
	lz[id] = 0;
}

void modify(int x , int k , int id = 1 , int l = 0 , int r = m){
	if(r - l == 1){
		seg[id] = k;
		return;
	}
	shift(id);
	int mid = l + r >> 1;
	if(x < mid)	modify(x , k , lc[id] , l , mid);
	else	modify(x , k , rc[id] , mid , r);
	seg[id] = seg[lc[id]] + seg[rc[id]];
}

ll get(int ql , int qr , int id = 1 , int l = 0 , int r = m){
	if(qr <= l || r <= ql)	return 0;
	if(ql <= l && r <= qr)	return seg[id];
	shift(id);
	int mid = l + r >> 1;
	return get(ql , qr , lc[id] , l , mid) + get(ql , qr , rc[id] , mid , r);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> q;
	m = (1 << n);
	for(int i = 0 ; i < m ; i++)	cin >> A[i];
	build();
	while(q--){
		int t , x , k , l , r;
		cin >> t;
		if(t == 1){
			cin >> x >> k;
			x--;
			modify(x , k);
		}
		if(t == 2){
			cin >> k;
			lz[1] ^= (1 << k) - 1;
		}
		if(t == 3){
			cin >> k;
			lz[1] ^= (1 << k);
		}
		if(t == 4){
			cin >> l >> r;
			l--;
			cout << get(l , r) << endl;
		}
	}

    return 0;
}
/*

*/