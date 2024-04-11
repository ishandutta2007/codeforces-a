#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 2e5 + 10;
const int mod = 998244353;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n;
string s;
void solve() {
    cin >> n >> s;
    int l = 0, r = 0, bal = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') bal++;
        else bal--;
        if(bal < 0) {
            l--;
            bal = 0;
        }
    }
    bal = 0;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == ')') bal++;
        else bal--;
        if(bal < 0) {
            bal = 0;
            r--;
        }
    }
    if(l == r && l>= -1) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }
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