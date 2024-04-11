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

int n , q , ans;
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> q >> s;
	for(int i = 0 ; i + 2 < n ; i++){
		if(s.substr(i , 3) == "abc"){
			ans++;
		}
	}
	while(q--){
		int ind;
		string c;
		cin >> ind >> c; ind--;
		for(int i = max(ind - 2 , 0) ; i <= ind && i + 2 < n ; i++){
			if(s.substr(i , 3) == "abc"){
				ans--;
			}
		}
		s[ind] = c[0];
		for(int i = max(ind - 2 , 0) ; i <= ind && i + 2 < n ; i++){
			if(s.substr(i , 3) == "abc"){
				ans++;
			}
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/