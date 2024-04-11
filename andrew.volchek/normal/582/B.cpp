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

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
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
ostream operator << (ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 105;
int inf = 1e9;
struct M {
    int a[maxn][maxn];
    M() {
        for (int i = 0; i < maxn; i++) {
            fill(a[i], a[i] + maxn, -inf);
        }
    }

    M operator * (const M &o) const {
        M res;
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j <= i; j++) {
                for (int k = j; k <= i; k++) {
                    chmax(res.a[i][j], a[i][k] + o.a[k][j]);
                }
            }
        }
        return res;
    }
};

M bpow(M x, int n) {
    M res;
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j <= i; j++) {
            res.a[i][j] = 0;
        }
    }
    while (n) {
        if (n & 1) {
            res = res * x;
        }
        x = x * x;
        n >>= 1;
    }
    return res;
}

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, T;
    cin >> n >> T;
    vector<int> a, cc;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.pb(x);
        cc.pb(x);
    }
    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());

    for (int &x : a) {
        x = lower_bound(cc.begin(), cc.end(), x) - cc.begin();
    }

    M x;

    for (int i = 0; i < maxn; i++) {
        vector<int> c(maxn, -inf);
        c[i] = 0;

        for (int j = 0; j < n; j++) {
            vector<int> nc = c;
            for (int h = 0; h <= a[j]; h++) {
                chmax(nc[a[j]], c[h] + 1);
            }
            c = nc;
        }

        for (int j = 0; j < maxn; j++) {
            x.a[j][i] = c[j];
        }
    }


    M res = bpow(x, T);

    int ans = 0;
    for (int i = 0; i < maxn; i++) {
        chmax(ans, res.a[i][0]);
    }

    cout << ans << endl;


    return 0;
}