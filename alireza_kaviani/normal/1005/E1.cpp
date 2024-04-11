/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll Sqrt(ll x, ll y) {
    ll t = pow(x, 1. / y);
    for (ll i = max(0LL, t - 10); i <= t + 10; i++) {
        if (poww(i, y, ll(8e18)) == x) return i;
    }
    return -1;
}

set_random;

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD1 = 998244353;
const ll MOD2 = 1e9 + 7;
const ll MOD3 = 1e9 + 9;

ll n , m , t , ind , ans , p[MAXN];
map<ll , ll> cntL , cntR;

int main() {
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> p[i];
        if(p[i] == m)   ind = i;
    }

    cntL[0]++;
    cntR[0]++;
    for(ll i = ind - 1 ; i >= 0 ; i--)
    {
        if(p[i] < m)    t++;
        else            t--;
        cntL[t]++;
    }

    t = 0;
    for(ll i = ind + 1 ; i < n ; i++)
    {
        if(p[i] < m)    t++;
        else            t--;
        cntR[t]++;
    }

    for(ll i = -MAXN ; i < MAXN ; i++)
    {
        ans += cntL[i] * cntR[-i];
        ans += cntL[i] * cntR[-i - 1];
    }
    cout << ans << endl;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/