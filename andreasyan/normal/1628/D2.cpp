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
const int N = 2000006;
const int M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int f[N], rf[N];
int ast2[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;

    ast2[0] = 1;
    for (int i = 1; i < N; ++i)
        ast2[i] = (ast2[i - 1] * 2) % M;
}

int C(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return (f[n] * 1LL * rf[k]) % M * rf[n - k] % M;
}

void solv()
{
    int n, m, k;
    cin >> n >> m >> k;
    m = n - m;

    int ans = 0;
    if (m == 0)
        ans = (n * 1LL * ast2[n - 1]) % M;
    else
    {
        for (int i = n - m, j = 0; i >= 1; --i, ++j)
        {
            ans = (ans + (C(n - i - 1, j) * 1LL * ast2[i - 1]) % M * i) % M;
        }
    }

    ans = (ans * 1LL * k) % M;
    ans = (ans * 1LL * ast(ast2[n - 1], M - 2)) % M;
    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}