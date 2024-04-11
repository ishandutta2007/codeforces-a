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

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n), w(k);
    cin >> a >> w;
    sort(rall(a));
    int i = 0;
    int cnt_ones = 0;
    vector <int> non_ones;
    for (int x : w) {
        if (x == 1)
            cnt_ones++;
        else
            non_ones.pb(x);
    }
    long long ans = 0;
    for (; i < cnt_ones; ++i)
        ans += 2 * a[i];
    sort(rall(non_ones));
    int l = i, r = n - 1;
    for (int x : non_ones) {
            ans += a[l];
            ++l;
            ans += a[r];
            r -= x - 1;
        cerr << ans << "\n";
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