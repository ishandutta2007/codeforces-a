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

const ll MAXN = 1010;
ll n , id , ans[MAXN];
vector<pair<string , ll>> vec;
string s;

int main()
{
    fast_io;

    cin >> s;
    n = s.size();
    s += "x";
    for(ll i = 1 ; i < n ; i++)
    {
        if(s[i] == 'b' && s[i - 1] == 'a')   ans[i - 1] = 1;
        if(s[i] == 'b' && s[i + 1] == 'a')  ans[i] = 1;
    }
    ans[n - 1] = (s[n - 1] == 'a');
    for(ll i = 0 ; i < n ; i++) cout << ans[i] << ends;

    return 0;
}