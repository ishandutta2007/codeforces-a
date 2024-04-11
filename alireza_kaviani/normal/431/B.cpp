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

int main()
{
    fast_io;

    ll g[5][5] , p[] = {0 , 1 , 2 , 3 , 4} , ans = 0;

    for(int i = 0 ; i < 5 ; i++)
        for(int j = 0 ; j < 5 ; j++)    cin >> g[i][j];

    do {
        ll hap = 0;
        for(int i = 0 ; i < 5 ; i++)
        {
            for(int j = i ; j < 4 ; j += 2)
            {
                hap += g[p[j]][p[j + 1]] + g[p[j + 1]][p[j]];
            }
        }
        ans = max(ans , hap);
    } while(next_permutation(p , p + 5));
    cout << ans << endl;

    return 0;
}