#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  130;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n = 120, q;

void solve() {
	cin >> q;
	while (q--) {
		ll t, x, y; cin >> t >> x >> y;
		vector <vector <ll>> a(n + 1, vector <ll>(n + 1, 0));
		a[0][0] = t - x - y;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j + 1] += (a[i][j] + 1) / 2;
				a[i + 1][j] += a[i][j] / 2;
			}
		}
		vector <vector <ll>> b(n + 1, vector <ll>(n + 1, 0));
		b[0][0] = t - x - y + 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[i][j + 1] += (b[i][j] + 1) / 2;
				b[i + 1][j] += b[i][j] / 2;
			}
		}
		if (b[x][y] == a[x][y]) deb1("NO")
		else deb1("YES")
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}