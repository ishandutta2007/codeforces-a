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
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    int n , k;
    cin >> n >> k;

    double ps[n];
    for(int i = 0 ; i < n ; i++)    cin >> ps[i];
    partial_sum(ps , ps + n , ps);

    double ans = 0.0;
    for(int i = 0 ; i <= n - k ; i++)
    {
        for(int j = i + k - 1 ; j < n ; j++)
        {
            double sum = (i == 0 ? ps[j] : ps[j] - ps[i - 1]);
            ans = max(ans , sum / (j - i + 1));
        }
    }
    printf("%.15f" , ans);

    return 0;
}