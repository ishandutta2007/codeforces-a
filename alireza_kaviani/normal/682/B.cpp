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

    int n;
    cin >> n;

    vector<int> vec(n + 1);
    vec[0] = 0;
    for(int i = 1 ; i <= n ; i++)    cin >> vec[i];

    Sort(vec);
    for(int i = 1 ; i <= n ; i++)
    {
        vec[i] = min(vec[i] , vec[i - 1] + 1);
    }
    cout << vec[n] + 1;

    return 0;
}