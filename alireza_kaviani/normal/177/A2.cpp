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
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1000;
ll n , ans , good[MAXN][MAXN];

int main()
{
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < n ; i++)
        good[i][n / 2] = good[n / 2][i] = good[i][i] = good[i][n - i - 1] = 1;

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < n ; j++)
        {
            ans += input() * good[i][j];
        }
    }
    cout << ans << endl;

    return 0;
}