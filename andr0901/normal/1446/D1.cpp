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

constexpr int M = 105;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    vector <int> cnt(M);
    forn (i, 0, n)
        cnt[a[i]]++;
    int ans = 0;
    int x = max_element(all(cnt)) - cnt.begin();
    forn (y, 1, M) {
        if (y == x)
            continue;
        unordered_map <int, int> used;
        used[0] = -1;
        int s = 0;
        forn (i, 0, n) {
            if (a[i] == x)
                ++s;
            if (a[i] == y)
                --s;
            if (used.find(s) != used.end())
                chkmax(ans, i - used[s]);
            else
                used[s] = i;
        }
        if (y < 5)  
            cerr << ans << " ";
    }
    cout << ans;
    return 0;
}