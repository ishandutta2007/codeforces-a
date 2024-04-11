#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ld EPS = 1e-9;

int a[N], c[N];
vector <int> b;

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while (n > 0 && m > 0 && n + m >= 3) {
        if (n > m)
            n -= 2, m--, ans++;
        else
            n--, m -= 2, ans++;
    }
    cout << ans;
}