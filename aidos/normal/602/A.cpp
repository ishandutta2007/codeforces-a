#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e3 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, k;
int s;
ll read() {
    ll base;
    cin >> n >> base;
    ll val = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        val = val * base + x;
    }
    return val;
}
void solve() {
    ll a = read();
    ll b = read();
    if(a < b) cout << "<";
    else if(a == b) cout << "=";
    else cout << ">";
}


int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}