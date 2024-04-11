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
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1010 , INF = 8e18;
ll n , m , mn , mx , a[MAXN] , b[MAXN];

int main()
{
    fast_io;

    cin >> m >> n;
    for(ll i = 0 ; i < n ; i++) {cin >> a[i] ; b[i] = a[i];}
    for(ll i = 0 ; i < m ; i++)
    {
        sort(a , a + n);
        sort(b , b + n , greater<ll>());
        mn += a[0]--;
        mx += b[0]--;
        if(a[0] == 0)   a[0] = INF;
        if(b[0] == 0)   b[0] = -INF;
    }
    cout << mx << ends << mn << endl;

    return 0;
}