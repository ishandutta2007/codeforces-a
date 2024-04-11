#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, a[N], ct = 0, ans = 0;

ll tree[N][2] = {};

void update(int idx, int val, int f){ 
    idx++;
    while(idx <= n+1){ 
        tree[idx][f] += val;
        idx += idx & (-idx); 
    } 
} 

ll query(int idx, int f){
    idx++;
    ll sum = 0;
    while(idx > 0){ 
        sum += tree[idx][f];
        idx -= idx & (-idx); 
    } 
    return sum; 
}

void solve(){
    cin>>n;
    vpll v;
    for(int i = 0; i < n; i++) cin>>a[i], v.pb({a[i],i});
    sort(v.begin(), v.end());
    for(auto it : v) a[it.s] = ct++;
    for(int i = 0; i < n; i++){
        ans += query(n,1) - query(a[i],1);
        ll x = query(n,0) - query(a[i],0);
        update(a[i],x,1);
        update(a[i],1,0);
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