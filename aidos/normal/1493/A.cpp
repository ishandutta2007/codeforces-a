#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    cin >> n >> k;
    vector<int> a;
    for(int i = (k + 1)/2; i<= n; i++) {
        if(i == k) continue;
        a.push_back(i);
    }
    cout << a.size() << "\n";
    for(int x: a) cout << x << " ";
    cout << "\n";
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