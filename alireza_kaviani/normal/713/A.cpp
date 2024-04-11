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

const int maxn = 18;
int cnt[1 << (maxn + 1)];

int val(string s)
{
	while (s.size() < maxn)	s = "0" + s;
	int ans = 0;
	for (int i = 0 ; i < s.size() ; i++)
	{
		ans = ans * 2 + s[i] % 2;
	}
	return ans;
}

int main()
{
    fast_io;
    
    int t;
    cin >> t;
    while (t--)
    {
    	char c;
    	string s;
    	cin >> c >> s;
    	if (c == '+')	cnt[val(s)]++;
    	if (c == '-')	cnt[val(s)]--;
    	if (c == '?')	cout << cnt[val(s)] << endl;
    }
    
    return 0;
}