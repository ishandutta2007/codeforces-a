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
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, a[N], p[N], mn[N], sz[N], P;

void make(ll n){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(a != b){
		if(sz[a] >= sz[b]) swap(a,b);
		p[a] = b;
		sz[b] += sz[a];
	}
}

void solve() {
	cin >> n >> P;
	for (int i = 1; i <= n; i++) cin >> a[i];
	make(n);
	vector <pll> v;
	for (int i = 1; i <= n; i++) {
		v.pb({a[i], i});
	}
	sort(all(v));
	ll ans = 0, c = 0;
	for (auto [w, i] : v) {
		if(w > P) break;
		for (int j = i - 1; j >= 1; j--) {
			if(find(i) == find(j)) break;
			if(__gcd(a[j], a[i]) == a[i]) {
				ans += a[i];
				merge(i, j);
			} else break;
		} 
		for (int j = i + 1; j <= n; j++) {
			if(find(i) == find(j)) break;
			if(__gcd(a[j], a[i]) == a[i]) {
				ans += a[i];
				merge(i, j);
			} else break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if(find(i) == i) c++;
	}
	ans += (c - 1) * P;
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