#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
const int mod = 1e9 + 7, x = 864197532, N = 200008, logN = 18, K = 600, C = 100, M = 1e9;

lli cnt[9], w, ans = 0;

void solve(int now, lli cur) {
    if (now == 1) {
        ans = max(ans, min(w, cur + cnt[now]));
        return;
    }
    lli k = min(cnt[now], (w - cur) / now);
    for (int t = 0; t < 8; ++t) {
        if (k < 0) break;
        solve(now - 1, cur + k * now);
        k--;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    fop (i,1,9) cin >> cnt[i];
    solve(8, 0);
    cout << ans << endl;
}