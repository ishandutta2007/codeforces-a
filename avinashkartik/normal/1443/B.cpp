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
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll a, b, dp[N][2];
string s;

ll mem(int i, int j){
	if(i == s.size()) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	dp[i][j] = INF;
	if(s[i] == '0'){
		if(j == 1) dp[i][j] = min(dp[i][j], mem(i + 1, 1) + b);
		else dp[i][j] = min(dp[i][j], mem(i + 1, 1) + a + b);
		dp[i][j] = min(dp[i][j], mem(i + 1, 0));
	} else {
		if(j == 1) dp[i][j] = min(dp[i][j], mem(i + 1, 1));
		else dp[i][j] = min(dp[i][j], mem(i + 1, 1) + a);
	}
	return dp[i][j];
}

void solve(){
	cin >> a >> b >> s;
	for(int i = 0; i <= s.size(); i++) dp[i][0] = dp[i][1] = -1;
	deb1(mem(0, 0));
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}