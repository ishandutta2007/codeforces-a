#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n;

struct pt {
	int r, c;
	pt(int r = 0, int c = 0) : r(r), c(c) {}
	bool operator<(pt const& other) {
		return r < other.r;
	}
};

void solve() {
	cin >> n;
	vector <pt> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].r;
	for(int i = 0; i < n; i++) cin >> v[i].c;
	sort(all(v));
	ll x = 1, y = 1, ans = 0;
	for(auto it : v) {
		int dx = it.r - x, dy = it.c - y;
		if((x + y) % 2 == 0 && dx == dy) {
			ans += dx;
			x = it.r, y = it.c;
			continue;
		} else if((x + y) % 2 == 0) x++;
		x += dy;
		ans += (it.r - x + 1) / 2;
		x = it.r, y = it.c;
	}
	deb1(ans)
}


int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}