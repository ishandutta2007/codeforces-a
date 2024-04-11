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
const int N = 202;

int n, k;
int x[N], y[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);

    for (int i = 1; i <= n; ++i)
    {
        bool z = true;
        for (int j = 1; j <= n; ++j)
        {
            if (!(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k))
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            printf("1\n");
            return;
        }
    }
    printf("-1\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}