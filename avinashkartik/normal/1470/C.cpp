#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(12);
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

const ll   N     =  6e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, p;

int query(int i) {
	cout << "? " << i + 1 << endl;
	int x; cin >> x;
	return x;
}

void solve() {
	cin >> n >> p;
	for (int i = 0, j = 1; j <= n; i = (i + j) % n, j++) {
		int x = query(i);
		if (x == p) continue;
		else if (x > p) {
			for (int k = 1; k < n; k++) {
				int x = query((i + n - k) % n);
				if (x == p) {
					cout << "! " << (i + n - k) % n + 1 << endl;
					break;
				}
			}
		} else {
			for (int k = 1; k < n; k++) {
				int x = query((i + k) % n);
				if (x == p) {
					cout << "! " << (i + k) % n + 1 << endl;
					break;
				}
			} 
		}
		break;
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