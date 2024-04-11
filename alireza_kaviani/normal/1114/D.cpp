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
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

mt19937 random(chrono::steady_clock::now().time_since_epoch().count());

const ll MAXN = 5010;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , p[MAXN] , dp[MAXN][MAXN];
vector<ll> vec;

int main()
{
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> p[i];
        if(vec.size() == 0 || p[i] != vec.back())
        {
            vec.push_back(p[i]);
        }
    }

    n = vec.size();
    for(ll i = 0 ; i < n ; i++) dp[i][i] = 0;
    for(ll i = 0 ; i < n ; i++) dp[i][i + 1] = 1;

    for(ll i = 2 ; i <= n ; i++)
    {
        for(ll l = 0 , r = i ; r < n ; l++ , r++)
        {
            dp[l][r] = min(dp[l][r - 1] + 1 , dp[l + 1][r] + 1);
            if(vec[l] == vec[r])    dp[l][r] = min(dp[l][r] , dp[l + 1][r - 1] + 1);
        }
    }
    cout << dp[0][n - 1] << endl;

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