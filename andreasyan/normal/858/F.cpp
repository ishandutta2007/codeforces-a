#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

struct ban
{
    int x, y, z;
};

int n, m;
vector<int> a[N];

vector<ban> ans;

bool c[N];
int tin[N], ti;

bool dfs(int x, int p)
{
    c[x] = true;
    tin[x] = ++ti;
    vector<int> v;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h])
        {
            if (tin[h] > tin[x])
                v.push_back(h);
            continue;
        }
        if (!dfs(h, x))
            v.push_back(h);
    }
    if (v.size() % 2 == 0)
    {
        for (int i = 0; i < v.size(); i += 2)
            ans.push_back({v[i], x, v[i + 1]});
        return false;
    }
    for (int i = 0; i < v.size() - 1; i += 2)
        ans.push_back({v[i], x, v[i + 1]});
    if (x != p)
        ans.push_back({p, x, v.back()});
    return true;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            dfs(i, i);
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}