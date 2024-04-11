#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

void solve()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    Loop(i,0,500)
    {
        int x = rand()&1 ? a[rand()%3]: 1;
        int y = rand()&1 ? a[rand()%3]: 1;
        int z = rand()&1 ? a[rand()%3]: 1;
        if(a[0] == max(x, y) &&
           a[1] == max(x, z) &&
           a[2] == max(y, z)   )
        {
            cout << "YES\n" << x << ' ' << y << ' ' << z << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}