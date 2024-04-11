/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-09-06 12:52:14
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

const ll MAXN = 3e5 + 10;
const ll MAXK = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , k , cnt[MAXK] , cnt2[MAXK] , A[MAXN] , ps[MAXN] , ps2[MAXN] , mx[LOG][MAXN] , lg[MAXN];
ll ans;

int get(int l , int r){
	int log = lg[r - l] , sz = (1 << log);
	int x = mx[log][l] , y = mx[log][r - sz];
	if(A[x] > A[y])	return x;
	return y;
}

void solve(int l , int r){
	if(r <= l)	return;
	int mid = get(l , r);
	ans += cnt[ps[mid]] + cnt2[ps2[mid]];
	/*cout << l << sep << r << sep << mid << sep << ans << endl;
	for(int i = 0 ; i < k ; i++){
		cout << cnt[i] << sep << cnt2[i] << endl;
	}
	cout << endl << "***************" << endl;*/
	if(mid - l < r - mid){
		for(int i = l ; i <= mid ; i++){
			cnt[(ps2[i] + A[mid]) % k]++;
		}
		solve(mid + 1 , r);
		for(int i = l ; i <= mid ; i++){
			cnt[(ps2[i] + A[mid]) % k]--;
		}
		cnt2[((ps[mid] - A[mid]) % k + k) % k]++;
		solve(l , mid);
		cnt2[((ps[mid] - A[mid]) % k + k) % k]--;
		return;
	}
	for(int i = mid ; i < r ; i++){
		cnt2[((ps[i] - A[mid]) % k + k) % k]++;
	}
	solve(l , mid);
	for(int i = mid ; i < r ; i++){
		cnt2[((ps[i] - A[mid]) % k + k) % k]--;
	}
	cnt[((ps2[mid] + A[mid])) % k]++;
	solve(mid + 1 , r);
	cnt[((ps2[mid] + A[mid])) % k]--;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	for(int i = 2 ; i < MAXN ; i++)	lg[i] = lg[i / 2] + 1;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		ps[i] = (i == 0 ? A[i] : ps[i - 1] + A[i]) % k;
		ps2[i + 1] = (ps2[i] + A[i]) % k;
	}
	for(int i = 0 ; i < MAXN ; i++){
		mx[0][i] = i;
	}
	for(int i = 1 ; i < LOG ; i++){
		int ln = (1 << (i - 1));
		for(int j = 0 ; j + ln < MAXN ; j++){
			int x = mx[i - 1][j] , y = mx[i - 1][j + ln];
			mx[i][j] = (A[x] > A[y] ? x : y);
		}
	}
	solve(1 , n + 1);
	cout << ans << endl;

    return 0;
}
/*

*/