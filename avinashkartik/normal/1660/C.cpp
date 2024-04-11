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

int n, dp[N][27];
string s;

int mem(int i, int j) {
	if (i == n) return j == 26? 0 : INFi;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = mem(i + 1, j) + 1;
	if (j == 26) dp[i][j] = min(dp[i][j], mem(i + 1, s[i] - 'a'));
	else if (s[i] - 'a' == j) dp[i][j] = min(dp[i][j], mem(i + 1, 26));
	return dp[i][j];
}

void solve() {
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 26; j++) dp[i][j] = -1;
	}
	deb1(mem(0, 26))
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}