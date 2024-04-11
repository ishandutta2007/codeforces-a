#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 1e6 + 10;

ll a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    ll n, s;
    cin >> n >> s;
    fr(i, n)
        cin >> a[i];

    ll tl = 0, tr = n + 1; ///Ch
    while (tr - tl > 1) {
        ll tm = (tl + tr) / 2;
        fr(i, n)
            b[i] = a[i] + (i + 1) * tm;
        sort(b, b + n);
        ll sum1 = 0;
        fr(i, tm)
            sum1 += b[i];
        if (sum1 > s)
            tr = tm;
        else
            tl = tm;
    }
    cout << tl << " ";

    fr(i, n)
        b[i] = a[i] + (i + 1) * tl;
    sort(b, b + n);
    ll sum1 = 0;
    fr(i, tl)
        sum1 += b[i];
    cout << sum1;
}