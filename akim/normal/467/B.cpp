#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

int x[100100];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	int n, m, k, o = 0; scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++) {
		scanf("%d", &x[i]);
	}
	scanf("%d", &n);
	for(int i = 0; i < m; i++) {
		int p = (n ^ x[i]), q = 0;
		while(p > 0) {
			q += (p & 1);
			p /= 2;
		}
		if(q <= k) {
			o++;
		}
	}
	printf("%d", o);

	return(0);
}

// by Kim Andrey