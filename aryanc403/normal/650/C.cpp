/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  "An ideal problem has no test data."
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
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
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

#ifdef ARYANC403
#define dbg(...) { cerr<<"[ "; __aryanc403__(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.X<<","<<x.Y<<")";
}

template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
void __aryanc403__(const string name, Arg1&& arg1){
	cerr << name << " : " << arg1 << " ] " << endl;
}

template <typename Arg1, typename... Args>
void __aryanc403__(const string names, Arg1&& arg1, Args&&... args){
	const string name = names.substr(0,names.find(','));
	cerr<<name<<" : "<<arg1<<" | ";
	__aryanc403__(names.substr(1+(int)name.size()), args...);
}

#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || a.X==b.X && a.Y <= b.Y);   }};

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
const lli maxN = 1000000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    map<lli,vii> a;
    vector<vi> ans;
    lli rm[maxN+5],cm[maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli dfs(vector<bool> &vis,vi &a,const vector<vi> &e,map<lli,lli> &idr,lli u)
{
    if(vis[u])
        return -INF;
    lli ans=-INF;
    a.pb(u);
    vis[u]=true;
    lli x=idr[u];
    if(x>=m)
        ans=max(ans,rm[x-m]);
    else
        ans=max(ans,cm[x]);
    for(auto x:e[u])
        ans=max(ans,dfs(vis,a,e,idr,x));
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    dbg(n,m);
    ans.resize(n,vector<lli>(m,0));
    dbg(ans);
    fo(i,n) fo(j,m)
    {
        cin>>in;
        a[in].pb({i,j});
    }
    dbg(a);
    for(const auto &z:a)
    {
        lli sz=0;
        map<lli,lli> id,mx,idr;
        for(auto x:z.Y)
        {
            auto it=id.find(x.X+m);
            if(it==id.end())
            {
                idr[sz]=x.X+m;
                id[x.X+m]=sz++;
                mx[x.X+m]=0;
            }
            it=id.find(x.Y);
            if(it==id.end())
            {
                idr[sz]=x.Y;
                id[x.Y]=sz++;
                mx[x.Y]=0;
            }
        }
        vector<vi> adj(sz);
        vector<bool> vis(sz,false);
        vi aa;
        for(auto x:z.Y)
        {
            lli u=id[x.X+m],v=id[x.Y];
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dbg(sz,z.X,z.Y,id);
        dbg(adj);

        fo(i,sz)
        {
            if(vis[i])
                continue;
            aa.clear();
            lli y=dfs(vis,aa,adj,idr,i);
            y++;
            dbg(y,aa);
            for(auto x:aa)
                mx[idr[x]]=y;
        }

        dbg(z.X,mx);

        for(auto x:z.Y)
        {
            ans[x.X][x.Y]=max(mx[x.X+m],mx[x.Y]);
            rm[x.X]=max(ans[x.X][x.Y],rm[x.X]);
            cm[x.Y]=max(ans[x.X][x.Y],cm[x.Y]);
        }
    }

    for(const auto a:ans)
    {
        for(auto x:a)
            cout<<x<<" ";
        cout<<endl;
    }

}   aryanc403();
    return 0;
}