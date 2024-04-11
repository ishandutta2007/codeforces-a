#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


ll f[MAXN], last[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;

    vector <ll> a(n + 1), dp(n + 2);

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= n; i++){
        if(!f[a[i]]){
            f[a[i]] = i;
        }
        last[a[i]] = i;
    }

    for(int i = 1; i <= n; i++){
        ll sc = 0, mx = i;
        for(int j = i; j <= n; j++){
            ll x = a[j];
            if(j == f[x]){
                sc ^= x;
                mx = max(mx, last[x]);
            }else{
                if(f[x] < i)break;
            }

            if(mx == j)dp[j] = max(dp[j], dp[i - 1] + sc);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << *max_element(all(dp)) << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}