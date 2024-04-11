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
const int N = 100005, M = 998244353;

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
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;
}

int C(int n, int k)
{
    return ((f[n] * 1LL * rf[k]) % M * 1LL * rf[n - k]) % M;
}

int n;
char a[N];

void solv()
{
    cin >> n;
    cin >> (a + 1);

    int q = 0;
    int qk = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == '1')
            ++q;
        else
        {
            qk += (q % 2);
            q = 0;
        }
    }
    qk += (q % 2);
    q = 0;

    for (int i = 1; i <= n; ++i)
        q += (a[i] - '0');

    cout << C(n - q + (q - qk) / 2, (q - qk) / 2) << "\n";
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