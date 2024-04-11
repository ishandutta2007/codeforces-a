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

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

void solve() {
    int h, c, t;
    cin >> h >> c >> t;
    auto get = [&](int k) -> ld {
        return abs((((ld)k + 1) * h + ((ld)k) * c) / (2 * k + 1) - t); 
    };
    int l = 0, r = 1e9;
    while (r - l > 2) {
        int m1 = l + (r - l) / 3, m2 = l + 2 * (r - l) / 3;
        if (get(m1) < get(m2))
            r = m2;
        else
            l = m1;
    }
    /*cout << get(3) << "\n";
    cout << l << " " << r << ": ";*/
    ld ans = 1e9;
    int idx;
    forn (i, l, r + 1) {
        if (get(i) < ans) {
            ans = get(i);
            idx = i;
        }
    }
    //cout << ans << " ";
    if (abs((h + c) / 2.0 - t) < ans)
        cout << 2;
    else
        cout << 2 * idx + 1;
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