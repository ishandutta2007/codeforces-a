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

ll n , m , t , l , r , p[MAXN];
vector<pll> q , vec;

int main() {
    fast_io;

    cin >> n >> m;
    for(ll i = 1 ; i <= n ; i++)    p[i] = n - i + 1;
    while(m--){
        cin >> t >> l >> r;
        if(t){
            q.push_back({l , r});
        }
        else{
            vec.push_back({l , r});
        }
    }

    Sort(q);
    for(pll i : q){
        for(ll j = i.X ; j <= i.Y ; j++)    p[j] = p[i.X];
    }

    for(pll i : vec){
        ll bad = 1;
        for(ll j = i.X ; j < i.Y ; j++){
            if(p[j] > p[j + 1]) bad = 0;
        }
        if(bad){
            return cout << "NO" << endl , 0;
        }
    }

    cout << "YES" << endl;
    for(ll i = 1 ; i <= n ; i++)    cout << p[i] << sep;

    return 0;
}
/*

*/