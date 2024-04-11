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
const int N = 200005;

int n;
char a[N];

void solv()
{
    cin >> n;
    cin >> a;
    n *= 2;

    stack<int> s;
    stack<bool> c;
    c.push(false);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '(')
        {
            if (!c.top())
            {
                ++ans;
                c.pop();
                c.push(true);
            }
            s.push(i);
            c.push(false);
        }
        else
        {
            s.pop();
            c.pop();
        }
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