#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 998244353;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n,m;
    cin>>n>>m;
    if(n%m == 0) cout<<"YES\n";
    else cout<<"NO\n";
}

void b(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    sort(todo(a));
    F0R(i,n) cout<<a[i]<<' ';
    cout<<'\n';
}

void c(){
    int n;
    ll k;
    cin>>n>>k;
    vll a(n);
    F0(i,n) cin>>a[i];
    vi b(100);
    F0(i,n){
        int j = 0;
        ll pot = k;
        while(pot < 1e16){
            if(a[i] % pot != 0) b[j]++;
            a[i] -= (a[i] % pot);
            pot *= k;
            j++;
        }
    }
    F0(i,100){
        if(b[i] > 1) {
            cout<<"NO\n";
            return;
        }

    }
    cout<<"YES\n";
}

ll pot(ll x, int exp, ll mod){
    if(exp == 0) return 1;
    ll a = pot(x,exp/2,mod);
    a *= a;
    a %= mod;
    if(exp % 2 != 0) a *= x;
    a %= mod;
    return a;
}

void dividir(ll& x, ll d, ll mod){
    x *= pot(d,mod-2,mod);
    x %= mod;
}

void d(){
    ll n,m;
    cin>>n>>m;
    if(n == 2) {
        cout<<"0\n";
        return;
    }
    ll potencia = 1;
    int exp = 0;
    while(exp != n-3){
        potencia *= 2;
        potencia %= mod;
        exp++;
    }

    vll combinatorio(m);
    combinatorio[n-2] = 1;
    REP(i,n-1,m-1){
        combinatorio[i] = combinatorio[i-1] * (ll) i;
        combinatorio[i] %= mod;
        dividir(combinatorio[i],i-n+2,mod);
    }

    ll res = 0;
    ll resi;
    REP(i,n-2,m){
        resi = 0;
        resi += combinatorio[i-1];
        resi *= n-2;
        resi %= mod;
        resi *= potencia;
        resi %= mod;
        res += resi;
        res %= mod;
    }

    cout<<res<<'\n';
}

int val[500][501];

void e(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    vvi dp(500,vi(501,INF));
    F1(len,n){
        F0(l,n-len+1){
            if(len == 1) {
                dp[l][l+1] = 1;
                val[l][l+1] = a[l];
                continue;
            }
            int r = l + len;
            REP(m,l+1,r-1){
                mini(dp[l][r],dp[l][m]+dp[m][r]);
                if(dp[l][m] == 1 and dp[m][r] == 1 and val[l][m] == val[m][r]){
                    dp[l][r] = 1;
                    val[l][r] = val[l][m]+1;
                    break;
                }
            }
        }
    }
    cout<<dp[0][n]<<'\n';
}

int nim(vll& a){
    sort(todo(a));
    int res = 0;
    int i = 0;
    while(i < a.size()){
        if(res < a[i]) return res;
        if(res == a[i]) res++;
        else i++;
    }
    return res;
}

void f(){
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    vll sinInf, sinCab, valeTodo;
    sinInf.pb(0); sinCab.pb(0); valeTodo.pb(0);
    vll a;
    int i = 1;
    while(i < 10000){

        a.clear();
        //valeTodo
        a.pb(sinInf[max(0,i-y)]);
        a.pb(sinCab[max(0,i-z)]);
        a.pb(valeTodo[max(0,i-x)]);
        valeTodo.pb(nim(a));

        a.clear();
        //sinInf
        a.pb(sinCab[max(0,i-z)]);
        a.pb(valeTodo[max(0,i-x)]);
        sinInf.pb(nim(a));

        a.clear();
        //sinCab
        a.pb(sinInf[max(0,i-y)]);
        a.pb(valeTodo[max(0,i-x)]);
        sinCab.pb(nim(a));

        i++;
    }

    int l = 5000;
    int k;
    REP(len,10,1000){
        bool hayCiclo = true;
        F0(i,len){
            if(sinCab[l+i] != sinCab[l+len+i]) {
                hayCiclo = false; break;
            }
            if(valeTodo[l+i] != valeTodo[l+len+i]) {
                hayCiclo = false; break;
            }
            if(sinInf[l+i] != sinInf[l+len+i]) {
                hayCiclo = false; break;
            }
        }
        if(hayCiclo) {
            k = len;
            break;
        }
    }

    vll b(n);
    F0(i,n) cin>>b[i];
    vll grundys(n);
    F0(i,n) {
        if(b[i] < l) grundys[i] = valeTodo[b[i]];
        else grundys[i] = valeTodo[l + (b[i]-l)%k];
    }
    int grundy = 0;
    F0(i,n) grundy ^= grundys[i];
    int res = 0;
    F0(i,n){
        if(b[i] < l){
            if(sinInf[max(0,(int)b[i]-y)] == (grundy ^ grundys[i])) res++;
            if(sinCab[max(0,(int)b[i]-z)] == (grundy ^ grundys[i])) res++;
            if(valeTodo[max(0,(int)b[i]-x)] == (grundy ^ grundys[i])) res++;
        }
        else{
            if(sinInf[l + (b[i]-l)%k - y] == (grundy ^ grundys[i])) res++;
            if(sinCab[l + (b[i]-l)%k - z] == (grundy ^ grundys[i])) res++;
            if(valeTodo[l + (b[i]-l)%k - x] == (grundy ^ grundys[i])) res++;
        }

    }
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) f();
    return 0;
}