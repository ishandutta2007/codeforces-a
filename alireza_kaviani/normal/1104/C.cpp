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
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;

ll n , cnt[2];
string s;
pll cel[2][2] = {{{1 , 1} , {3 , 1}} , {{4 , 3} , {4 , 1}}};

int main()
{
    fast_io;

    cin >> s;
    n = s.size();
    for(ll i = 0 ; i < n ; i++)
    {
        if(s[i] == '0')
        {
            cout << cel[0][cnt[0] % 2].X << sep << cel[0][cnt[0] % 2].Y << endl;
            cnt[0]++;
        }
        if(s[i] == '1')
        {
            cout << cel[1][cnt[1] % 2].X << sep << cel[1][cnt[1] % 2].Y << endl;
            cnt[1]++;
        }
    }

    return 0;
}
/*
todo :
    1- set consants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea
    5- don't forget printf and scanf can help you in your code speed
*/