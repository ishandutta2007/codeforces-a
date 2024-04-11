#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <vector <int>> a(n, vector <int> (n));
    forn (i, 0, n)
        forn (j, 0, n) 
            cin >> a[i][j];
    ll first = sqrt(1LL * a[0][1] * a[0][2] / a[1][2]);
    cout << first << " ";
    forn (i, 1, n)
        cout << a[i][0] / first  << " ";
    return 0;
}