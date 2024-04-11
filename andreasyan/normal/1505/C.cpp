#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

void solv()
{
    string s;
    cin >> s;
    /*for (int i = 0; i < sz(s); ++i)
    {
        cout << s[i] - 'A' << "\n";
    }
    return;*/
    for (int i = 2; i < sz(s); ++i)
    {
        if ((s[i] - 'A') % 2 != (s[i - 1] - 'A' + s[i - 2] - 'A') % 2)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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