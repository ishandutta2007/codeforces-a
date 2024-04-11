#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=10000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 100010;

ll n, x, y, ans;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%lld", &n);
	for (int i=0; i<n; i++){
		scanf("%lld %lld", &x, &y);
		ans=max(ans, x+y);
	}
	printf("%lld\n", ans);

	return 0;
}