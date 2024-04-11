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

const ll MAXN = 1e5 + 10;
vector<pii> edge;
ll n , diff , c[MAXN] , cnt[MAXN];

int main()
{
    fast_io;

    cin >> n;
    for(int i = 1 ; i < n ; i++)    edge.push_back({input() , input()});
    for(int i = 1 ; i <= n ; i++)   cin >> c[i];

    for(int i = 0 ; i < n - 1 ; i++)
    {
        if(c[edge[i].X] != c[edge[i].Y])
        {
            diff++;
            cnt[edge[i].X]++;
            cnt[edge[i].Y]++;
        }
    }

    for(int i = 1 ; i <= n ; i++)
    {
        if(cnt[i] == diff)  return cout << "YES" << endl << i << endl , 0;
    }
    cout << "NO" << endl;

    return 0;
}