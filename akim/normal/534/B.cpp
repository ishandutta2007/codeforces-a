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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int v[maxn];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int v2, t, d;
	cin >> v[0] >> v2;
	cin >> t >> d;
	for(int i = 1; i < t; i++) {
		v[i] = v[i - 1] + d;
	}
	v[t - 1] = v2;
	for(int i = t - 2; i > 0; i--) {
		v[i] = min(v[i + 1] + d, v[i]);
	}
	int ans = 0;
	for(int i = 0; i < t; i++) {
		ans += v[i];
	}
	cout << ans;

	return(0);
}

// by Kim Andrey