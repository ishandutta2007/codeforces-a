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

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

vll factoresPrimos(ll n){
    ll factor = 2;
    vll res;
    while(factor*factor <= n){
        if(n%factor == 0) res.pb(factor);
        while(n%factor == 0) n /= factor;
        factor++;
    }
    if(n > 1) res.pb(n);
    return res;
}

vi factorizacion(ll u, vll& primos){
    vi res(primos.size(),0);
    F0(i,primos.size()){
        while(u%primos[i] == 0){
            u /= primos[i];
            res[i]++;
        }
    }
    return res;
}

ll c[101][101];

void calcularCombinatorios(){
    c[0][0] = 1;
    F1(n,100){
        c[n][0] = 1;
        REP(k,1,n-1) c[n][k] = (c[n-1][k-1]+c[n-1][k])%mod;
        c[n][n] = 1;
    }
}


ll maneras(vi x){
    if(x.empty())
        return 1;
    int total = 0;
    F0(i,x.size()) total += x[i];
    int ultimo = x.back();
    x.pop_back();
    ll res = maneras(x);
    res *= c[total][ultimo];
    res %= mod;
    return res;
}

void e(){
    calcularCombinatorios();
    ll d;
    cin>>d;
    int q;
    cin>>q;
    vll primos = factoresPrimos(d);
    ll u,v;
    while(q--){
        cin>>u>>v;
        vi alfa = factorizacion(u,primos);
        vi beta = factorizacion(v,primos);
        vi positivas;
        vi negativas;
        F0(i,primos.size()){
            if(alfa[i] > beta[i]) positivas.pb(alfa[i]-beta[i]);
            else if(alfa[i] < beta[i]) negativas.pb(beta[i]-alfa[i]);
        }
        ll res = 1;
        res *= maneras(positivas);
        res *= maneras(negativas);
        res %= mod;
        cout<<res<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../output.txt","w",stdout);
    e();
    return 0;
}