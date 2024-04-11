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

const ll   N     =  1e6+5;
const ll   mod   =  998244353 ;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, a[N], b[N], c[N], f[N], ans[N];
vll adj[N];

void solve(){
	vll left;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) f[i] = 0, adj[i].clear();
    for(int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    for(int i = 1; i <= n; i++){
    	cin >> b[i];
    	f[b[i]] = i;
    	if(b[i] != a[i]) adj[b[i]].pb(i), cnt++;
    }
    for(int i = 1; i <= m; i++){
    	cin >> c[i];
    	if(adj[c[i]].size()){
    		cnt--;
    		while(left.size()){
    			ans[left.back()] = adj[c[i]].back();
				left.pop_back();
    		}
    		ans[i] = adj[c[i]].back();
    		adj[c[i]].pop_back();
    	} else {
    		if(f[c[i]] == 0) left.pb(i);
    		else{
    			while(left.size()){
	    			ans[left.back()] = f[c[i]];
    				left.pop_back();
	    		}
    			ans[i] = f[c[i]];
    		}
    	}
    }
    if(cnt == 0 && left.size() == 0){
    	deb1("Yes")
    	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    	newl;
    }
    else deb1("No")
}

int main(){
    GODSPEED;
    int test = 1;
    cin >> test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}