#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 3e5 + 20;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    int mn = INF;
    fr(i, n - 1)
        mn = min(mn, a[i + 1] - a[i]);
    int cnt = 0;
    fr(i, n - 1)
        if (a[i + 1] - a[i] == mn)
            cnt++;
    cout << mn << " " << cnt;
}