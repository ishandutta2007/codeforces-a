#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

ll gcd(ll a, ll b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll g = 0;
    forn (i, 0, n) {
        ll x;
        cin >> x;
        g = gcd(g, x);
    }
    int cnt = 0;
    for (ll i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            cnt++;
            if (i * i != g)
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}