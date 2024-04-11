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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = s.size();
    for (char t = 'z'; t >= 'a'; --t) {
        forn (i, 0, sz(s)) {
            if (s[i] == t) {
                bool ok = false;
                if (i - 1 >= 0 && s[i - 1] == t - 1)
                    ok = true;
                if (i + 1 < sz(s) && s[i + 1] == t - 1)
                    ok = true;
                if (ok) {
                    s.erase(s.begin() + i);
                    ++t;
                    break;
                }
            }
        }
    }
    cout << ans - (int)s.size();
    return 0;
}