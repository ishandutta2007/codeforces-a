#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n;
int a[maxn];
void solve(){
    string s, t;
    cin >>n >> s;
    t = s;
    sort(t.begin(), t.end());
    int ans = 0;
    for(int i = 0; i < n; i++) if(s[i] != t[i]) ans++;
    cout << ans << "\n";
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}