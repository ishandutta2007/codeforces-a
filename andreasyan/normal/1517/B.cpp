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
const int N = 102;

int n, m;
deque<int> a[N];

int ans[N][N];

void solv()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
        sort(all(a[i]));
    }

    ll yans = 0;
    for (int jj = 0; jj < m; ++jj)
    {
        int minu = a[1].front();
        for (int i = 1; i <= n; ++i)
        {
            minu = min(minu, a[i].front());
        }
        yans += minu;

        int u;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i].front() == minu)
            {
                u = i;
                break;
            }
        }

        ans[u][jj + 1] = a[u].front();
        a[u].pop_front();
        for (int i = 1; i <= n; ++i)
        {
            if (i == u)
                continue;
            ans[i][jj + 1] = a[i].back();
            a[i].pop_back();
        }
    }

    //cout << yans << "\n";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}