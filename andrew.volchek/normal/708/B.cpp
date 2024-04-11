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


//-----------------------------------------------------------------------------


int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
   // gen();

    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    ll a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;

    if (a00 + a01 + a10 + a11 == 0) {
        cout << "1" << endl;
        return 0;
    }

    ll zero = 0;
    while (zero * (zero - 1) / 2 < a00) {
        zero++;
    }

    ll one = 0;
    while (one * (one - 1) / 2 < a11) {
        one++;
    }

    if (zero * (zero - 1) / 2 != a00 || one * (one - 1) / 2 != a11) {
        printf("Impossible\n");
        return 0;
    }

    if (!zero && (a01 || a10)) {
        zero = 1;
    }

    if (!one && (a10 || a01)) {
        one = 1;
    }

    /*if (!zero && a01) {
        if (!one && a01) {
            one = 1;
        }
        if (a01 == one && a10 == 0) {
            cout << "0";
            for (int i = 0; i < one; i++) {
                cout << "1";
            }
            cout << endl;
            return 0;
        } else {
            printf("Impossible\n");
            return 0;
        }
    }

    if (!one && a10) {
        if (!zero && a10) {
            zero = 1;
        }
        if (a10 == zero && a01 == 0) {
            cout << "1";
            for (int i = 0; i < zero; i++) {
                cout << "0";
            }
            cout << endl;
            return 0;
        } else {
            printf("Impossible\n");
            return 0;
        }
    }*/


    string x, y, z;
    for (int i = 0; i < zero; i++) {
        x += '0';
    }

    for (int i = 0; i < one; i++) {
        y += '1';
    }

    while (x.size() * 1LL * y.size() > a01) {
        if ((x.size() - 1) * 1LL * y.size() >= a01) {
            z += '0';
            x.pop_back();
        } else {
            break;
        }
    }




    ll need = x.size() * 1LL * y.size() - a01;

    if (need) {
        x.pop_back();
    }

    string ans = x;
    for (int i = 0; i < y.size(); i++) {
        ans += '1';
        if (need && i + 1 == need) {
            ans += '0';
        }
    }


    ans += z;



    ll b01 = 0, b10 = 0;
    ll b0 = 0, b1 = 0;
    for (char c : ans) {
        if (c == '0') {
            b0++;
            b10 += b1;
        } else {
            b1++;
            b01 += b0;
        }
    }


    if (a01 != b01 || a10 != b10 || b0 * (b0 - 1) / 2 != a00 || b1 * (b1 - 1) / 2 != a11) {
        printf("Impossible\n");
        return 0;
    }

    printf("%s\n", ans.c_str());

    return 0;
}