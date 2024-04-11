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
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, vis[N];

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= 3*n; i++) vis[i] = 0;
	vll match;
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		if(!vis[u] && !vis[v]){
			vis[u] = 1;
			vis[v] = 1;
			match.pb(i);
		}
	}
	if(match.size() >= n){
		deb1("Matching")
		for(int i = 0; i < n; i++) cout << match[i] << " ";
		newl;
	} else {
		deb1("IndSet")
		for(int i = 1, j = 0; i <= 3*n; i++){
			if(vis[i]) continue;
			if(j == n) break;
			cout << i << " ";
			j++;
		}
		newl;
	}

}

int main(){
	GODSPEED;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}