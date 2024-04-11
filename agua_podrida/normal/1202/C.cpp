#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vbool;
int mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}

template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define INF 100000000
#define todo(v) v.begin(),v.end()

void a(){
    string x;
    string y;
    cin>>x;
    cin>>y;
    reverse(todo(x));
    reverse(todo(y));
    int i = 0;
    while(y[i] != '1') i++;
    int k = 0;
    while(x[i+k] != '1') k++;
    cout<<k<<'\n';
}

void floyd(vvi& grafo){
    F0(k,10){
        F0(i,10){
            F0(j,10){
                mini(grafo[i][j],grafo[i][k]+grafo[k][j]);
            }
        }
    }
}

void b(){
    string s;
    cin>>s;
    int n = s.size();
    vi sint(n);
    F0(i,n){
        sint[i] = (int) s[i] - (int) '0';
    }
    vvi matriz(10, vi(10,0));
    F0(x,10){
        REP(y,x,9){
            vvi grafo(10,vi(10,INF));
            F0(u,10){
                grafo[u][(u+x)%10] = 1;
                grafo[u][(u+y)%10] = 1;
            }
            floyd(grafo);
            int res = 0;
            F0(i,n-1){
                if(grafo[sint[i]][sint[i+1]] > 1000){
                    res = -1;
                    break;
                }
                res += grafo[sint[i]][sint[i+1]]-1;
            }
            matriz[x][y] = res;
            matriz[y][x] = res;
        }
    }
    F0(i,10){
        F0(j,10) cout<<matriz[i][j]<<' ';
        cout<<'\n';
    }
}

void d(){
    ll n;
    cin>>n;
    ll B = 2;
    ll res = 1;
    while(res + B <= n){
        res += B;
        B++;
    }
    ll A = n - res;
    cout<<1;
    B -= 2;
    while(B--) cout<<'3';
    while(A--) cout<<'1';
    cout<<"33";
    cout<<'7';
    cout<<'\n';
}

void c(){
    string command;
    cin>>command;
    int n = command.size();
    int extDer = 0;
    int extIzq = 0;
    int extArr = 0;
    int extAb = 0;
    int x = 0;
    int y = 0;
    F0(i,n){
        if(command[i] == 'D'){
            x++;
            maxi(extDer,x);
        }
        else if(command[i] == 'A'){
            x--;
            mini(extIzq,x);
        }
        else if(command[i] == 'W'){
            y++;
            maxi(extArr,y);
        }
        else {
            y--;
            mini(extAb,y);
        }
    }
    pi tder = mp(-2,-1);
    pi tizq = mp(-2,-1);
    pi tarr = mp(-2,-1);
    pi tab = mp(-2,-1);
    x = 0;
    y = 0;
    if(extDer == x) tder.F = -1;
    if(extIzq == x) tizq.F = -1;
    if(extArr == y) tarr.F = -1;
    if(extAb == y) tab.F = -1;
    F0(i,n){
        if(command[i] == 'D'){
            x++;
            if(x == extDer){
                if(tder.F == -2) tder.F = i;
                tder.S = i;
            }
            if(y == extAb){
                tab.S = i;
            }
            if(y == extArr){
                tarr.S = i;
            }
        }
        else if(command[i] == 'A'){
            x--;
            if(x == extIzq){
                if(tizq.F == -2) tizq.F = i;
                tizq.S = i;
            }
            if(y == extAb){
                tab.S = i;
            }
            if(y == extArr){
                tarr.S = i;
            }
        }
        else if(command[i] == 'W'){
            y++;
            if(y == extArr){
                if(tarr.F == -2) tarr.F = i;
                tarr.S = i;
            }
            if(x == extDer){
                tder.S = i;
            }
            if(x == extIzq){
                tizq.S = i;
            }
        }
        else {
            y--;
            if(y == extAb){
                if(tab.F == -2) tab.F = i;
                tab.S = i;
            }
            if(x == extDer){
                tder.S = i;
            }
            if(x == extIzq){
                tizq.S = i;
            }
        }
    }
    bool puedoSacarCostado = tder.F > tizq.S+1 or tizq.F > tder.S+1;
    bool puedoSacarTechoPiso = tarr.F > tab.S+1 or tab.F > tarr.S+1;
    ll A = extArr-extAb+1;
    ll B = extDer-extIzq+1;
    if(A >= B){
        if(puedoSacarCostado) B--;
        else if(puedoSacarTechoPiso) A--;
    }
    else {
        if(puedoSacarTechoPiso) A--;
        else if(puedoSacarCostado) B--;
    }
    cout<<A*B<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) c();
    return 0;
}