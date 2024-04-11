/* in the name of Anton */

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
#define sz(x) ((lli)(x).size())
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


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vii a;
    map<ii,ii> dp;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

ii query(lli l,lli r)
{
    auto it=dp.find({l,r});
    if(it!=dp.end())
        return it->Y;
    cnt++;
    cout<<"? "<<l<<" "<<r<<endl;
    lli x,f;
    cin>>x;
    if(x==-1)
        exit(0);
    cin>>f;
    dp[{l,r}]={x,f};
    return {x,f};
}

void bf(lli l,lli r,lli x,lli f)
{
    for(lli i=l;i<=r;++i)
    {
        auto y=query(i,i).X;
        if(y==x)
        {
            a.pb({x,f});
            i+=f-1;
            continue;
        }
        a.pb({y,1});
    }
}

void solve(lli l,lli r)
{
    if(l>r)
        return;
    auto cur=query(l,r);
    if(cur.Y==r-l+1)
    {
        a.pb(cur);
        return;
    }

    if(cur.Y==1)
    {
        a.pb(cur);
        solve(l+1,r);
        return;
    }

    lli m=(l+r)/2;
    if(query(l,m)==cur || query(m+1,r)==cur)
    {
        solve(l,m);
        solve(m+1,r);
        return;
    }

    auto ul=query(l,m);
    if(ul.X==cur.X)
    {
        a.pb(cur);
        solve(l,m-ul.Y);
        solve(m-ul.Y+1+cur.Y,r);
        return;
    }

    auto ur=query(m+1,r);
    if(ur.X==cur.X)
    {
        a.pb(cur);
        solve(l,m+ur.Y-cur.Y);
        solve(m+1+ur.Y,r);
        return;
    }
        solve(l,m);
        solve(m+1,r);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    solve(1,n);
    sort(all(a));
    dbg(cnt);
    cout<<"! ";
    for(auto x:a)
        while(x.Y--)
            cout<<x.X<<" ";
    cout<<endl;
}   aryanc403();
    return 0;
}