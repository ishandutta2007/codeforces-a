#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>
#include <limits>
#include <complex>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------


const int maxn = 405;
const int inf = 1e9;

int g[maxn][maxn];

int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        fill(g[i], g[i] + maxn, inf);
        g[i][i] = 0;
    }



	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		g[u][v] = 1;
		g[v][u] = 1;
	}
	
	if (g[0][n - 1] == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][j] == inf) {
					g[i][j] = 1;
				} else if (g[i][j] == 1) {
					g[i][j] = inf;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
			}
		}
	}
	
	if (g[0][n - 1] == inf) {
		cout << -1 << endl;
	} else {
		cout << g[0][n - 1] << endl;
	}



    return 0;
}