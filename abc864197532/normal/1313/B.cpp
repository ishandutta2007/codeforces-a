#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    cout << max(1, min(n, x + y - n + 1)) << ' ' << min(n, x + y - 1) << endl;
}

int main () {
    int t, a, b, c;
    cin >> t;
    while (t--) {
        solve();
    }
}