#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int j = 1; j <= n; j++) {
        for(int x = a[j]; x <= 2 * n; x+=a[j]) {
            int i = x - j;
            if(i >= 1 && i < j) {
                if(x/a[j] == a[i]) ans++;
            }
        }
    }
    cout<<ans<<"\n";
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