#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1003, INF = 1000000009;

pair<int, int> qry(vector<int> v)
{
    if (v.empty())
    {
        return m_p(-1, INF);
    }
    printf("? %d ", v.size());
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
    fflush(stdout);
    pair<int, int> ans;
    scanf("%d%d", &ans.fi, &ans.se);
    return ans;
}

int n;
vector<int> a[N];

pair<int, int> root;

int d[N];
int tin[N], tout[N], ti;

void dfs0(int x, int p)
{
    tin[x] = ++ti;
    if (x == p)
        d[x] = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        d[h] = d[x] + 1;
        dfs0(h, x);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        a[i].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    root = qry(v);
    dfs0(root.fi, root.fi);
    pair<int, int> g1;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        v.clear();
        for (int x = 1; x <= n; ++x)
        {
            if (d[x] >= m)
                v.push_back(x);
        }
        pair<int, int> qm = qry(v);
        if (qm.se != root.se)
        {
            r = m - 1;
        }
        else
        {
            g1 = qm;
            l = m + 1;
        }
    }
    int d2 = root.se - d[g1.fi];
    v.clear();
    for (int x = 1; x <= n; ++x)
    {
        if (d[x] == d2)
            v.push_back(x);
    }
    pair<int, int> g2 = qry(v);
    if (g2 != root)
    {
        if (isp(g2.fi, g1.fi))
        {
            v.clear();
            for (int x = 1; x <= n; ++x)
            {
                if (x == g2.fi)
                    continue;
                if (d[x] == d2)
                    v.push_back(x);
            }
            g2 = qry(v);
        }
    }
    printf("! %d %d\n", g1.fi, g2.fi);
    fflush(stdout);
    char comeon[20];
    scanf(" %s", comeon);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}