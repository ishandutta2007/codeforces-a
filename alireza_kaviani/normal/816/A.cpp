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

    string s;
    cin >> s;

    int h = (s[0] - 48) * 10 + (s[1] - 48) , m = (s[3] - 48) * 10 + (s[4] - 48) , ans = 1e9;
    for(int i = 0 ; i <= 2; i++)
    {
        for(int j = 0 ;j <= 9 ; j++)
        {
            int nowh = i * 10 + j , nowm = j * 10 + i;
            if(nowh >= 24 || nowm >= 60)
            {
                continue;
            }
            int s = ((nowh - h) * 60 + (nowm - m) + 24 * 60) % (24 * 60);
            ans = min(ans , s);
        }
    }
    cout << ans << endl;

    return 0;
}