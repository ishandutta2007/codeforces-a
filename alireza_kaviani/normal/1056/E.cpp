/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD1 = 998244353;
const ll MOD2 = 1e9 + 7;
const ll MOD3 = 1e9 + 9;

vector<ll> primes;
ll ns , nt , ans , cnt[2] , sz[2] , mod[3] = {MOD1 , MOD2 , MOD3} , base[3] , p[MAXN][3] , inv[MAXN][3] , hs[MAXN][3];
pair<ll , pll> val[2];
string s , t;

void Hash(ll ind)
{
    p[0][ind] = 1;
    inv[0][ind] = 1;
    ll baseInv = poww(base[ind] , mod[ind] - 2 , mod[ind]);
    for(ll i = 1 ; i < MAXN ; i++) {
        p[i][ind] = p[i - 1][ind] * base[ind] % mod[ind];
        inv[i][ind] = inv[i - 1][ind] * baseInv % mod[ind];
    }
    for(ll i = 0 ; i < nt ; i++)
    {
        hs[i + 1][ind] = hs[i][ind] + (t[i] - 96) * p[i][ind] % mod[ind];
    }
}

ll pr(ll x)
{
    for(ll i = 2 ; i * i <= x ; i++)
    {
        if(x % i == 0)  return 0;
    }
    return 1;
}

pair<ll , pll> get(ll l , ll r)
{
    ll a[3];
    for(ll i = 0 ; i < 3 ; i++)
        a[i] = (hs[r][i] + mod[i] - hs[l][i]) % mod[i] * inv[l][i] % mod[i];
    return {a[0] , {a[1] , a[2]}};
}

int main() {
    fast_io;
    set_random;

    for(ll i = 30 ; i <= 1e5 ; i++)
    {
        if(pr(i))   primes.push_back(i);
    }

    for(ll i = 0 ; i < 3 ; i++) base[i] = primes[rng() % primes.size()];

    cin >> s >> t;
    ns = s.size();
    nt = t.size();

    for(ll i = 0 ; i < 3 ; i++) Hash(i);

    for(ll i = 0 ; i < ns ; i++)    cnt[s[i] - 48]++;

    for(ll i = 1 ; i < nt ; i++)
    {
        ll x = nt - i * cnt[0];
        if(x <= 0 || x % cnt[1] != 0)   continue;

        ll can = 1;

        sz[0] = i;
        sz[1] = x / cnt[1];

        pair<ll , pll> val[2];
        val[0] = get(s.find('0') * sz[1] , s.find('0') * sz[1] + sz[0]);
        val[1] = get(s.find('1') * sz[0] , s.find('1') * sz[0] + sz[1]);

        for(ll j = 0 , k = 0 ; j < nt ; k++)
        {
            ll type = s[k] - 48;
            if(get(j , j + sz[type]) != val[type])  can = 0;
            j += sz[type];
        }
        if(val[0] == val[1])    can = 0;
        ans += can;
    }
    cout << ans << endl;

    return 0;
}

/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/