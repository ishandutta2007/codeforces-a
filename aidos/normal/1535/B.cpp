#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] % 2 != a[j] % 2) {
                ans++;
            } else if(a[i] % 2 == 0) {
                ans++;
            } else if(__gcd(a[i], a[j]) > 1) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}