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

const ld pi = acos(-1.0l);

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


int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    // gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    map<int, int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s[x]++;
    }

    set<pair<int,int>> f;
    for (auto kv : s) {
        f.insert(mp(kv.snd, kv.fst));
    }

    vector<vector<int>> ans;
    while (f.size() >= 3) {
        auto u = *f.rbegin();
        f.erase(*f.rbegin());
        auto v = *f.rbegin();
        f.erase(*f.rbegin());
        auto w = *f.rbegin();
        f.erase(*f.rbegin());

        ans.pb({u.snd, v.snd, w.snd});

        u.fst--;
        if (u.fst) {
            f.insert(u);
        }

        v.fst--;
        if (v.fst) {
            f.insert(v);
        }

        w.fst--;
        if (w.fst) {
            f.insert(w);
        }
    }

    cout << ans.size() << endl;
    for (auto v : ans) {
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (int i = 0; i < 3; i++) {
            if (i) {
                cout << " ";
            }
            cout << v[i];
        }
        cout << endl;
    }


    return 0;
}