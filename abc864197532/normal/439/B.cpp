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
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    int a[n];
    fop (i,0,n) {
        cin >> a[i];
    }
    sort(a, a + n);
    lli ans = 0;
    fop (i,0,n) {
        ans += 1ll * a[i] * k;
        k = max(k - 1, 1);
    }
    cout << ans << endl;
}