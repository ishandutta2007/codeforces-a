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
const int N = 100005;

int n;
char a[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", a);
    bool u = false;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != '0')
        {
            for (int j = i; j < n; ++j)
            {
                if (a[j] == '0')
                {
                    u = true;
                    break;
                }
            }
            break;
        }
        putchar(a[i]);
    }
    if (u)
        putchar('0');
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] != '1')
            break;
        putchar(a[i]);
    }
    putchar('\n');
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
    {
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}