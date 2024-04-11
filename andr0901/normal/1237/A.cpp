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

int get(int x) {
    if (x > 0)
        return x / 2;
    else
        return (x - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    bool up = true;
    forn (i, 0, n) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            cout << a[i] / 2 << "\n";
            continue; 
        }
        if (up) {
            cout << get(a[i]);
        } else {
            cout << get(a[i]) + 1;
        }
        up = !up;
        cout << "\n";
    }
    return 0; 
}