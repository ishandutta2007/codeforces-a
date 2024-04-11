/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  "An ideal problem has no test data."
  Author - Aryan Choudhary (@aryanc403)
  Ref - https://www.codechef.com/viewsolution/23003967
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
// #define endl "\n"
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
const lli maxN = 200000L;
const lli logN = 20L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y,t;
    lli m;
    string s;
    vi a[maxN+5];
    lli sz[maxN+5];
    bool blocked[maxN+5];
    lli pp[maxN+5],hh[maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli prt(char c,lli u)
{
    cout<<c<<" "<<u<<endl;
    if(c=='!')
        exit(0);
    cin>>u;
    if(u==-1)
        exit(0);
    return u;
}

lli dfs1(lli u,lli p=-1)
{
    sz[u]=1;
    for(auto x:a[u])
    {
        if(x==p||blocked[x])
            continue;
        sz[u]+=dfs1(x,u);
    }
    return sz[u];
}

lli search(lli u,lli size=0,lli p=-1)
{
while(true)
{
    lli best=0;
    lli bigger=u;
    for(auto x:a[u])
    {
        if(x==p||blocked[x])
            continue;
        if(best<sz[x])
        {
            best=sz[x];
            bigger=x;
        }
    }

    if(best<=size/2)
        return u;
    p=u;
    u=bigger;
    // return search(bigger,size,u);
}
}

void getCentroid(lli start,lli dd)
{
    lli sz=dfs1(start);
    lli u=search(start,sz),x;

    if(u==start)
    {
        blocked[u]=true;
        x=prt('s',u);
        if(dd==1)
            prt('!',x);
        getCentroid(x,dd-1);
        return;
    }

    x=prt('d',u);
    bool fl=false;

    if(x==0)
        prt('!',u);

    if(dd==x+hh[u]-hh[start])
    {
        //insubtree of u.
        blocked[pp[u]]=true;
        getCentroid(u,x);
        return;
    }

    for(auto x:a[u])
    {
        if(x==pp[u])
            continue;
        blocked[x]=true;
    }
    getCentroid(start,dd);
}

void dfsParH(lli u,lli par)
{
    pp[u]=par;
    hh[u]=1+hh[par];
    for(auto x:a[u])
    {
        if(x==par)
            continue;
        dfsParH(x,u);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    // repA(i,1,n)
    // {
    //     a[i].clear();
    //     blocked[i]=false;
    // }

    fo(i,n-1)
    {
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }

    dfsParH(1,0);

    lli y=prt('d',1);

    if(y==0)
        prt('!',1);

    getCentroid(1,y);

}   aryanc403();
    return 0;
}