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
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
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
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 1, N = 1002, logN = 20, K = 600, M = 1e9 + 1;

struct Seg {
    int l, r, m, a, b, c, ab, bc, abc;
    Seg* ch[2];
    Seg (int _l, int _r, string &s) : l(_l), r(_r), m(l + r >> 1), a(0), b(0), c(0), ab(0), bc(0), abc(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, s);
            ch[1] = new Seg(m, r, s);
            pull();
        } else {
            if (s[l] == 'a') a++;
            else if (s[l] == 'b') b++;
            else c++;
        }
    }
    void pull() {
        a = ch[0]->a + ch[1]->a;
        b = ch[0]->b + ch[1]->b;
        c = ch[0]->c + ch[1]->c;
        ab = min({ch[0]->a + ch[1]->b, ch[0]->ab + ch[1]->b, ch[0]->a + ch[1]->ab, a, b});
        bc = min({ch[0]->b + ch[1]->c, ch[0]->bc + ch[1]->c, ch[0]->b + ch[1]->bc, b, c});
        abc = min({ch[0]->abc + ch[1]->c, ch[0]->a + ch[1]->abc, ch[0]->a + ch[1]->bc, ch[0]->ab + ch[1]->c, a, b, c, ab, bc, ch[0]->ab + ch[1]->bc});
    }
    void set(int p, char chr) {
        if (r - l == 1) {
            a = b = c = 0;
            if (chr == 'a') a++;
            else if (chr == 'b') b++;
            else c++;
        } else {
            ch[p >= m]->set(p, chr), pull();
        }
    }
};

int main () {
    owo;
    int n, q;
    string s;
    cin >> n >> q >> s;
    Seg root(0, n, s);
    int p;
    char c;
    while (q--) {
        cin >> p >> c, --p;
        root.set(p, c);
        cout << root.abc << endl;
    }
}