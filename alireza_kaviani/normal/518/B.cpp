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
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 2e5 + 10;
map<char , ll> cnt;
ll x , y , mark[MAXN];
string s , t;

int main()
{
    fast_io;

    cin >> s >> t;
    for(ll i = 0 ; i < t.size() ; i++)  cnt[t[i]]++;
    for(ll i = 0 ; i < s.size() ; i++)
    {
        if(cnt[s[i]])
        {
            x++;
            cnt[s[i]]--;
            mark[i] = 1;
        }
    }

    for(ll i = 0 ; i < s.size() ; i++)
    {
        if(!mark[i])
        {
            ll d = 32;
            if(s[i] > 96)   d *= -1;
            if(cnt[s[i] + d])
            {
                y++;
                cnt[s[i] + d]--;
            }
        }
    }

    cout << x << ends << y << endl;

    return 0;
}