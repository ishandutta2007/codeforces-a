/***************************************** START OF TEMPLATE *********************************************/
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;

#define  SPEED          ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  randomINIT     mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define  foo(i,a,n)     for(ll i = (a); i <= n; i++)
#define  frr(i,a,n)     for(ll i = (a); i >= n; i--)
#define  fo(i,n)        for(ll i = 0; i < n; i++)
#define  newl           cout<<"\n";
#define  f              first
#define  s              second
#define  pb             push_back
#define  mp             make_pair
#define  sym(s)         s="#"+s+"#";   
#define  all(x)         (x).begin(),(x).end()
#define  alll(x, n)     x+1, x+n+1
#define  mset(x,val)    memset(x,val,sizeof(x))
#define  mset1d(a,n,v)  foo(i,0,n+5)a[i]=v;
#define  mset2d(a,n,m,v)foo(i,0,n+5)foo(j,0,m+5)a[i][j]=v;
#define  INP(a,n)       foo(i,1,n) cin>>a[i];
#define  deb1d(a,n)     foo(i,1,n)cout<<a[i]<<" ";newl;
#define  deb2d(a,n,m)   foo(i,1,n){foo(j,1,m){cout<<a[i][j]<<" ";}newl;}    
#define  debm(a)        for(auto it: a)cout<<"{"<<it.f<<","<<it.s<<"}, ";newl;
#define  debp(a,n)      foo(i,1,n)cout<<"{"<<a[i].f<<","<<a[i].s<<"}, ";newl;
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<" ";newl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" ";newl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" ";newl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d;newl;
#define  ll             long long
#define  ld             long double
#define  pll            pair<ll,ll>
#define  vll            vector<ll>
#define  vpll           vector<pll>

const ld   PI    =  3.14159265358979323846; 
const ll   MOD   =  998244353;
const ll   INF   =  LLONG_MAX;
const int  INFi  =  INT_MAX;
const ll   N     =  5e+5+8;

vll adj[N]; ll vis[N];
ll dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

ll test_cases = 1; randomINIT;

/*********************************************************************************************************/
/***************************************** VARIABLE DECLARATIONS *****************************************/
ll f[N], n, k, res;

/***************************************** FUNCTION IMPLEMENTATIONS **************************************/
ll fast_pow(ll x, ll y, ll MOD=MOD){
    ll res=1;
    while(y){
        if(y&1)res=(res*x)%MOD;
        y>>=1;x=(x*x)%MOD;
    }
    return res;
}

ll mod_inverse(ll x, ll MOD=MOD){
    return fast_pow(x,MOD-2,MOD);
}
ll nCr(ll n, ll r){
    if(r>n)return 0;
    return f[n]*mod_inverse(f[n-r])%MOD*mod_inverse(f[r])%MOD;
}


/***************************************** START OF MAIN FUNCTION ****************************************/
void MAIN(ll tc){
    cin>>n>>k;
    foo(i,1,n) res=(res+nCr(n/i-1,k-1))%MOD;
    cout<<res;
}

int main(){
    SPEED;
    f[0]=1;
    foo(i,1,N-1)f[i]=f[i-1]*i%MOD;
    //cin>>test_cases;
    foo(i,1,test_cases){
        MAIN(i);
    }
}