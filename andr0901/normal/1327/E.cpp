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

const int MOD = 998244353;

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        return x - MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        return x + MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    /*vector <int> ans(5);
    forn (i, 0, 10000) {
        int lst = -1;
        int block_sz = 0;
        int x = i;
        forn (_, 0, 4) {
            int cur = x % 10;
            if (cur != lst && lst != -1) {
                ans[block_sz]++;
                block_sz = 1;
            }  else {
                block_sz++;
            }
            lst = cur;
            x /= 10;
        }
        ans[block_sz]++;
    }
    cout << ans;*/
    vector <int> ans = {10};
    int pow = 10;
    int pref = 10;
    forn (i, 2, n + 1) {
        ans.pb(sub(mul(i, mul(pow, 10)), add(pref, mul(i - 1, pow))));
        pref = add(pref, ans.back());
        pow = mul(pow, 10);
    }
    reverse(all(ans));
    cout << ans;
    return 0;
}