#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j;
vector<ll> m;
bool viv = false;

void solve() {
    ll sum;
    cin >> sum;
    ll ost;
    ost = sum % 14;
    if (ost < 1 || ost > 6) {
        cout << "NO\n";
        return;
    }    
    if (sum < 15) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    	solve();

    return 0;
}