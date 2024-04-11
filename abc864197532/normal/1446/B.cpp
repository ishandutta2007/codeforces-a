#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 18, K = 500, C = 1 << 20;

int dp[5001][5001];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    int ans = 0;
    fop (i,0,n) fop (j,0,m) {
        if (s[i] == t[j]) {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
        } else {
            dp[i + 1][j + 1] = max({dp[i + 1][j + 1], dp[i][j + 1] - 1, dp[i + 1][j] - 1});
        }
        ans = max(ans, dp[i + 1][j + 1]);
    }
    cout << ans << endl;
    
}