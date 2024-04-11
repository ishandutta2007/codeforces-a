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
const int N = 1000006;

int n, m;
pair<string, int> a[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < m; j += 2)
        {
            a[i].fi[j] = 'A' + 'Z' - a[i].fi[j];
        }
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i)
        cout << a[i].se << ' ';
    cout << "\n";
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
        solv();
    return 0;
}