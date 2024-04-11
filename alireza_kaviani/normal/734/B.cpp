#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll ans , k2 , k3 , k5 , k6;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> k2 >> k3 >> k5 >> k6;
	for(ll i = 0 ; i <= k2 ; i++){
		ans = max(ans , min({i , k5 , k6}) * 256 + min(k2 - i , k3) * 32);
	}
	cout << ans << endl;

    return 0;
}
/*

*/