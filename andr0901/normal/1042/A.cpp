#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset <int> a, b;
    forn (i, 0, n) {
        int t;
        cin >> t;
        a.insert(t), b.insert(t);
    }
    forn (i, 0, m) {
        int t = *a.begin();
        a.erase(a.begin());
        a.insert(t + 1);
    }
    cout << *a.rbegin() << " ";
    forn (i, 0, m) {
        int t = *(--b.end());
        b.erase((--b.end()));
        b.insert(t + 1);
    }
    cout << *b.rbegin();
    return 0;
}