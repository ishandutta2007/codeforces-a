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
#define pii pair<int,int>
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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector <ll> a(n + 1);
    vector <ll> b(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];

    map <ll, ll> mp;
    map <ll, ll> f;

    for(int i = 1; i <= n; i++){
        mp[a[i]] += b[i];
        f[a[i]]++;
    }

    ll sc = 0, ans = 0;

    for(auto kek : mp){
        if(f[kek.fi] > 1){
            ans += kek.se;
            mp[kek.fi] = 0;
            for(auto i : mp){
                if((kek.fi & i.fi) == i.fi){
                    ans += i.se;
                    mp[i.fi] = 0;
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}