#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  2e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, suf[N], valid[N];
string s;

void solve(){
    cin>>n>>s;
    if(n&1){
    	deb1(0)
    	return;
    }
    int ans = 0;
    valid[n] = 1;
    for(int i = n-1; i >= 0; i--){
    	if(s[i] == ')') suf[i] = suf[i+1]+1;
    	else suf[i] = suf[i+1]-1;
    	valid[i] = valid[i+1] & (suf[i] >= 0);
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == '(') sum++;
    	else sum--;
    	if(valid[i+1]){
	    	ll x = sum;
	    	if(s[i] == ')') x = sum+2;
	    	else x = sum-2;
	    	if(x == suf[i+1]) ans++;
	    }
    	if(sum < 0) break;
    }
    deb1(ans)
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}