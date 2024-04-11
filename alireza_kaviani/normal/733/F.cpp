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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;
typedef pair<ll , pair<ll , pll>> parent;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
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

const ll MAXN = 2e5 + 10;
const ll LOG = 20;
const ll INF = 8e18;
const ll MOD1 = 998244353;
const ll MOD2 = 1e9 + 7;
const ll MOD3 = 1e9 + 9;

template <ll SIZE>
struct DSU
{
    ll par[SIZE];
    DSU()
    {
        fill(par , par + SIZE , -1);
    }

    ll Find(ll v)
    {
        return (par[v] == -1 ? v : par[v] = Find(par[v]));
    }

    ll Union(ll v , ll u)
    {
        ll pv = Find(v) , pu = Find(u);
        if(pv == pu)    return 0;
        par[pu] = pv;
        return 1;
    }
};

vector<pll> adj[MAXN];
vector<pair<pll , pll>> E;
set<pair<pll , pll>> st;
map<pair<pll , pll> , ll> inMST , ind;
ll n , m , s , ans = INF , W , w[MAXN] , c[MAXN] , H[MAXN];
pair<pll , pll> edge;
parent par[MAXN][LOG];
DSU<MAXN> dsu;

void KMST()
{
    Sort(E);
    for(ll i = 0 ; i < m ; i++)
    {
        ll w = E[i].X.X , c = E[i].X.Y , v = E[i].Y.X , u = E[i].Y.Y;
        if(dsu.Union(v , u))
        {
            adj[v].push_back({u , w});
            adj[u].push_back({v , w});
            W += w;
            inMST[{{w , c} , {v , u}}] = inMST[{{w , c} , {u , v}}] = 1;
        }
    }
}

void DFS(ll v , ll p = 0 , ll w = 0)
{
    H[v] = (p == 0 ? 0 : H[p] + 1);

    par[v][0] = {p , {w , {p , v}}};
    for(ll i = 1 ; i < LOG ; i++)
    {
        par[v][i] = {par[par[v][i - 1].X][i - 1].X , max(par[v][i - 1].Y , par[par[v][i - 1].X][i - 1].Y)};
    }

    for(pll i : adj[v])
    {
        ll u = i.X , w = i.Y;
        if(u != p)
        {
            DFS(u , v , w);
        }
    }
}

parent getPar(ll v , ll h)
{
    parent res = {v , {0 , {0 , 0}}};
    for(ll i = 0 ; i < LOG ; i++)
    {
        if(h & (1 << i))
        {
            res.X = par[v][i].X;
            res.Y = max(res.Y , par[v][i].Y);
            v = res.X;
        }
    }
    return res;
}

parent LCA(ll v , ll u)
{
    if(H[v] > H[u]) swap(v , u);
    parent res = getPar(u , H[u] - H[v]);
    u = res.X;

    if(v == u)  return res;
    for(ll i = LOG - 1 ; i >= 0 ; i--)
    {
        parent pv = par[v][i] , pu = par[u][i];
        if(pv.X != pu.X)
        {
            res.Y = max(res.Y , pv.Y);
            res.Y = max(res.Y , pu.Y);
            v = pv.X;
            u = pu.X;
        }
    }
    return {par[v][0].X , max({res.Y , par[v][0].Y , par[u][0].Y})};
}

int main() {
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++) cin >> w[i];
    for(ll i = 0 ; i < m ; i++) cin >> c[i];
    for(ll i = 0 ; i < m ; i++)
    {
        ll v , u;
        cin >> v >> u;
        if(v > u)   swap(v , u);
        //E.push_back({{w[i] , c[i]} , {v , u}});
        st.insert({{w[i] , c[i]} , {v , u}});
        ind[{{w[i] , c[i]} , {v , u}}] = ind[{{w[i] , c[i]} , {u , v}}] = i + 1;
    }
    cin >> s;

    E = vector<pair<pll , pll>>(st.begin() , st.end());
    m = E.size();
    KMST();

    DFS(1);

    for(ll i = 0 ; i < m ; i++)
    {
        ll w = E[i].X.X , c = E[i].X.Y , v = E[i].Y.X , u = E[i].Y.Y;
        parent p = LCA(v , u);
        if(W - p.Y.X + w - s / c < ans)
        {
            ans = W - p.Y.X + w - s / c;
            edge = E[i];
        }
    }

    cout << ans << endl;
    ll w = edge.X.X , c = edge.X.Y , v = edge.Y.X , u = edge.Y.Y;
    parent p = LCA(v , u);
    for(ll i = 0 ; i < m ; i++)
    {
        if(E[i].X == edge.X && (E[i].Y == Mp(v , u) || E[i].Y == Mp(u , v)))
        {
            cout << ind[edge] << sep << w - s / c << endl;
        }
        else if(inMST[E[i]])
        {
            if(E[i].Y == p.Y.Y || (E[i].Y == Mp(p.Y.Y.Y , p.Y.Y.X)))
            {
                continue;
            }
            cout << ind[E[i]] << sep << E[i].X.X << endl;
        }
    }

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/