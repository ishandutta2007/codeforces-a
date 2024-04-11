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

void solv()
{
    int n, m;
    int q[30] = {};

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        for (int j = 0; j < m; ++j)
        {
            if ((x & (1 << j)))
                ++q[j];
        }
    }

    int ans = 0;
    for (int j = 0; j < m; ++j)
    {
        if (q[j] > n - q[j])
            ans |= (1 << j);
    }

    cout << ans << "\n";
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