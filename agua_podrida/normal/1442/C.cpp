#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
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
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
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
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

/*
bool sacar(pll izq, pll p, pll der){
    ll x1 = izq.first; ll y1 = izq.second;
    ll x2 = p.first; ll y2 = p.second;
    ll x3 = der.first; ll y3 = der.second;
    ll ym = y1 * (x3 - x2) + y3 * (x2 - x1);
    y2 *= (x3 - x1);
    return y2 <= ym;
}

bool sacarIzq(set<pll>& ch, pll p){
    auto it = ch.find(p);
    if(it != ch.begin()){
        auto itizq = it;
        itizq--;
        if(itizq != ch.begin()){
            auto itizqizq = itizq;
            itizqizq--;
            if(sacar(*itizqizq,*itizq,*it)) {
                ch.erase(itizq);
                return true;
            }
        }
    }
    return false;
}

bool sacarDer(set<pll>& ch, pll p){
    auto it = ch.find(p);
    auto itder = it;
    itder++;
    if(itder != ch.end()){
        auto itderder = itder;
        itderder++;
        if(itderder != ch.end() and sacar(*it,*itder,*itderder)){
            ch.erase(itder);
            return true;
        }
    }
    return false;
}

void meter(set<pll>& ch, pll p){
    auto it = ch.lower_bound(mp(p.first,-INF));
    if(it != ch.end() and it->first == p.first and it->second >= p.second) return;
    else ch.insert(p);
    auto itizq = ch.find(p);
    if(itizq != ch.begin()){
        itizq--;
        auto itder = ch.find(p);
        itder++;
        if(itder != ch.end() and sacar(*itizq,p,*itder)){
            ch.erase(p);
            return;
        }
    }

    while(sacarIzq(ch,p));
    while(sacarDer(ch,p));
}

vector<int> p, l, h, x, y;
vll res;
const int N = 1000005;
int donde[N];

vector<int> read(int n, int k, int m){
    vector<int> v(n);
    for(int i = 0; i < k; ++i) {
        cin>>v[i];
    }
    int A, B, C;
    cin>>A>>B>>C;
    if(m == -2) {
        cin>>m;
    }
    for(int i = k; i < n; ++i) {
        v[i] = ((ll) A * v[i-2] + (ll) B * v[i-1] + C) % (m == -1 ? i : m) + 1;
    }
    return v;
}

void mergear(vector<set<pll>>& ch, int aa, int bb){
    int a = donde[aa];
    int b = donde[bb];
    if(a == b) return;
    if(ch[a].size() < ch[b].size()) {
        donde[aa] = donde[bb];
        swap(a,b);
    }
    else donde[bb] = donde[aa];
    for(auto p : ch[b]) meter(ch[a],p);
}

ll costo(ll h, pll p) {
    return p.first*h - p.second;
}

ll queryAns(set<pll>& ch, ll h, ll d){
    if(ch.empty())
        return 0;
    ll lo = 0; //res in [lo,hi)
    ll hi = 2e12;
    while(lo+1 != hi){
        ll m = (lo+hi)/2;
        auto it2 = ch.lower_bound(mp(m-1,1));
        auto it1 = it2;
        if(it1 != ch.begin()) it1--;
        if(it2 == ch.begin() or (it2 != ch.end() and costo(h,*it1) > costo(h,*it2))) lo = m;
        else hi = m;
    }
    auto it = ch.lower_bound(mp(lo-1,1));
    ll res = costo(h,*it);
    res -= h*d;
    return res;
}

vvi hijos;
vector<set<pll>> ch;
vvll querys;

void dfs(int nodo, ll d){
    donde[nodo] = nodo;
    F0(i,hijos[nodo].size()) {
        d += l[hijos[nodo][i]];
        dfs(hijos[nodo][i],d);
        d -= l[hijos[nodo][i]];
        mergear(ch,nodo,hijos[nodo][i]);
    }
    meter(ch[donde[nodo]],mp(d,-queryAns(ch[donde[nodo]],h[nodo],d)));

    F0(i,querys[nodo].size()) {
        res.pb(queryAns(ch[donde[nodo]],querys[nodo][i],d) % mod +1);
    }
}

void d(int tc){
    res.clear();
    int n, m, k;
    cin>>n>>m>>k;
    p = read(n, k, -1);
    l = read(n, k, -2);
    h = read(n, k, -2);
    x = read(m, k, n);
    y = read(m, k, -2);

    hijos = vvi(n);
    for(int i = 0; i < (int) p.size(); ++i) {
        --p[i]; // 0 becomes -1 !!!
        if(i > 0) hijos[p[i]].push_back(i);
    }

    querys = vvll(n);
    F0(i,x.size()){
        x[i]--;
        querys[x[i]].emplace_back(y[i]);
    }

    ch = vector<set<pll>>(n);
    dfs(0,0);

    vll debug = res;
    F1(i,res.size()-1) res[i] = (res[i] * res[i-1]) % mod;
    cout<<"Case #"<<tc<<": "<<res.back()<<'\n';
}
*/

vvi gin,gout;
vi mintran;

ll pow2(ll exp){
    if(exp == 0) return 1;
    ll a = pow2(exp/2);
    a *= a;
    a %= mod;
    if(exp % 2 == 1) a *= 2;
    a %= mod;
    return a;
}

void bfs1(vi& mintran){
    deque<pi> q;
    q.push_back({0,0});
    int nodo,tran;
    while(!q.empty()){
        nodo = q.front().first;
        tran = q.front().second;
        q.pop_front();
        if(mintran[nodo] != -1) continue;
        mintran[nodo] = tran;
        for(auto w : gout[nodo]){
            if(tran%2 == 0) q.push_front({w,tran});
            else q.push_back({w,tran+1});
        }
        for(auto w : gin[nodo]){
            if(tran % 2 == 1) q.push_front({w,tran});
            else q.push_back({w,tran+1});
        }
    }
}

int n,m;

void bfs2(vvi& d){
    vpi qnext;
    qnext.push_back({0,0});
    priority_queue<pi> q;
    int v,mov,i;
    int tran = 0;
    while(tran <= mintran[n-1] + 20){
        F0(i,qnext.size()) q.push(qnext[i]);
        qnext.clear();
        while(!q.empty()){
            mov = -q.top().first;
            v = q.top().second;
            q.pop();
            i = tran - mintran[v];
            if(i >= 20 or d[v][i] != -1) continue;
            d[v][i] = mov;
            if(tran%2 == 0) for(auto w : gout[v]) q.push({-mov-1,w});
            else for(auto w : gin[v]) q.push({-mov-1,w});
            qnext.push_back({-mov,v});
        }
        tran++;
    }
}

void c(){
    cin>>n>>m;
    gin.resize(n);
    gout.resize(n);
    mintran = vi(n,-1);
    int u,v;
    F0(i,m){
        cin>>u>>v;
        u--; v--;
        gout[u].pb(v);
        gin[v].pb(u);
    }

    bfs1(mintran);

    vvi d(n,vi(20,-1));
    bfs2(d);

    ll res = INF;
    if(mintran[n-1] < 10){
        F0(i,20) mini(res,(1ll<<(mintran[n-1]+i))-1 + (ll) d[n-1][i]);
        res %= mod;
    }
    else {
        res = pow2(mintran[n-1]);
        res--;
        res += d[n-1][0];
        res += mod;
        res %= mod;
    }
    cout<<res<<'\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}