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

    int m , n;
    cin >> m >> n;

    vector<bool> ok(n , 0);
    for(int i = 0 ; i < m ; i++)
    {
        int l , r;
        cin >> l >> r;
        l-- ; r--;
        for(int j = l ; j <= r ; j++)
        {
            ok[j] = 1;
        }
    }

    vector<int> ans;
    for(int i = 0 ; i < n ; i++)
    {
        if(!ok[i])
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0 ; i < ans.size() ; i++)   cout << ans[i] + 1 << ends;

    return 0;
}