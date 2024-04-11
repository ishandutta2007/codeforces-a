#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int x, n, m;
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = a[n-1] - a[0];
    for(int i = 1; i < n; i++) {
        ans = min(ans, a[i] - a[i-1]);
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}