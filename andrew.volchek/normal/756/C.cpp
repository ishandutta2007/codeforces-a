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
#include <tuple>
#include <complex>
#include <numeric>
#include <future>

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

const ld pi = acos(-1.0);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
bool chmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
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


//--------------------------------------------------------------------------

const int maxn = 1e5 + 5;
ll mx[maxn * 4];
ll add[maxn * 4];

void madd(int v, int l, int r, int i, int j, int val) {
    if (i <= l && r <= j) {
        mx[v] += val;
        add[v] += val;
        return;
    }
    int c = (l + r) >> 1;
    if (i <= c) {
        madd(2 * v, l, c, i, j, val);
    }
    if (c < j) {
        madd(2 * v + 1, c + 1, r, i, j, val);
    }

    mx[v] = max(mx[2 * v], mx[2 * v + 1]) + add[v];
}

int lb(int v, int l, int r, ll d) {
    if (l == r) {
        return (mx[v] + d) > 0 ? l : -1;
    }
    int c = (l + r) >> 1;
    if (mx[2 * v + 1] + d + add[v] > 0) {
        return lb(2 * v + 1, c + 1, r, d + add[v]);
    } else {
        return lb(2 * v, l, c, d + add[v]);
    }
}

int a[maxn];

int main() {
    srand(time(NULL));


#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int pos, type;
        scanf("%d %d", &pos, &type);
        if (type == 0) {
            madd(1, 1, n, 1, pos, -1);
        } else {
            scanf("%d", a + pos);
            madd(1, 1, n, 1, pos, +1);
        }

        int res = lb(1, 1, n, 0);
        if (res == -1) {
            printf("-1\n");
        } else {
            printf("%d\n", a[res]);
        }
    }




    return 0;
}