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
const long long mod = ml * kk + 7;;
const long long inf = ml * ml * ml + 7;
 
 
ll n;
vector<ll> m;
bool viv = false;

void solve() {
	ll a, b;
	cin >> a >> b;
	b++;
	ll b2 = 0;
	while (b > 0)
		b2++, b /= 10;
	b2--;
	cout << a * b2 << '\n';

}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    	solve();


    return 0;
}