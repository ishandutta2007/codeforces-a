// Dennis - Toney
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

int Main(){
	int n;
	cin >> n;
	ll mx = 0;
	ll res = 1, sm = 0;
	for(int i = 0; i < n; i++){
		ll v;
		cin >> v;
		while(v % 2 == 0){
			v /= 2;
			res *= 2;
		}
		mx = max(mx, v);
		sm += v;
		// debug(v);
	}
	cout << sm + (res - 1) * mx << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}