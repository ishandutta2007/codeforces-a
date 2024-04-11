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

const ll MAXN = 1010;
ll n , p[MAXN];

ll ok()
{
    for(ll i = 0 ; i < n ; i++)
    {
        if(p[i] != i)   return 0;
    }
    return 1;
}

void update()
{
    for(ll i = 0 , t = 1 ; i < n ; i++ , t *= -1)
    {
        p[i] = (p[i] + t + n) % n;
    }
}

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 0 ; i < n ; i++) cin >> p[i];
    for(ll i = 0 ; i < 1e5 ; i++)
    {
        if(ok())   return cout << "YES" << endl , 0;
        update();
    }
    cout << "NO" << endl;

    return 0;
}