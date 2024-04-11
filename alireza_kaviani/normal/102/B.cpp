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

int solve(int n)
{
    if(n < 10)  return 1;
    int sum = 0;
    for( ; n != 0 ; n /= 10)    sum += n % 10;
    return 1 + solve(sum);
}

int main()
{
    fast_io;

    int n = 0;
    string s;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++) n += s[i] - 48;
    cout << (s.size() == 1 ? 0 : solve(n));

    return 0;
}