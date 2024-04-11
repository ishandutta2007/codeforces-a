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


set<vector<string>> gen(vector<string> a) {
    set<vector<string>> res;
    queue<vector<string>> q;
    q.push(a);
    res.insert(a);

    auto add = [&](vector<string> b) {
        if (!res.count(b)) {
            res.insert(b);
            q.push(b);
        }
    };

    while (!q.empty()) {
        auto v = q.front();
        q.pop();


        if (v[0][0] == 'X') {
            swap(v[0][0], v[1][0]);
            add(v);
            swap(v[0][0], v[1][0]);

            swap(v[0][0], v[0][1]);
            add(v);
            swap(v[0][0], v[0][1]);
        } else if (v[1][0] == 'X') {

            swap(v[1][0], v[0][0]);
            add(v);
            swap(v[1][0], v[0][0]);

            swap(v[1][0], v[1][1]);
            add(v);
            swap(v[1][0], v[1][1]);
        } else if (v[0][1] == 'X') {

            swap(v[0][1], v[1][1]);
            add(v);
            swap(v[0][1], v[1][1]);

            swap(v[0][1], v[0][0]);
            add(v);
            swap(v[0][1], v[0][0]);
        } else {
            swap(v[1][1], v[0][1]);
            add(v);
            swap(v[1][1], v[0][1]);

            swap(v[1][1], v[1][0]);
            add(v);
            swap(v[1][1], v[1][0]);
        }
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
    //freopen("a.out", "w", stdout);

#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif

    vector<string> a;
    string s;
    cin >> s;
    a.pb(s);
    cin >> s;
    a.pb(s);

    vector<string> b;
    ;
    cin >> s;
    b.pb(s);
    cin >> s;
    b.pb(s);

    auto x = gen(a);
    auto y = gen(b);

    for (auto h : x) {
        if (y.count(h)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}