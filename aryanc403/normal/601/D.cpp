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
const lli maxN = 300000L;
const lli N = 26L;

struct node{
    node *a[N];
    bool vis[N];
    lli cnt=0;
};

node* NODE()
{
    node* nd=(node*)malloc(sizeof(node));
    lli i;
    fo(i,N)
    {
        nd->a[i]=NULL;
        nd->vis[i]=false;
    }
    nd->cnt=0;
    return nd;
}

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    map<lli,lli> m;
    string s;
    vi a,e[maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

node* merge(node *a,node *b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;

    lli i;
    node *nd=NODE();
    fo(i,N)
    {
        if(a->vis[i]||b->vis[i])
        {
            nd->cnt++;
            nd->vis[i]=true;
        }
        nd->a[i]=merge(a->a[i],b->a[i]);
        if(nd->a[i]!=NULL)
            nd->cnt+=nd->a[i]->cnt;
    }
    return nd;
}

node* dfs(lli u,lli p)
{
    node *nd=NODE();
    for(auto x:e[u])
    {
        if(x==p)
            continue;
        nd=merge(nd,dfs(x,u));
    }
    node* td=NODE();
    td->cnt=nd->cnt+1;
    td->a[s[u]-'a']=nd;
    td->vis[s[u]-'a']=true;
    m[td->cnt+a[u]]++;
    return td;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    a.clear();a.reserve(n+1);
    a.pb(0);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    cin>>s;
    s="0"+s;

    fo(i,n-1)
    {
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(1,-1);

    auto it=m.rbegin();
    cout<<(it->X)<<endl;
    cout<<(it->Y)<<endl;

}   aryanc403();
    return 0;
}