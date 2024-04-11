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

const ll MAXN = 1e6 + 10 , INF = 8e18;
ll n , mx , ansl , ansr , p[MAXN] , cnt[MAXN] , l[MAXN] , r[MAXN];

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/
    fill(l , l + MAXN , INF);

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> p[i];
        cnt[p[i]]++;
        l[p[i]] = min(i , l[p[i]]);
        r[p[i]] = i;
    }
    for(ll i = 0 ; i < MAXN ; i++)
    {
        if(cnt[i] > mx)
        {
            ansl = l[i];
            ansr = r[i];
            mx = cnt[i];
        }
        if(cnt[i] == mx && ansr - ansl + 1 > r[i] - l[i] + 1)
        {
            ansl = l[i];
            ansr = r[i];
        }
    }
    cout << ansl << sep << ansr << endl;

    return 0;
}