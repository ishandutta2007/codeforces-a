#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define pll pair <ll, ll>
#define all(x) x.begin(),x.end()
#define pii pair <int, int>
#define sqr(x) ((x)*(x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
template <typename T> void vout(T s){cout << s << endl; exit(0);}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;
    vector <ll> r(n + 1);
    vector <ll> p(n + 1);

    for(int i = 1; i <= n; i++)cin >> p[i];
    for(int i = 1; i <= n; i++)cin >> r[i];

    vector <ll> ans(n + 1);

    ll ra, rb;
    ra = rb = 0;

    for(int i = 1; i <= n; i++){
        if(p[i] == 1 && r[i] == 1)continue;
        if(p[i] == 1)ra++;
        else if(r[i] == 1)rb++;
    }

    if(!ra)vout(-1);


    ll t = rb / ra + 1;
    cout << t << "\n";
    return 0;
}