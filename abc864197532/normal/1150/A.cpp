#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 1001, logN = 18;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, r, mn = 1 << 30, mx = 0, x;
    cin >> n >> m >> r;
    for (int i = 0; i < n; ++i) cin >> x, mn = min(mn, x);
    for (int i = 0; i < m; ++i) cin >> x, mx = max(mx, x);
    if (mn < mx) {
        int ad = r / mn;
        cout << r % mn + ad * mx << endl;
    } else {
        cout << r << endl;
    }
}