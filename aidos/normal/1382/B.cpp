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
    int ok = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(!ok) {
            ok = 1;
        } else if(a[i] > 1) {
            ok = 1;
        } else {
            ok = 0;
        }
    }
    if(ok) cout << "First\n";
    else cout << "Second\n";
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