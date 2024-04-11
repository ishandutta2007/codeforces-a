#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e3 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
string s;
ll dp[maxn][maxn];
ll get(int i, int j) {
    if(i < j) return 0;
    if(j < 0) return 0;
    if(i == 0) {
        return 1;
    }
    ll &res = dp[i][j];
    if(res != -1) return res;
    res = (get(i-1, j - 1) + get(i - 1, j + 1)) % mod;
    return res;
}
void solve() {
    cin >> n >> k >> s;
    int a = 0, b = 0;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') a++;
        else {
            if(a == 0) b++;
            else a--;
        }
    }
    n -= k;
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = b; j <= i; j++) {
            ans = (ans + get(i, j) * get(n-i, j - b + a)) % mod;
        }
    }
    cout << ans << "\n";
}


int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}