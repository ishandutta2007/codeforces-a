/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-09-06 19:05:01
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

const ll MAXN = (1 << 19);
const ll LOG = 19;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , q , ans[MAXN] , A[MAXN] , fen[MAXN];
vector<pii> Q[MAXN];

void add(int x , int v){
	for( ; x < MAXN ; x += x & -x)	fen[x] += v;
}

int get(int x){
	int ans = 0;
	for( ; x > 0 ; x -= x & -x)	ans += fen[x];
	return ans;
}

int Find(int x){
	int ans = 0;
	for(int i = LOG - 1 ; i >= 0 ; i--){
		int ln = (1 << i);
		if(fen[ans + ln] >= x){
			x -= fen[ans + ln];
			ans += ln;
		}
	}
	return ans + 1;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		A[i] = i - A[i];
		if(A[i] < 0)	A[i] = MOD;
	}
	for(int i = 1 ; i <= q ; i++){
		int x , y;
		cin >> x >> y;
		int l = x + 1 , r = n - y;
		Q[r].push_back({l , i});
	}
	for(int i = 1 ; i <= n ; i++){
		int ind = min(i + 1 , Find(A[i]));
		add(1 , 1);
		add(ind , -1);
		for(pii j : Q[i]){
			ans[j.Y] = get(j.X);
		}
	}
	for(int i = 1 ; i <= q ; i++){
		cout << ans[i] << endl;
	}

    return 0;
}
/*

*/