#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_io;

    int n , m , ans = 1e9;
    cin >> n >> m;

    int a[n] , b[m];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    for(int i = 0 ; i < m ; i++)    cin >> b[i];

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            int t = 0;
            if(a[i] == b[j])
            {
                t = a[i];
            }
            else
            {
                t = min(a[i] * 10 + b[j] , a[i] + b[j] * 10);
            }
            ans = min(ans , t);
        }
    }
    cout << ans << endl;

    return 0;
}