#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 1e3;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;

ll a[N];

int main() {
    //freopen("sweets.in", "r", stdin);
    ll ans = 0;
    string s;
    cin >> s;
    fr(i, (int)s.size() - 1)
        if ((10 * (s[i] - '0') + s[i + 1] - '0') % 4 == 0)
            ans += i + 1;
    fr(i, s.size())
        if (s[i] == '0' || s[i] == '4' || s[i] == '8')
            ans++;
    cout << ans;
}