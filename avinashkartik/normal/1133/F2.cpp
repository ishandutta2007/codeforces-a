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
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, m, d, p[N], sz[N];
vll adj[N];
set <ll> v[N];

void make(ll n){
    for(int i = 1; i <= n; i++){
        p[i] = i;
        sz[i] = 1;
    }
}

int find(ll x){
    return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
    ll a = find(x);
    ll b = find(y);
    if(a != b){
        if(sz[a] >= sz[b]) swap(a,b);
        p[a] = b;
        sz[b] += sz[a];
    }
}

void solve(){
    cin>>n>>m>>d;
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    make(n);
    int maxx = 0, ind = 0; 
    set <pll> ans;
    for(int i = 2; i <= n; i++){
        for(auto it : adj[i]){
            if(it == 1) continue;
            if(find(i) != find(it)){
                merge(i,it);
            }
        }
    }
    ll ct = 0;
    for(auto it : adj[1]){
        if(find(1) != find(it)){
            ans.insert({1,it});
            merge(1,it);
            ct++;
        }
    }
    if(ct > d){
        deb1("NO")
        return;
    }
    make(n);
    ct = 0;
    for(auto it : ans){
        merge(it.f,it.s);
        ct++;
    }
    for(auto it : adj[1]){
        if(ct == d) break;
        if(find(1) != find(it)){
            ans.insert({1,it});
            merge(1,it);
            ct++;
        }
    }
    for(int i = 2; i <= n; i++){
        for(auto it : adj[i]){
            if(it == 1) continue;
            if(find(i) != find(it)){
                merge(i,it);
                ans.insert({it,i});
            }
        }
    }
    if(ct != d){
        deb1("NO")
        return;
    }
    deb1("YES")
    for(auto it : ans) deb2(it.f,it.s);
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