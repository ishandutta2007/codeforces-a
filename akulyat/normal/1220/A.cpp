#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j;
vector<ll> m;
bool viv = false;
string s;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin >> s;
ll z = 0;
ll o = 0;
for (auto i : s) {
    if (i == 'z')
        z++;
    if (i == 'n')
        o++;
    }


for (ll i = 0; i < o; i++)
    cout << 1 << ' ';
for (ll i = 0; i < z; i++)
    cout << 0 << ' ';





    return 0;
}