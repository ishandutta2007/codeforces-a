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
const int mod = 1e9 + 7, abc = 864197532, N = 800007, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    set <int> s;
    for (int k = 1; k <= 10; ++k) {
        s.insert((1 << k - 1) * ((1 << k) - 1));
    }
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0 && s.count(i)) {
            ans = i;
        }
    }
    cout << ans << endl;
}