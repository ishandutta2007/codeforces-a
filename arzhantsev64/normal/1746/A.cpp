#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] == 1)
            ans = 1;
    }
    cout << (ans == 1 ? "YES\n" : "NO\n");
}


signed main() {
    initIO();
    
    int t;
    cin >> t;
    while (t--)
        solve();
}