#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1e5 + 10;
ll n , s , p[MAXN];

ll get(ll k)
{
    ll ans = 0 , q[n];
    for(ll i = 1 ; i <= n ; i++)
    {
        q[i - 1] = p[i] + i * k;
    }
    sort(q , q + n);
    for(ll i = 0 ; i < k ; i++)
    {
        ans += q[i];
    }
    return ans;
}

ll BS(ll l , ll r)
{
    if(l == r)  return l;
    ll mid = 1 + l + r >> 1;
    if(get(mid) <= s)    return BS(mid , r);
    return BS(l , mid - 1);
}

int main()
{
    fast_io;

    cin >> n >> s;
    for(ll i = 1 ; i <= n ; i++)    cin >> p[i];
    cout << BS(0 , n) << ends << get(BS(0 , n)) << endl;

    return 0;
}