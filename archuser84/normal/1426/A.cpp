#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

int solve()
{
    int n;
    int x;
    cin >> n >> x;
    if(n <= 2)
        Kill(1);
    n-=2;
    cout << n/x + bool(n%x) + 1 << '\n';
    return 0;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        solve();
}