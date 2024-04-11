/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    #pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
#endif

using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    vector<vii> ee(n);
    vi minima(n,INF);
    fo(i,m)
    {
        lli w;
        cin>>u>>v>>w;
        ee[u].pb({v,w});
        minima[u]=min(minima[u],w);
    }

    for(int i=0;i<n;++i){
        vii e;
        for(auto x:ee[i]){
            if(minima[i]+n<=x.Y)
                continue;
            e.pb(x);
        }
        ee[i].swap(e);
    }

    for(int u=0;u<n;++u){
        dbg(u);
        const lli c=minima[u];
        vi dist(n,INF);
        vector<bool> vis(n);
        vector<stack<lli>> pq(n+1);
        for(auto x:ee[u]){
            if(dist[x.X]<=x.Y)
                continue;
            dist[x.X]=x.Y;
            pq[x.Y-c].push(x.X);
        }

        for(int t=0;t<n;++t){
            dbg(t,pq[t].empty());
            while(!pq[t].empty()){
                auto v=pq[t].top();pq[t].pop();
                dbg(v,vis[v],t);
                if(vis[v])
                    continue;
                vis[v]=true;
                if(dist[(v+1)%n]>t+c+1){
                    dist[(v+1)%n]=t+c+1;
                    pq[t+1].push((v+1)%n);
                }
                dbg(dist[v],t+c);
                assert(dist[v]==t+c);
                for(auto x:ee[v]){
                    x.X=(x.X+dist[v])%n;
                    if(x.Y+t>=n)
                        continue;
                    if(dist[x.X]>x.Y+dist[v]){
                        pq[x.Y+t].push(x.X);
                        dist[x.X]=x.Y+dist[v];
                    }
                }
            }
        }

        dist[u]=0;
        for(int i=0;i<n;++i)
            cout<<dist[i]<<" \n"[i+1==n];
    }

}   aryanc403();
    return 0;
}