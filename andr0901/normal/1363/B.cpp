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
    vector <int> suf(sz(s) + 1);
    for (int i = sz(s) - 1; i >= 0; --i)
        suf[i] = suf[i + 1] + (s[i] == '1');
    int ans = 1e9, cnt = 0;
    forn (i, 0, sz(s)) {
        chkmin(ans, cnt + suf[i]);
        cnt += (s[i] == '0');
    }
    forn (i, 0, sz(s)) {
        if (s[i] == '0')
            s[i] = '1';
        else
            s[i] = '0';
    }
    for (int i = sz(s) - 1; i >= 0; --i)
        suf[i] = suf[i + 1] + (s[i] == '1');
    cnt = 0;
    forn (i, 0, sz(s)) {
        chkmin(ans, cnt + suf[i]);
        cnt += (s[i] == '0');
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}