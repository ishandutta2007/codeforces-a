#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define x first
#define y second
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-6;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
const ll MAX = 5000 + 1;
#else
const ll MAX = 2e5 + 1;
#endif

#ifdef LOCAL
//#define DEBUG
#endif

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	bool a[n], b[n];
	ms(a);
	ms(b);

	for(int i = 1; i <= n * n; i++){
		int x, y;
		cin >> x >> y;
		if(!a[x - 1] && !b[y - 1]){
			cout << i << " ";
			a[x - 1] = b[y - 1] = 1;
		}
	}

}