#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

string s;
int n;

int main()
{
    FAST;
    cin >> s;
    n = s.size();
    int l = -1;
    ll ans = 0;
    Loop(i,0,n)
    {
        for(int k = 1; i - 2*k > l; ++k)
        {
            if(s[i] == s[i-k] && s[i] == s[i-2*k])
            {
                l = i-2*k;
                break;
            }
        }
        ans += l+1;
    }
    cout << ans << '\n';
}