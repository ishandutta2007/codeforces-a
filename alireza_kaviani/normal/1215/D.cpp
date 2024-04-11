/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, sum1, sum2, cnt1, cnt2;
string s;

void calc(ll s1, ll c1, ll s2, ll c2) {
    if (c1 == 0) {
        if (s2 + c2 / 2 * 9 < s1) {
            cout << "Monocarp" << endl;
            exit(0);
        }
        return;
    }
    c1--;
    s1 += 9;
    ll mn = min(c1, c2);
    c1 -= mn;
    c2 -= mn;

    if (c1 == 0) {
        if (s2 + (c2 + 1) / 2 * 9 < s1) {
            cout << "Monocarp" << endl;
            exit(0);
        }
        return;
    }
    if (s1 + c1 / 2 * 9 > s2) {
        cout << "Monocarp" << endl;
        exit(0);
    }
}

int main() {
    fast_io;

    cin >> n >> s;
    for (ll i = 0; i < n / 2; i++) {
        if (s[i] == '?') cnt1++;
        else sum1 += s[i] - 48;
    }
    for (ll i = n / 2; i < n; i++) {
        if (s[i] == '?') cnt2++;
        else sum2 += s[i] - 48;
    }

    calc(sum1, cnt1, sum2, cnt2);
    calc(sum2, cnt2, sum1, cnt1);
    cout << "Bicarp" << endl;

    return 0;
}
/*

*/