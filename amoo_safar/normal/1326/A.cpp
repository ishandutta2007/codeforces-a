#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	for(int u = 0; u < t; u++){
		ll n;
		cin >> n;
		if(n == 1){
			cout << "-1\n";
			continue;
		}
		for(int i = 0; i < n - 1; i++) cout << 5;
			cout << "4\n";
	}

	return 0;
}