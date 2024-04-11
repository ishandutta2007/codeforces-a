#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    lli al = accumulate(all(a), 0ll);
    if (al & 1) return cout << "NO\n", 0;
    al >>= 1;
    set <lli> s;
    s.insert(0);
    lli pre = 0;
    for (int i = 0; i < n; ++i) {
        pre += a[i];
        s.insert(a[i]);
        if (s.count(pre - al)) {
            cout << "YES\n";
            return 0;
        }
    }
    s.clear();
    s.insert(0);
    pre = 0;
    for (int i = n - 1; i >= 0; --i) {
        pre += a[i];
        s.insert(a[i]);
        if (s.count(pre - al)) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}