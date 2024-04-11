#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
ll  a[1000010], b[1000010];
int n, x, d[1000010];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++){
    	scanf("%d", &d[i]);
    }
    sort(d, d+n);
    int sum = 0;
    for(int i=1; i < n; i++){
    	sum++;
    	a[i] = a[i-1] + (d[i] - d[i-1]) * 2ll * ((sum + x - 1)/x);
	}
	sum = 0;
	for(int i=n-2; i>=0; i--){
		sum++;
    	b[i] = b[i+1] + (d[i+1] - d[i]) * 2ll * ((sum + x - 1)/x);
	}
	ll ans = inf * 1ll * inf;
	for(int i = 0; i < n; i++){
		if( ans > a[i] + b[i]) ans = a[i] + b[i];
	}
	cout << ans << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}