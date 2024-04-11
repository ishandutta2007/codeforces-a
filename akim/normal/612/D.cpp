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

vector<pair<int, int> > vc, ans;

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
		int l, r;
		scanf("%d%d", &l, &r);
		vc.pb(mp(l, -1));
		vc.pb(mp(r, 1));
	}

	sort(vc.begin(), vc.end());

	int bal = 0;
	int lo = -mod;
	bool o = 0;
	for(int i = 0; i < n * 2; i++) {
		bal -= vc[i].sc;
		if(bal == k && !o) {
			o = 1;
			lo = vc[i].fs;
		} else
		if(bal == k - 1 && o) {
			ans.pb(mp(lo, vc[i].fs));
			o = 0;
		}
	}
	printf("%d\n", (int)ans.size());
	for(int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].fs << " " << ans[i].sc << endl;
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