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
    int n, m, l, r, t, x;
    cin >> n >> m;
    int aa[n], now[n];
    fop (i,0,n) aa[i] = 864197532, now[i] = 0;
    fop (i,0,m) {
        cin >> l >> r >> t >> x;
        l--;
        fop (j,l,r) {
            if (aa[j] > t) {
                aa[j] = t;
                now[j] = x;
            }
        }
    }
    int ans = 0;
    fop (i,0,n) ans += now[i];
    cout << ans << '\n';
}