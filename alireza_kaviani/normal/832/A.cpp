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
#define Mp                           make_pair
#define endt                        '\t'
#define ends

int main()
{
    ld a,b;
    cin >> a >> b;
    ll ans=((ll)floor(a/b))%2;
    if(ans)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}