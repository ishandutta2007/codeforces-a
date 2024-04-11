#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[301][5];

ll get(ll x, ll xe, ll l, ll r){
    if(v[x][xe].empty())return 0;
    return upper_bound(all(v[x][xe]), r) - lower_bound(all(v[x][xe]), l);
}

ll kek[301];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    kek['R'] = 0;
    kek['G'] = 1;
    kek['B'] = 2;

    while(t--){
        ll n, k;
        cin >> n >> k;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)v[i][j].clear();
        string s;
        cin >> s;
        for(int i = 0; i < n; i++){
            v[i % 3][kek[s[i]]].p_b(i);
        }

        ll ans = 1e18;

        for(int i = 0; i < n; i++){
            if(i + k > n)break;
            ll l = i, r = i + k - 1;
            for(int j = 0; j < 3; j++){
                ll sc = k;
                sc -= get(i % 3, j, l, r);
                sc -= get((i + 1) % 3, (j + 1) % 3, l, r);
                sc -= get((i + 2) % 3, (j + 2) % 3, l, r);
                ans = min(ans, sc);
            }
        }

        cout << ans << "\n";

    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}