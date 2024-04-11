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

char c[100][100];

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

	int mnx = mod, mny = mod, mxx = -mod, mxy = -mod;
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("\n");
		for(int j = 0; j < m; j++) {
			c[i][j] = getchar();
			if(c[i][j] != '.') {
				mnx = min(mnx, i);
				mny = min(mny, j);
				mxx = max(mxx, i);
				mxy = max(mxy, j);
			}
		}
	}

	for(int i = mnx; i <= mxx; i++) {
		for(int j = mny; j <= mxy; j++) {
			printf("%c", c[i][j]);
		}
		printf("\n");
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