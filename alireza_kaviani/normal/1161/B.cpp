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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

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
#define file_io                     freopen("in.txt" , "r" , stdin) ; freopen("out.txt" , "w" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , v , u;
vector<pll> E;
map<pll , ll> isEdge;

ll can(ll x){
    if(x == n)  return 0;
    vector<pll> vec;
    for(pll i : E){
        v = (i.X + x) % n;
        u = (i.Y + x) % n;
        if(v > u)   swap(v , u);
        vec.push_back({v , u});
        if(!isEdge[{v , u}])    return 0;
    }
    return 1;
}

int main() {
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++){
        cin >> v >> u;
        v--; u--;
        if(v > u)   swap(v , u);
        E.push_back({v , u});
        isEdge[{v , u}] = 1;
    }

    for(ll i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            if(can(i) || can(n / i)){
                return cout << "Yes" << endl , 0;
            }
        }
    }
    cout << "No" << endl;

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