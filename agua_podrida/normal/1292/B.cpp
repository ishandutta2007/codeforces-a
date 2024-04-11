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
#define INF 1000000000
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

void a(){
    int n,q;
    cin>>n>>q;
    vvb lava(3,vb(n+2,false));
    vb bloqueado(n+2,false);
    int cantFilasBloqueadas = 0;
    int r,c;
    while(q--){
        cin>>r>>c;
        if(lava[r][c]){
            lava[r][c] = false;
            if(bloqueado[c] and !(lava[r][c+1] and lava[r%2+1][c])){
                bloqueado[c] = false;
                cantFilasBloqueadas--;
            }
            if(bloqueado[c-1] and !lava[r][c-1]){
                bloqueado[c-1] = false;
                cantFilasBloqueadas--;
            }
        }
        else {
            lava[r][c] = true;
            if(!bloqueado[c] and (lava[r%2+1][c] or lava[r%2+1][c+1])){
                bloqueado[c] = true;
                cantFilasBloqueadas++;
            }
            if(!bloqueado[c-1] and lava[r%2+1][c-1]){
                bloqueado[c-1] = true;
                cantFilasBloqueadas++;
            }
        }
        if(cantFilasBloqueadas == 0) cout<<"Yes\n";
        else cout<<"No\n";
    }
}

void b(){
    ll x0,y0,ax,ay,bx,by;
    ll xs,ys,t;
    cin>>x0>>y0>>ax>>ay>>bx>>by;
    cin>>xs>>ys>>t;
    vpll p;
    while(x0 <= 2e16 and y0 <= 2e16){
        p.pb(mp(x0,y0));
        x0 *= ax;
        x0 += bx;
        y0 *= ay;
        y0 += by;
    }
    int res = 0;
    if(abs(p[0].F-xs)+abs(p[0].S-ys) <= t){
        ll sobra = t - abs(p[0].F-xs) - abs(p[0].S-ys);
        int i = 0;
        while(i+1 < p.size() and abs(p[0].F - p[i+1].F)+abs(p[0].S - p[i+1].S) <= sobra) i++;
        res = i+1;
    }

    int i = 0;
    while(i+1 < p.size()){
        i++;
        if(abs(p[i].F - xs) + abs(p[i].S - ys) > t) continue;
        ll sobra = t - (abs(p[i].F - xs) + abs(p[i].S - ys));
        int j = i;
        while(j >= 0 and abs(p[j].F - p[i].F) + abs(p[j].S - p[i].S) <= sobra) j--;
        maxi(res,i-j);
    }
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    b();
    return 0;
}