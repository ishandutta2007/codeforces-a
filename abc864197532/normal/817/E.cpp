/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 200000;

struct trie {
    trie* ch[2] = {NULL, NULL};
    int sz = 0;
    void add(int v, int d, int p = 29) {
        sz += d;
        if (p == -1) return;
        int f = v >> p & 1;
        if (!ch[f]) ch[f] = new trie();
        ch[f]->add(v, d, p - 1);
    }
    int query(int v, int l, int p = 29) {
        if (p == -1) return 0;
        int f = v >> p & 1;
        if (l >> p & 1) {
            return (ch[f] ? ch[f]->sz : 0) + (ch[f ^ 1] ? ch[f ^ 1]->query(v, l, p - 1) : 0);
        } else {
            return (ch[f] ? ch[f]->query(v, l, p - 1) : 0);
        }
    }
} T;

int main () {
    owo;
    int q;
    cin >> q;
    while (q--) {
        int t, p, l;
        cin >> t >> p;
        if (t == 1) {
            T.add(p, 1);
        } else if (t == 2) {
            T.add(p, -1);
        } else {
            cin >> l;
            cout << T.query(p, l) << endl;
        }
    }
}