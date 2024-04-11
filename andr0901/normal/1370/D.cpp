//#pragma GCC optimize("Ofast")
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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    cin >> a;
    auto check = [&](int m) {
        vector <int> less;
        forn (i, 0, n)
            if (a[i] <= m)
                less.pb(i);
        if (less.size() >= k)
            return true;
        if (less.empty())
            return false;
        int ans = 1;
        if (less[0] > 0)
            ans++;
        int lst = less[0];
        forn (i, 1, sz(less)) {
            if (less[i] - lst > 1) {
                ans += 2;
                lst = less[i];
            }
        }
        if (lst < n - 1)
            ans++;
        cerr << m << " " << ans << "\n";
        if (ans >= k)
            return true;
        if (sz(less) == 1)
            return false;
        ans = 1;
        if (less[1] > 0)
            ans++;
        lst = less[1];
        forn (i, 2, sz(less)) {
            if (less[i] - lst > 1) {
                ans += 2;
                lst = less[i];
            }
        }
        if (lst < n - 1)
            ans++;
        cerr << m << " " << ans << "\n";
        if (ans >= k)
            return true;
        return false;
    };
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (check(m))
            r = m;
        else
            l = m;
    }
    cout << r;
    return 0;
}