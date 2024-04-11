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
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main()
{
    fast_io;

    ll n , sum = 0 , sum2 = 0 , ans = 0;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n ;i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(sum2 * 2 < sum)
        {
            ans++;
            sum2 += a[i];
        }
    }
    cout << ans << endl;

    return 0;
}