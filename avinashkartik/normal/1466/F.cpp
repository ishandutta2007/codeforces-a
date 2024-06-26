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

const ll   N     =  5e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, a[N], p[N];

void make(ll n){
	for(int i = 1; i <= n; i++){
		p[i] = 0;
	}
}

int find(ll x){
	return (p[x] == x || p[x] == 0)? x: p[x] = find(p[x]);
}

ll fastmod(ll x, ll y = mod - 2) {
	ll res = 1;
	while(y) {
		if(y&1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

void solve() {
	cin >> n >> m;
	make(m + 2);
	vll ans;
	for(int i = 1;  i <= n; i++) {
		int k, u, v; cin >> k;
		if(k == 1) {
			cin >> u;
			ll pu = find(u);
			if(p[pu] == 0) {
				p[pu] = pu;
				ans.pb(i);
			}
		} else {
			cin >> u >> v;
			ll pu = find(u), pv = find(v);
			if(pu > pv) swap(pu, pv);
			if(pu == pv) continue;
			if(p[pu] == 0) {
				p[pu] = pv;
				ans.pb(i);
			} else if(p[pv] == 0) {
				p[pv] = pv;
				ans.pb(i);
			}
		}
	}
	deb2(fastmod(2, ans.size()), ans.size())
	debv(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}