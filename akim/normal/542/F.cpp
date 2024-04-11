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

vector<int> vc[maxn];

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

	int n, t;
	scanf("%d%d", &n, &t);
	for(int i = 0; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		vc[u].pb(v);
	}
	for(int i = 0; i < t; i++) {
		sort(vc[i].begin(), vc[i].end());
		while(vc[i].size() > 1) {
			int u = vc[i].back(); vc[i].ppb();
			int v = vc[i].back(); vc[i].ppb();
			vc[i + 1].pb(u + v);
		}
		if(vc[i].size() == 1) {vc[i + 1].pb(vc[i].back()); vc[i].ppb();}
	}
	sort(vc[t].begin(), vc[t].end());
	printf("%d", vc[t].back());

	return(0);
}

// by Kim Andrey