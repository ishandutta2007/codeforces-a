#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//	tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;
//	order_of_key
//	find_by_order
#endif

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int x[maxn];
bitset<501> dp[550];
bool pm[maxn];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	pm[0] = 1;
	dp[0][0] = 1;
	for(int id = 0; id < n; id++) {
		for(int i = k; i >= 0; i--) {
			if(!pm[i]) {
				continue;
			}
			if(i + x[id] <= k) dp[i + x[id]] |= (dp[i] | (dp[i] << x[id]));
			if(i + x[id] <= k) pm[i + x[id]] = 1;
		}
	}

	int ans = 0;
	for(int i = 0; i <= k; i++) {
		if(dp[k][i]) ans++;
	}
	printf("%d\n", ans);
	for(int i = 0; i <= k; i++) {
		if(dp[k][i]) {
			printf("%d ", i);
		}
	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim