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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, k, ans, A[MAXN], dist[2][MAXN], pm[MAXN];
vector<ll> adj[MAXN];
vector<pll> v1, v2;
set<pll, greater<pll>> st;

void BFS(ll ind, ll v) {
    fill(dist[ind], dist[ind] + MAXN, INF);
    queue<ll> q;
    dist[ind][v] = 0;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (ll u : adj[v]) {
            if (dist[ind][u] == INF) {
                dist[ind][u] = dist[ind][v] + 1;
                q.push(u);
            }
        }
    }
}

ll check(ll x) {
    st = {};
    ll r = k - 1;
    for (ll i = 0; i < k; i++) {
        //ll ind = lower_bound(all(v2) , pll(x - v1[i].X - 1 , -INF)) - v2.begin();
        while (r >= 0 && v1[i].X + v2[r].X + 1 >= x) {
            st.insert({dist[0][v2[r].Y], v2[r].Y});
            r--;
        }
        if (SZ(st) == 0) continue;
        //if(dist[1][v1[i].Y] + pm[ind] + 1 >= x) return 1;
        pll A = (*st.begin());
        if (A.Y != v1[i].Y && A.X + dist[1][v1[i].Y] + 1 >= x) return 1;
        if (SZ(st) == 1) continue;
        auto it = st.begin();
        it++;
        A = *it;
        if (A.Y != v1[i].Y && A.X + dist[1][v1[i].Y] + 1 >= x) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (ll i = 1; i <= k; i++) cin >> A[i];
    for (ll i = 1; i <= m; i++) {
        ll v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    BFS(0, 1);
    BFS(1, n);

    for (ll i = 1; i <= k; i++) v1.push_back({dist[0][A[i]], A[i]});
    for (ll i = 1; i <= k; i++) v2.push_back({dist[1][A[i]], A[i]});
    Sort(v1);
    Sort(v2);
    for (ll i = k - 1; i >= 0; i--) pm[i] = max(pm[i + 1], dist[0][v2[i].Y]);

    /*for(ll i = 0 ; i <= k ; i++)    cout << pm[i] << sep;
    cout << endl;
    for(ll i = 1 ; i <= n ; i++)    cout << dist[0][i] << sep;
    cout << endl;
    for(ll i = 1 ; i <= n ; i++)    cout << dist[1][i] << sep;
    cout << endl;*/

    ll l = 0, r = MAXN;
    while (r - l > 1) {
        ll mid = l + r >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    //cout << l << endl;
    cout << min(dist[0][n], l) << endl;

    return 0;
}
/*

*/