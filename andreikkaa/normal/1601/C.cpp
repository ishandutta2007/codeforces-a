/*
* C++11 code template for contests.
* @author: Andrei Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

//#define ANDREIKKAA_ALLOCATOR
const int _ML = 500;

const char _inpf[] =
#if defined(ANDREIKKAA)
        "input.txt"
#else
""
#endif
;
const char _outf[] =
#if defined(ANDREIKKAA)
        ""
#else
""
#endif
;

#if defined(ANDREIKKAA)
#undef NDEBUG
#else
#pragma GCC optimize("O3,no-stack-protector")
#endif
#include "bits/stdc++.h"
#if !defined(ANDREIKKAA)
#define endl '\n'
#endif
#define x first
#define y second
using namespace std;
#define rand abcdefghijklmnopqrstuvwxyz
#define random_shuffle abcdefghijklmnopqrstuvwxyz
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using ld = double;
const ld PI = 3.14159265358979323846;
mt19937 rd(228);
#if defined(ANDREIKKAA_ALLOCATOR)
char _mem[_ML * 1024 * 1024];
size_t _ptr = 0;
inline void* operator new (size_t _x) { _ptr += _x; assert(_ptr < _ML * 1024 * 1024); return _mem + _ptr - _x; }
inline void operator delete (void*) { }
#endif
template<class T, class U> inline ostream &operator<< (ostream &, const pair<T, U> &);
template<class T, class U> inline istream &operator>> (istream &, pair<T, U> &);
template<class T> inline ostream &operator<< (ostream &, const vector<T> &);
template<class T> inline istream &operator>> (istream &, vector<T> &);
template<class T> inline ostream &operator<< (ostream &, const set<T> &);
template<class T> inline ostream &operator<< (ostream &, const multiset<T> &);
template<class T> inline ostream &operator<< (ostream &, const unordered_set<T> &);
template<class T> inline ostream &operator<< (ostream &, const unordered_multiset<T> &);
template<class T, class U> inline ostream &operator<< (ostream &, const map<T, U> &);
template<class T, class U> inline ostream &operator<< (ostream &, const unordered_map<T, U> &);
template<class T, size_t N> inline ostream &operator<< (ostream &, const array<T, N> &);
template<class T, size_t N> inline ostream &operator>> (ostream &, array<T, N> &);

/* ________ CODE ________ */

const int N = 1'000'228;
int p[4 * N];
int t[4 * N];

void upd_t(int v, int l, int r, int L, int R, int X) {
    if(R <= l || r <= L) {
        return;
    }

    if(L <= l && r <= R) {
        t[v] += X;
        p[v] += X;
        return;
    }

    upd_t(v << 1, l, (l + r) >> 1, L, R, X);
    upd_t(v << 1 | 1, (l + r) >> 1, r, L, R, X);
    t[v] = min(t[v << 1], t[v << 1 | 1]) + p[v];
}

int fen[N];
int get_t(int x) {
    int ans = 0;
    for(; x >= 0; x = (x & (x + 1)) - 1) {
        ans += fen[x];
    }
    return ans;
}

void upd_t(int x, int n) {
    for(; x < n; x |= (x + 1)) {
        ++fen[x];
    }
}

void _solve() {
    int n, m;
    cin >> n >> m;

    memset(t, 0, sizeof(int) * 4 * (n + 1));
    memset(p, 0, sizeof(int) * 4 * (n + 1));

    vector<int> a(n);
    cin >> a;

    map<int, int> mp;
    for(int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }

    for(int i = 0; i < n; ++i) {
        upd_t(1, 0, n + 1, i + 1, n + 1, 1);
    }

    ll ans = 0;

    vector<pair<int, int>> s(n);
    for(int i = 0; i < n; ++i) {
        s[i] = {a[i], i};
    }

    sort(all(s));
    int ptr = 0;
    for(auto i : mp) {
        while(ptr < n && s[ptr].x < i.x) {
            upd_t(1, 0, n + 1, s[ptr].y + 1, n + 1, -1);
            upd_t(1, 0, n + 1, 0, s[ptr].y + 1, 1);
            ++ptr;
        }

        int p = ptr;
        for(; p < n && s[p].x == i.x; ++p) {
            upd_t(1, 0, n + 1, s[p].y + 1, n + 1, -1);
        }
        ans += t[1] * ll(i.y);
        for(--p; p >= ptr; --p) {
            upd_t(1, 0, n + 1, s[p].y + 1, n + 1, 1);
        }
    }

    vector<int> c = a;
    sort(all(c));
    c.erase(unique(all(c)), c.end());

    memset(fen, 0, sz(c) * sizeof(int));

    for(int i : a) {
        int p = lower_bound(all(c), i) - c.begin();
        ans += get_t(sz(c) - p - 2);
        upd_t(sz(c) - p - 1, sz(c));
    }

    cout << ans << endl;
}

void _main_function() {
    int t = 1;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        _solve();
    }
}

/* ________ CODE ________ */

int main() {
#if defined(ANDREIKKAA)
    time_t _start = clock();
#endif
    if (_inpf[0] != '\0') assert(freopen(_inpf, "r", stdin) != nullptr);
    if (_outf[0] != '\0') assert(freopen(_outf, "w", stdout) != nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout << setprecision(20);
    cout << fixed;

    _main_function();
#if defined(ANDREIKKAA)
    cout << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl;
#endif
}

template<class T, class U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) {
    _out << _p.x << ' ' << _p.y;
    return _out;
}
template<class T, class U> inline istream &operator>> (istream &_in, pair<T, U> &_p) {
    _in >> _p.x >> _p.y;
    return _in;
}
template<class T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) {
    if (_v.empty()) { return _out; }
    _out << *_v.begin();
    for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline istream &operator>> (istream &_in, vector<T> &_v) {
    for (auto &_i : _v) { _in >> _i; }
    return _in;
}
template<class T> inline ostream &operator<< (ostream &_out, const set<T> &_s) {
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) {
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) {
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) {
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T, class U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) {
    if (_m.empty()) { return _out; }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}
template<class T, class U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) {
    if (_m.empty()) { return _out; }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}

template<class T, size_t N> inline ostream &operator<< (ostream &_out, const array<T, N> &a) {
    for(int i = 0; i < N; ++i) {
        _out << a[i];
        if(i + 1 < N) {
            _out << ' ';
        }
    }
    return _out;
}
template<class T, size_t N> inline istream &operator>> (istream &_in, array<T, N> &a) {
    for(int i = 0; i < N; ++i) {
        _in >> a[i];
    }
    return _in;
}