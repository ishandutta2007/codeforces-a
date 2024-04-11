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

const ll   N     =  1e6 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int m, n;

void solve() {
	cin >> m >> n;
	vector <vector <int>> p(m + 1, vector <int>(n + 1));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> p[i][j];
		}
	}
	if (m < n) {
		int ans = INFi;
		for (int i = 1; i <= n; i++) {
			int res = 0;
			for (int j = 1; j <= m; j++) {
				res = max(res, p[j][i]);
			}
			ans = min(ans, res);
		}
		deb1(ans)
	} else {
		
		auto f = [&](int x) -> bool {
			vector <int> ct(n + 1, 0);
			bool f = 0;
			for (int i = 1; i <= m; i++) {
				int cnt = 0;
				for (int j = 1; j <= n; j++) {
					if (p[i][j] >= x) {
						ct[j]++;
						cnt++;
					}
				}
				f |= (cnt > 1);
			}
			for (int i = 1; i <= n; i++) {
				if (ct[i] == 0) return 0;
			}
			return f;
		};
		int l = 1, r = 1e9, ans = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (f(mid)) {
				ans = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		deb1(ans)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}