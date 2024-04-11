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
const int maxn = 1e5 + 5;

pair<int,int> rmq[20][maxn];
int llg[maxn];


pair<int,int> get(int l, int r) {
	int x = llg[r - l];
	return max(rmq[x][l], rmq[x][r - (1 << x) + 1]);
}

ll rec(int l, int r) {
	if (l > r - 1) {
		return 0;
	}
	
	auto rr = get(l, r - 1);
	ll res = rr.fst * 1LL * (rr.snd - l + 1) * (r - (rr.snd + 1) + 1);
	
	res += rec(l, rr.snd);
	res += rec(rr.snd + 1, r);
	
	return res;
}


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

	
	for (int i = 1; i < maxn; i++) {
		while ((1 << (llg[i])) <= i) {
			llg[i]++;
		}
		llg[i]--;
	}

    int n, q;
    scanf("%d %d", &n, &q);
    
    vector<int> a;
    for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.pb(x);
	}
	

	
	for (int i = 0; i + 1 < n; i++) {
		rmq[0][i] = mp(abs(a[i + 1] - a[i]), i);
	}
	
	for (int i = 1; i < 20; i++) {
		for (int j = 0; j + (1 << i) - 1 < n - 1; j++) {
			rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
		}
	}
	
	
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--, r--;
		cout << rec(l, r) << endl;
	}


    return 0;
}