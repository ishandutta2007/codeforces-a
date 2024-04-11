/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-10-17 16:35:02
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
#define lc							id << 1
#define rc							lc | 1

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , prv[MAXN] , mx[MAXN << 2] , lz[MAXN << 2];
ll ans = 0;
string s;

void shift(int id){
	mx[lc] += lz[id];
	mx[rc] += lz[id];
	lz[lc] += lz[id];
	lz[rc] += lz[id];
	lz[id] = 0;
}

int Find(int x , int id = 1 , int l = 0 , int r = MAXN){
	if(mx[id] < x)	return -1;
	if(r - l == 1)	return l;
	shift(id);
	int mid = l + r >> 1;
	if(mx[rc] >= x)	return Find(x , rc , mid , r);
	return Find(x , lc , l , mid);
}

void add(int ql , int qr , int id = 1 , int l = 0 , int r = MAXN){
	if(qr <= l || r <= ql || qr <= ql)	return;
	if(ql <= l && r <= qr){
		lz[id]++;
		mx[id]++;
		return;
	}
	shift(id);
	int mid = l + r >> 1;
	add(ql , qr , lc , l , mid);
	add(ql , qr , rc , mid , r);
	mx[id] = max(mx[lc] , mx[rc]);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> s;
	ll res = 0;
	for(int i = 0 , cur = 0 ; i < n ; i++){
		if(s[i] == '1')	cur++;
		else	cur = 0;
		int x = min(i , Find(cur));
		ans += i - x;
		res += ans;
		add(x + 1 , i + 1);
		// cout << i << sep << x << sep << cur << sep << ans << endl;
	}
	cout << res << endl;

    return 0;
}
/*

*/