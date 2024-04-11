#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 1000087, logN = 17, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));
    vector <int> pre(5000, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pre[a[j] - a[i]]++;
        }
    }
    vector <int> cnt = pre;
    int alround = n * (n - 1) / 2;
    for (int i = 1; i < 5000; ++i) pre[i] += pre[i - 1];
    lli ans = 0;
    for (int i = 1; i < 5000; ++i) {
        for (int j = 1; i + j < 5000; ++j) {
            ans += 1ll * cnt[i] * cnt[j] * (alround - pre[i + j]);
        }
    }
    cout << fixed << setprecision(10) << double(ans) / alround / alround / alround << endl;
}