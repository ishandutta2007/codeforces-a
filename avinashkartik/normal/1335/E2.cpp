#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio                ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second
#define  endl                  "\n"
#define  pb                    push_back  
#define  mset(a,x)             memset(a,x,sizeof(a))             
 
typedef  int             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll t=1,n,a[N],ct[N][201],l,r,cti,ctj,ans,res;
 
ll bs(ll x, ll cnt){
	ll l = 1;
	ll r = n;
	ll ans = 0;
	while(l <= r){
		ll mid = (l+r)/2;
		if(ct[mid][x] <= cnt){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return ans+1;
}
 
void solve(){
	cin>>n;
	res = 0;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		for(int j = 1; j <= 200; j++)
			ct[i][j] = ct[i-1][j];
		ct[i][a[i]]++;
		res = max(ct[i][a[i]],res);
	}
	for(int i = 1; i <= n; i++){
		ll x = a[i];
		ll cnt = ct[n][a[i]]-ct[i][a[i]];
		ll ind = bs(x,cnt);
		if(ind <= i) continue;
		ans = 0;
		for(int j = 1; j <= 200; j++)
			ans = max(ans,ct[ind-1][j]-ct[i][j]);
		res = max(ans+2*ct[i][a[i]],res);
				
	}
	cout<<res<<endl;
}
 
int main(){
    fastio;
    cin>>t;
    for(int i = 0; i < t; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}