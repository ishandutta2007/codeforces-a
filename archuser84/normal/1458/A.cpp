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

const int N = 200'010;
ll a[N], b[N];
int n, m;

ll gcd(ll a, ll b){while(b) swap(a=a%b, b); return abs(a);}

int main()
{
    // Hi again
    FAST;
    cin >> n >> m;
    Loop(i,0,n) cin >> a[i];
    Loop(i,0,m) cin >> b[i];
    ll g = 0;
    Loop(i,1,n) g = gcd(g, a[i]-a[0]);
    Loop(i,0,m) cout << gcd(g, a[0]+b[i]) << ' ';
}