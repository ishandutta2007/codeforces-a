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


ll n, i, j, k;
vector<ll> m;
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    sort(m.begin(), m.end());

    vector<ll> add;
    for (ll i = 0; i < k; i++)
        add.push_back(m[i]);
    for (ll i = k; i < n; i++)
        add.push_back(m[i] + add[i - k]);
    for (ll i = 1; i < n; i++)
        add[i] += add[i-1];
    for (auto i : add)
        cout << i << ' ';



    return 0;
}