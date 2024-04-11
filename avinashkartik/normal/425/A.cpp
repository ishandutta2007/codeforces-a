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

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, k, a[N];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll ans = *max_element(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		multiset <int, greater<>> left;
		multiset <int> taken;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			left.insert(a[j]);
		}
		taken.insert(a[i]);
		ll sum = a[i];
		for (int j = i + 1; j <= n; j++) {
			sum += a[j];
			taken.insert(a[j]);
			left.erase(left.find(a[j]));
			auto l = left.begin(), t = taken.begin();
			ll k1 = k, res = sum;
			ans = max(ans, res);
			while (k1 && l != left.end() && t != taken.end()) {
				res += *l - *t;
				ans = max(ans, res);
				k1--;
				l++;
				t++;
			}
		}
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}