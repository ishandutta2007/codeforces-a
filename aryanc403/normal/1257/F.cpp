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

typedef int lli;
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

#define bcnt(x) __builtin_popcount(x)
const lli mod = 1000000007L;
const lli N = 15;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

template <class T>
void makeUnq(vector<T> &a)
{
    sort(all(a));
    a.resize(unique(all(a))-a.begin());
}

void com(vi &a,map<vi,int> &ans)
{
  const lli lim=(1LL<<N)-1;
  for(lli i=0;i<=lim;++i)
  {
    vi b;
    for(auto x:a)
      b.pb(bcnt((x^i)&lim));
    ans[b]=i;
    // if(i==0)
    //   dbg(b);
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
    a.clear();a.reserve(n);

    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    makeUnq(a);
    n=sz(a);

    // for(auto x:a)
    //   dbg(bcnt(x));

    map<vi,int> fh,sh;
    com(a,fh);
    for(auto &x:a)
      x/=1LL<<N;
    com(a,sh);


    for(auto &v:fh)
    {
      lli mx=0;
      for(auto x:v.X)
        mx=max(mx,x);
      vi b;
      for(lli i=mx;i<=2*N;++i)
      {
        b.clear();
        for(auto x:v.X)
          b.pb(i-x);

        auto it=sh.find(b);
        if(it!=sh.end())
        {
          cout<<(it->Y)*(1LL<<N)+v.Y<<endl;
          exit(0);
        }
      }
    }
    cout<<-1<<endl;
}   aryanc403();
    return 0;
}