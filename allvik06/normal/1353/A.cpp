#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n == 1) cout << 0 << "\n";
        else if (n == 2) cout << m << "\n";
        else cout << 2 * m << "\n";
    }
}