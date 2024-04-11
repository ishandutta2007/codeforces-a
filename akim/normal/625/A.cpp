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

ll n, a, b, c;

ll d(ll m) {
	return(m + (n - m * (b - c)) / a);
}

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

	scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
	ll l = 0, r = (n - b >= 0 ? (n - b) / (b - c) : -1ll) + 1ll;
	while(l + 100 < r) {
		ll m1 = l + ((r - l) / 3), m2 = r - ((r - l) / 3);
		if(d(m1) < d(m2)) {
			l = m1;
		} else {
			r = m2;
		}
	}
	ll ans = 0;
	for(ll i = l; i <= r; i++) {
		ans = max(ans, d(i));
	}
	printf("%lld", ans);

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