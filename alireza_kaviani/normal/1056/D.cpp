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
#define tab                         '\t'
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1e5 + 10;
vector<ll> adj[MAXN];
ll n , mark[MAXN] , p[MAXN] , sz[MAXN];

void dfs(ll v)
{
    ll leaf = 1;
    mark[v] = 1;
    for(ll u : adj[v])
    {
        if(!mark[u])
        {
            dfs(u);
            sz[v] += sz[u];
            leaf = 0;
        }
    }
    sz[v] += leaf;
}

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 2 ; i <= n ; i++)
    {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    dfs(1);
    sort(sz + 1 , sz + n + 1);
    for(ll i = 1 ; i <= n ; i++)    cout << sz[i] << sep;

    return 0;
}