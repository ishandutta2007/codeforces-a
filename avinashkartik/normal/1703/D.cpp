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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n;
string s[N];

void solve() {
	cin >> n;
	map <string, int> ct;
	vector <int> ans(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> s[i], ct[s[i]]++;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < s[i].size(); j++) {
			string x = s[i].substr(0, j), y = s[i].substr(j, s[i].size() - j);
			if (ct.find(x) != ct.end() && ct.find(y) != ct.end()) {
				 ans[i] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i];
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}