# include <bits/stdc++.h>
 
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e6 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;
 
int qq, n, a[xn], b[xn], c[xn], d[xn];

ll check(int x){
	for (int i = 1; i <= n; ++ i) c[i] = a[i], d[i] = b[i];
	d[1] = x;
	for (int i = 2; i <= n; ++ i){
		if (c[i] > d[i] + d[i - 1]) return -1;
		c[i] = max(0, c[i] - d[i - 1]);
		d[i] -= c[i];
	}
	return d[n];
}
 
int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> n;
    	for (int i = 1; i <= n; ++ i) cin >> a[i];
    	for (int i = 1; i <= n; ++ i) cin >> b[i];
    	int l = -1, r = a[2] + 1;
    	while (r - l > 1){
    		int mid = l + r >> 1;
    		if (check(mid) == -1) l = mid;
    		else r = mid;
		}
		if (r == a[2] + 1 || r > b[1]){
			cout << "NO" << endl;
			continue;
		}
		if (b[1] - r + check(r) >= a[1]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
    return 0;
}