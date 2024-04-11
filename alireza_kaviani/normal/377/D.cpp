/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, L[MAXN], V[MAXN], R[MAXN];
vector<ll> vec[MAXN];
set<pll> st;
pair<pair<int, int>, int> ans;
pair<int, int> seg[MAXN << 2];
int lz[MAXN << 2];

void build(int id = 1, int l = 0, int r = MAXN) {
    seg[id].Y = l;
    if (r - l == 1) return;
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid, r);
}

void shift(int id) {
    lz[id << 1] += lz[id];
    lz[id << 1 | 1] += lz[id];
    seg[id << 1].X += lz[id];
    seg[id << 1 | 1].X += lz[id];
    lz[id] = 0;
}

void update(int ql, int qr, int x, int id = 1, int l = 0, int r = MAXN) {
    if (r <= ql || qr <= l) return;
    if (ql <= l && r <= qr) {
        lz[id] += x;
        seg[id].X += x;
        return;
    }
    shift(id);
    int mid = l + r >> 1;
    update(ql, qr, x, id << 1, l, mid);
    update(ql, qr, x, id << 1 | 1, mid, r);
    seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> L[i] >> V[i] >> R[i];
        vec[V[i]].push_back(i);
    }

    build();
    for (ll i = 0; i < MAXN; i++) {
        while (SZ(st) && (*st.begin()).X < i) {
            pll A = *st.begin();
            update(L[A.Y], V[A.Y] + 1, -1);
            st.erase(st.begin());
        }
        for (ll j : vec[i]) {
            update(L[j], V[j] + 1, 1);
            st.insert({R[j], j});
        }
        ans = max(ans, pair<pair<int, int>, int>(seg[1], i));
    }

    vector<ll> Ans;
    for (ll i = 1; i <= n; i++) {
        if (L[i] <= ans.X.Y && ans.X.Y <= V[i] && V[i] <= ans.Y && ans.Y <= R[i]) Ans.push_back(i);
    }
    cout << Ans.size() << endl;
    for (ll i : Ans) cout << i << sep;

    return 0;
}
/*

*/