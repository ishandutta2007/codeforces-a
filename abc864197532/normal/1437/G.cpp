#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 18, K = 500, C = 1 << 20;

vector <int> adj[N];
int vic_id[N], cur[N]{}, sz[N]{}, pt[N]{}, hld_id[N]{}, hd[N]{}, p[N]{};
int _id = 0;
multiset <int> vic[N];


void dfs(int v, int pa) {
    p[v] = pa;
    sz[v] = 1;
    pt[v] = -1;
    for (int u : adj[v]) if (u ^ pa) {
        dfs(u, v);
        sz[v] += sz[u];
        if (pt[v] == -1 || sz[pt[v]] < sz[u]) pt[v] = u;
    }
}

void hld(int v, int pa, int h) {
    if (v == -1) return;
    hld_id[v] = _id++;
    hd[v] = h;
    hld(pt[v], v, h);
    for (int u : adj[v]) if (u != pa && u != pt[v]) {
        hld(u, v, u);
    }
}

struct Seg {
    int l, r, m;
    int sum;
    Seg* ch[2];
    Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
        sum = 0;
        if (r - l != 1) {
            ch[0] = new Seg (l, m);
            ch[1] = new Seg (m, r);
            pull();
        }
    }
    void pull() {sum = max(ch[0]->sum, ch[1]->sum);}
    void set(int p, int v) {
        if (r - l == 1) {
            sum = v;
        } else {
            if (p < m) ch[0]->set(p, v);
            else ch[1]->set(p, v);
            pull();
        }
    }
    int query(int a, int b) {
        if (a <= l and r <= b) return sum;
        int ans = -1 << 30;
        if (a < m) ans = max(ans, ch[0]->query(a, b));
        if (m < b) ans = max(ans, ch[1]->query(a, b));
        return ans;
    }
} root(0, 2 * N);

int Query(int v) {
    int ans = 0;
    while (hd[v]) {
        int l = hld_id[hd[v]], r = hld_id[v];
        if (l > r) swap(l, r);
        ans = max(ans, root.query(l, r + 1));
        v = p[hd[v]];
    }
    return max(ans, root.query(0, hld_id[v] + 1));
}

void Mo(int v, int x) {
    vic[vic_id[v]].erase(vic[vic_id[v]].lower_bound(cur[v]));
    cur[v] = x;
    vic[vic_id[v]].insert(cur[v]);
    root.set(hld_id[vic_id[v]], *(--vic[vic_id[v]].end()));
}

struct AC {
    vector <vector <int>> ch;
    vector <int> cnt, f;
    AC () {extend();}
    void extend() {
        ch.pb(vector <int>(26, 0));
        cnt.pb(0);
    }
    int next(int u, int v) {
        if (!ch[u][v]) {
            ch[u][v] = ch.size();
            extend();
        }
        return ch[u][v];
    }
    void insert(string &s, int id) {
        int now = 0;
        for (char c : s) {
            now = next(now, c - 'a');
        }
        cnt[now]++;
        vic_id[id] = now;
    }
    void build_fail() {
        f.assign(ch.size(), 0);
        queue <int> q;
        for (int i = 0; i < 26; ++i) if (ch[0][i]) {
            q.push(ch[0][i]);
            adj[0].pb(ch[0][i]);
        }
        while (q.size()) {
            int v = q.front(); q.pop();
            for (int i = 0; i < 26; ++i) if (ch[v][i]) {
                int k = f[v];
                while (k && !ch[k][i]) k = f[k];
                if (ch[k][i]) k = ch[k][i];
                f[ch[v][i]] = k;
                cnt[ch[v][i]] += cnt[k];
                adj[k].pb(ch[v][i]);
                q.push(ch[v][i]);
            }
        }
    }
    int match(string &s) {
        int k = 0, ans = -1;
        for (char c : s) {
            while (k && !ch[k][c - 'a']) k = f[k];
            if (ch[k][c - 'a']) k = ch[k][c - 'a'];
            if (cnt[k]) {
                ans = max(ans, Query(k));
            }
        }
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, t, a, b;
    string s;
    cin >> n >> q;
    AC ac;
    fop (i,0,n) {
        cin >> s;
        ac.insert(s, i);
    }
    fop (i,0,n) vic[vic_id[i]].insert(0);
    ac.build_fail();
    dfs(0, -1);
    hld(0, -1, 0);
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            Mo(a - 1, b);
        } else {
            cin >> s;
            cout << ac.match(s) << endl;
        }
    }
}