/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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

clock_t time_p=clock();
void aryanc403()
{
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

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
const lli maxN = 100000L;
const mytype eps = 1e-12;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,e[maxN+5];
    vector<lli> p;//,pp;

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.Y*sz(e[b.X]) <= b.Y*sz(e[a.X]) );   }};

    priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

vi solve()
{
    vector<bool> vis(n+1,true),ans;
    dbg(p);
    ii bst;
    bst=mp(-1,1);

    repA(i,1,n)
        pq.push({i,p[i]});

    while(!pq.empty())
    {
        auto u=pq.top();pq.pop();
        // dbg(u);
        if(!vis[u.X])
            continue;

        if(bst.X*sz(e[u.X])<bst.Y*p[u.X])
        {
            bst=mp(p[u.X],sz(e[u.X]));
            dbg(bst);
            ans=vis;
        }
        // store if best.

        vis[u.X]=false;
        for(auto x:e[u.X])
        {
            p[x]--;
            pq.push({x,p[x]});
        }
    }

    dbg(ans);

    vi a;
    repA(i,1,n)
        if(ans[i])
            a.pb(i);
    dbg(bst,a);
    // if(bst.X==0)
    // {
    //     a.clear();
    //     repA(i,1,n)
    //         if(pp[i]>=0)
    //             a.pb(i);
    // }
    return a;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m>>k;
    p.resize(n+1,0);

    while(k--)
    {
        cin>>in;
        dbg(in);
        p[in]=-m-10;
    }

    while(m--)
    {
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
        p[u]++;p[v]++;
    }

    // pp=p;

    auto a=solve();
    cout<<sz(a)<<endl;
    for(auto x:a)
        cout<<x<<" ";cout<<endl;

}   aryanc403();
    return 0;
}