#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

class SegTree{
private: 
    int n;
    vector <int> tr, to_add;
    int neutral_tr = 1e18, neutral_to_add = 0;

    int merge_tr(int a, int b) {
        return min(a, b);
    }

    int merge_to_add(int a, int b) {
        return a + b;
    }

    void build(int v, int vl, int vr, const vector <int>& a) {
        if (vr - vl < 1)
            return;
        if (vr - vl == 1) {
            tr[v] = a[vl];
            return;
        }
        int vm = vl + vr >> 1;
        build(2 * v, vl, vm, a), build(2 * v + 1, vm, vr, a);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    void push(int v, int vl, int vr) {
        if (vr - vl != 1) {
            to_add[2 * v] = merge_to_add(to_add[2 * v], to_add[v]);
            to_add[2 * v + 1] = merge_to_add(to_add[2 * v + 1], to_add[v]);
        }
        tr[v] = merge_to_add(tr[v], to_add[v]);
        to_add[v] = neutral_to_add;
    }

    void upd(int v, int vl, int vr, int l, int r, int x) {
        push(v, vl, vr);
        if (vr <= l || r <= vl) 
            return;
        if (l <= vl && vr <= r) {
            to_add[v] = merge_to_add(to_add[v], x);
            push(v, vl, vr);
            return;
        }
        int vm = vl + vr >> 1;
        upd(2 * v, vl, vm, l, r, x), upd(2 * v + 1, vm, vr, l, r, x);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    int get(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr <= l || r <= vl)
            return neutral_tr;
        if (l <= vl && vr <= r)
            return tr[v];
        int vm = vl + vr >> 1;
        return merge_tr(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }
public: 
    SegTree(const vector <int>& a) {
        n = sz(a);
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
        build(1, 0, n, a);
    }

    SegTree(int _n) {
        n = _n;
        tr.resize(4 * n, neutral_tr), to_add.resize(4 * n, neutral_to_add);
    }

    void upd(int l, int r, int x) {
        upd(1, 0, n, l, r, x);
    }

    int get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};

 main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> where(n);
    forn (i, 0, n) {
        int x;
        cin >> x, x--;
        where[x] = i + 1;
    }
    vector <int> cost(n);
    vector <int> pr(n + 1);
    forn (i, 0, n) {
        cin >> cost[i];
        pr[i + 1] = pr[i] + cost[i];
    }
    SegTree tr(pr);
    int ans = tr.get(1, n);
    /*forn (j, 0, n + 1)
            cout << tr.get(j, j + 1) << " ";
        cout << "\n";*/
    forn (i, 0, n) {
        //cout << where[i] << " ";
        tr.upd(0, where[i], cost[where[i] - 1]);
        tr.upd(where[i], n + 1, -cost[where[i] - 1]);
       /* forn (j, 0, n + 1)
            cout << tr.get(j, j + 1) << " ";
        cout << "\n";*/
        ans = min(ans, tr.get(1, n));
    }
    cout << ans;
    return 0;
}