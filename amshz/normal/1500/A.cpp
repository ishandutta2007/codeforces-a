//khodaya khodet komak kon
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
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e5 + 10;
const int xm = 2.5e6 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n;
pii b[xm], a[xn];

int main(){
	InTheNameOfGod;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].A, a[i].B = i;
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; ++ i){
		for (int j = 1; j < i; ++ j){
			int x = a[i].A - a[j].A;
			if (b[x].B && b[x].B != j && b[x].A != j && b[x].B != i){
				cout << "YES" << endl;
				cout << a[b[x].A].B << sep << a[i].B << sep << a[b[x].B].B << sep << a[j].B << endl;
				return 0;
			}
			else if (!b[x].B)
				b[x] = {j, i};
		}
	}
	kill("NO");

	return 0;
}