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
 
const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n;
string s, t, ans = "";

void solve(){
    cin>>n>>s>>t;
    int cts = 0, ctt = 0;
    for(int i = 0; i < n; i++){
        cts += s[i]-'0';
        ctt += t[i]-'0';
        if(s[i] != t[i]) ans += s[i];
    }
    if(cts != ctt){
        deb1(-1)
        return;
    }
    n = ans.size();
    int mx = 0, mn = 0, tmx = 0, tmn = 0;
    for(int i = 0; i < n; i++){
        if(ans[i] == '1'){
            mx += 1;
            tmx = max(tmx,mx);
            mn = min(0,mn+1);
            tmn = min(tmn,mn);
        }
        else{
            mx = max(0,mx-1);
            tmx = max(tmx,mx);
            mn -= 1;
            tmn = min(tmn,mn);
        }
    }
    deb1(max(tmx,-tmn))
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