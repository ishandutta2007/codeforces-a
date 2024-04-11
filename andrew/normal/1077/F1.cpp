#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

ll dp[5010][5010], l[MAXN], r[MAXN], mn[MAXN], mx[MAXN];



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, k, m;
    cin >> n >> k >> m;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mn[i] = 1e18;
        mx[i] = -1e18;
    }

    for(int j = 1; j <= n - k + 1; j++){
        l[j] = j;
        r[j] = j + k - 1;
        for(int i = l[j]; i <= r[j]; i++){
            mn[i] = min(mn[i], ll(j));
            mx[i] = max(mx[i], ll(j));
        }
    }

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)dp[i][j] = -1;

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        ll le = l[mn[i] - 1];
        for(int j = 1; j <= m; j++){
            for(int i1 = le; i1 < i; i1++)if(dp[i1][j - 1] != -1){
                dp[i][j] = max(dp[i][j], dp[i1][j - 1] + a[i]);
            }
        }
    }

    ll mxx = n - k + 1;

    ll ans = -1;

    for(int i = 1; i <= n; i++)if(mx[i] == mxx)ans = max(ans, dp[i][m]);

    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}