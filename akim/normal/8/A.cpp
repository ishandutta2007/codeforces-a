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

	string s, t, r;
	getline(cin, s);
	getline(cin, t);
	getline(cin, r);
	int ns = s.length();
	int i, j;
	bool ok1 = 0;
	for(i = 0; i < ns; i++) {
		if(i + t.length() <= ns) {
			ok1 = 1;
			for(int j = 0; j < t.length(); j++) {
				if(s[i + j] != t[j]) {
					ok1 = 0;
					break;
				}
			}
		}
		if(ok1) break;
	}
	bool ok2 = 0;
	for(i+=t.length(); i < ns; i++) {
		if(i + r.length() <= ns) {
			ok2 = 1;
			for(int j = 0; j < r.length(); j++) {
				if(s[i + j] != r[j]) {
					ok2 = 0;
					break;
				}
			}
		}
		if(ok2) break;
	}
	bool oks1 = ((ok1 || t.empty()) && (ok2 || r.empty()));

	reverse(s.begin(), s.end());
	ok1 = 0;
	for(i = 0; i < ns; i++) {
		if(i + t.length() <= ns) {
			ok1 = 1;
			for(int j = 0; j < t.length(); j++) {
				if(s[i + j] != t[j]) {
					ok1 = 0;
					break;
				}
			}
		}
		if(ok1) break;
	}
	ok2 = 0;
	for(i+=t.length(); i < ns; i++) {
		if(i + r.length() <= ns) {
			ok2 = 1;
			for(int j = 0; j < r.length(); j++) {
				if(s[i + j] != r[j]) {
					ok2 = 0;
					break;
				}
			}
		}
		if(ok2) break;
	}
	bool oks2 = ((ok1 || t.empty()) && (ok2 || r.empty()));

	if(oks1) {
		if(oks2) {
			printf("both");
		} else {
			printf("forward");
		}
	} else {
		if(oks2) {
			printf("backward");
		} else {
			printf("fantasy");
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