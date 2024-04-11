#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], A, R, M;

ll f(int mid){
	ll x = 0, y = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] > mid) y += a[i]-mid;
		else x += mid-a[i];
	}
	ll z = min(x,y); x -= z, y -= z;
	return x*A + y*R + z*M;
}

ll ternary_search(ll l, ll r){
    for(int i = 0; i < 55; i++){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        ll f1 = f(m1);
        ll f2 = f(m2);
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    ll ans = INF;
    for(int i = l; i <= r; i++) ans = min(ans,f(i));
    return ans;
}

void solve(){
	cin>>n>>A>>R>>M;
	M = min(M,A+R);
	for(int i = 1; i <= n; i++) cin >> a[i];
	deb1(ternary_search(0,1e9))
}

int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}