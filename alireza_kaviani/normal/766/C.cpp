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

set_random;

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , mxLen , cnt[MAXN] , dp1[MAXN] , dp2[MAXN];
string s;

ll ok(set<ll> st , ll x){
    for(auto &i : st){
        if(x > cnt[i]) return 0;
    }
    return 1;
}

int main() {
    fast_io;
    fill(dp2 , dp2 + MAXN , INF);

    cin >> n >> s;
    for(ll i = 0 ; i < 26 ; i++)   cin >> cnt[i];
    s = "." + s;

    dp1[0] = 1;
    dp2[0] = 0;

    for(ll i = 1 ; i <= n ; i++){
        set<ll> st;
        for(ll j = i ; j >= 1 ; j--){
            st.insert(s[j] - 97);
            if(!ok(st , i - j + 1))    break;
            mxLen = max(mxLen , i - j + 1);
            dp1[i] = (dp1[i] + dp1[j - 1]) % MOD;
            dp2[i] = min(dp2[i] , dp2[j - 1] + 1);
        }
    }
    cout << dp1[n] << endl << mxLen << endl << dp2[n] << endl;

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