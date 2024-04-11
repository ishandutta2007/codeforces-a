#include <bits/stdc++.h>

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
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e5;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll last[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    map <vector <pll>, ll> mp;

    ll n, k;
    cin >> n >> k;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    ll ans = 0;

    for(int i = 2; i <= N; i++)if(!last[i]){
        last[i] = i;
        if(ll(i) * ll(i) <= N)for(int j = i * i; j <= N; j += i)last[j] = i;
    }

    for(int i = 1; i <= n; i++){
        map <ll, ll> f;

        ll x = a[i];

        while(x != 1){
            f[last[x]]++;
            x /= last[x];
        }

        vector <pll> c, b;

        for(auto i : f){
            int x = i.se % k;
            if(x){
                b.p_b({i.fi, x});
                c.p_b({i.fi, k - x});
            }
        }

        ans += mp[c];
        mp[b]++;
        c.clear();
        b.clear();

    }

    cout << ans << "\n";

    return 0;
}