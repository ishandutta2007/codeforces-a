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

constexpr int W = 2e5 + 5;

bool knapsack(const vector<int>& a) {
    bitset<W> mask;
    mask[0] = 1;
    forn (i, 0, a.size()) {
        mask |= (mask << a[i]);
    }
    int s = accumulate(all(a), 0);
    if (s % 2) {
        return false;
    }
    forn (i, 0, 20) {
        cerr << i << ": " << mask[i] << "\n";
    }
    return mask[s / 2];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    bool can = knapsack(a);
    if (!can) {
        cout << "0\n";
        return 0;
    }
    while (true) {
        forn (i, 0, n) {
            if (a[i] % 2) {
                cout << "1\n" << i + 1 << "\n";
                return 0;
            }
        }
        forn (i, 0, n) {
            a[i] /= 2;
        }
    }
    return 0;
}