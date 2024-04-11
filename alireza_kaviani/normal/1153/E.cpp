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
//#define endl                        '\n'
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

ll n , cntRow[MAXN] , cntCol[MAXN];
vector<ll> row , col;
vector<pll> ans;

int main() {
    fast_io;

    cin >> n;
    for(ll i = 1 ; i <= n ; i++){
        cout << "? 1 1 " << i << sep << n << endl;
        cout.flush();
        cin >> cntRow[i];
        cout << "? 1 1 " << n << sep << i << endl;
        cout.flush();
        cin >> cntCol[i];
    }

    for(ll i = n ; i >= 1 ; i--){
        cntRow[i] += cntRow[i - 1];
        cntCol[i] += cntCol[i - 1];
    }

    for(ll i = 1 ; i <= n ; i++){
        if(cntRow[i] & 1){
            row.push_back(i);
        }
        if(cntCol[i] & 1){
            col.push_back(i);
        }
    }

    if(col.size() && row.size()){
        for(ll i : row){
            for(ll j : col){
                cout << "? " << i << sep << j << sep << i << sep << j << endl;
                cout.flush();
                ll x;
                cin >> x;
                if(x == 1){
                    ans.push_back({i , j});
                }
            }
        }
    }

    if(col.size() && row.size() == 0){
        ll l = 0 , r = n + 1;
        while(r - l > 1){
            ll mid = (l + r) / 2;
            cout << "? 1 " << col[0] << sep << mid << sep << col[0] << endl;
            cout.flush();
            ll x;
            cin >> x;
            if(x & 1)   r = mid;
            else    l = mid;
        }
        ans.push_back({r , col[0]});
        ans.push_back({r , col[1]});
    }

    if(row.size() && col.size() == 0){
        ll l = 0 , r = n + 1;
        while(r - l > 1){
            ll mid = (l + r) / 2;
            cout << "? " << row[0] << sep << "1 " << row[0] << sep << mid << endl;
            cout.flush();
            ll x;
            cin >> x;
            if(x & 1)   r = mid;
            else    l = mid;
        }
        ans.push_back({row[0] , r});
        ans.push_back({row[1] , r});
    }

    cout << "! ";
    for(pll i : ans){
        cout << i.X << sep << i.Y << sep;
    }
    cout << endl;
    cout.flush();

    return 0;
}
/*

*/