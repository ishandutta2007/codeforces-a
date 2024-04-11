#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e5 + 2;
const ld EPS = 1e-8;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    frab(i, 2, 2 * (1 << n)) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = n; i >= 1; i--)
        for (int j = (1 << i); j < (1 << i) * 2 - 1; j += 2) {
            int mx = max(a[j], a[j + 1]);
            ans += mx - min(a[j], a[j + 1]);
            a[j] = a[j + 1] = mx;
            a[j / 2] += a[j + 1];
        }
    cout << ans;
}