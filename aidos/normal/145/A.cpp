#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, m, k;
string s, t;
void solve() {
    cin >> s >> t;
    n = s.size();
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == t[i]) continue;
        if(s[i] == '4')x++;
        else y++;
    }
    cout << max(x, y) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}