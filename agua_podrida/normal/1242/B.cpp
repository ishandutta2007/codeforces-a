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
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 1000000007;

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
#define INF 1e17
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    ll n;
    cin>>n;
    if(n == 1) {
        cout<<1<<'\n';
        return;
    }
    ll aux = n;
    vll factorizacion;
    ll div = 2;
    while(n > 1){
        while(n % div == 0) {
            n /= div;
            factorizacion.pb(div);
        }
        div++;
        if(div*div > n) {
            if(n > 1) factorizacion.pb(n);
            break;
        };
    }

    if(factorizacion.size() == 1) cout<<aux<<'\n';
    else if(factorizacion[0] == factorizacion.back()) cout<<factorizacion[0]<<'\n';
    else cout<<1<<'\n';
}

int n,m;

void dfs(vector<set<int>>& grafo, int nodo, int c, set<int>& aislados){
    int ultVisto = 0;
    while(ultVisto < n){
        auto it = aislados.upper_bound(ultVisto);
        if(it == aislados.end()) break;
        ultVisto = *it;
        if(grafo[nodo].count(*it) == 0){
            aislados.erase(it);
            dfs(grafo,ultVisto,c,aislados);
        }
    }
}

void b(){
    cin>>n>>m;
    vector<set<int>> grafo(n+1);
    int u,v;
    F0(i,m){
        cin>>u>>v;
        grafo[u].insert(v);
        grafo[v].insert(u);
    }

    int c = -1;
    set<int> aislados;
    F1(i,n) aislados.insert(i);
    F1(i,n) {
        if(aislados.count(i)){
            aislados.erase(i);
            dfs(grafo,i,c,aislados);
            c++;
        }
    }

    cout<<c<<'\n';
}

int main() {
    b();
}