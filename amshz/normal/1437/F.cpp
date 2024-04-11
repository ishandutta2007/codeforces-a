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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 5e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, a[xn], b[xn], dp[xn][xn];

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j < i; ++ j)
			if (a[j] >= a[i] * 2)
				b[i] = j;
	}
	dp[0][0] = 1;
	for (ll i = 1; i <= n; ++ i){
		for (ll j = 1; j < i; ++ j){
			dp[i][j] = dp[i][j - 1];
			if (a[i] * 2 <= a[j]) dp[i][j] = (dp[i][j] + (dp[i - 1][j] - dp[i - 1][j - 1] + mod) % mod * (i - 1) % mod) % mod;
			else dp[i][j] = (dp[i][j] + (dp[i - 1][j] - dp[i - 1][j - 1] + mod) % mod * (i - 2) % mod) % mod;
		}
		dp[i][i] = dp[i][i - 1];
		if (b[i] || i == 1) dp[i][i] = (dp[i][i] + dp[i - 1][b[i]]) % mod;
	}
	cout << dp[n][n] << endl;
			
	return 0;
}