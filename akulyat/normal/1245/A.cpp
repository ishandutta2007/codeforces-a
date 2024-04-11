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
 
long long GCD(long long a, long long b)
{
if (a == 0 && b == 0)
    return 1;
while (a != 0&&b != 0)
    {
    if (a >= b)
        a %= b;
    else
        b %= a;
    }
return a + b;
}
 
 
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
        {
        ll a, b;
        cin >> a >> b;
        if (GCD(a, b) == 1)
            cout << "Finite\n";
        else
            cout << "Infinite\n";
        }
 
    return 0;
}