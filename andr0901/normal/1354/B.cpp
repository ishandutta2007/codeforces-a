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
    string s;
    cin >> s;
    vector <vector <int>> a(3);
    forn (i, 0, sz(s))
        a[s[i] - '1'].pb(i);
    /*forn (i, 0, 3)
        cout << a[i] << "\n";*/
    int ans = 1e9;
    forn (i, 0, sz(s)) {
        bool ok = true;
        int mx = i;
        forn (j, 0, 3) {
            if (lower_bound(all(a[j]), i) == a[j].end())
                ok = false;
            else
                chkmax(mx, *lower_bound(all(a[j]), i));
        }
        //cout << ok << " " << i << " " << mx << "\n";
        if (ok)
            chkmin(ans, mx - i); 
    }
    if (ans == 1e9)
        cout << "0\n";
    else
        cout << ans + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}