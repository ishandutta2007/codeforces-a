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
const int N = 300005;

int n, qq, M;
int a[N];

int f[N];

int q;
int u[N];
void ave(int x, int y)
{
    if (!(1 <= x && x <= n))
        return;

    if (u[x] == 0)
        ++q;
    u[x] = (u[x] + y) % M;
    if (u[x] == 0)
        --q;
}

void solv()
{
    cin >> n >> qq >> M;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[i] = (a[i] - x) % M;
    }

    f[1] = f[2] = 1;
    for (int i = 3; i <= n + 3; ++i)
    {
        f[i] = (f[i - 1] + f[i - 2]) % M;
    }

    for (int i = 1; i <= n; ++i)
    {
        ave(i, a[i]);
        ave(i + 1, -a[i]);
        ave(i + 2, -a[i]);
    }

    while (qq--)
    {
        char ty;
        int l, r;
        cin >> ty >> l >> r;

        if (ty == 'A')
        {
            ave(l, f[1]);
            ave(r + 1, -f[r - l + 2]);
            ave(r + 2, -f[r - l + 1]);
        }
        else
        {
            ave(l, -f[1]);
            ave(r + 1, f[r - l + 2]);
            ave(r + 2, f[r - l + 1]);
        }

        if (!q)
            cout << "YES\n";
        else
            cout << "NO\n";
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}