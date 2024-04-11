#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
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

int gcd(int a, int b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 1e9;
    vector <int> d;
    forn (y, 1, 2e4 + 1) {
        for (int i = 1; i * i <= y; ++i) {
            if (y % i == 0) {
                int x, g, z;
                x = i;
                g = lcm(x, y);
                z = (c / g) * g;
                if (z && abs(x - a) + abs(y - b) + abs(z - c) < ans) {
                    ans = abs(x - a) + abs(y - b) + abs(z - c);
                    d = {x, y, z};
                }

                z = ((c + g - 1) / g) * g;
                if (z && abs(x - a) + abs(y - b) + abs(z - c) < ans) {
                    ans = abs(x - a) + abs(y - b) + abs(z - c);
                    d = {x, y, z};
                }


                x = y / i;
                g = lcm(x, y);
                z = (c / g) * g;
                if (z && abs(x - a) + abs(y - b) + abs(z - c) < ans) {
                    ans = abs(x - a) + abs(y - b) + abs(z - c);
                    d = {x, y, z};
                }

                z = ((c + g - 1) / g) * g;
                if (z && abs(x - a) + abs(y - b) + abs(z - c) < ans) {
                    ans = abs(x - a) + abs(y - b) + abs(z - c);
                    d = {x, y, z};
                }

            }
        }
    }
    cout << ans << "\n";
    for (int i : d)
        cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}