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

const lli mod = 998244353LL;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;

const int N=2e5+5;
lli fac[N+5],inv[N+5];

lli po(lli a,lli n)
{
    if(n<0)
    {
        a=po(a,mod-2);
        n*=-1;
    }
    if(n==0)
        return 1;
    if(n%2)
        return (a*po(a,n-1))%mod;
    return po(a*a%mod,n/2);
}

lli nCr(lli n,lli r)
{
    if(n<0||r<0||r>n)
        return 0;
    lli ans=1;
    ans=(ans*fac[n])%mod;
    ans=(ans*inv[r])%mod;
    ans=(ans*inv[n-r])%mod;
    return ans;
}

void pre(lli n)
{
    lli i;
    fac[0]=1;
    repA(i,1,n)
        fac[i]=(i*fac[i-1])%mod;
    inv[n]=po(fac[n],mod-2);
    repD(i,n,1)
        inv[i-1]=(i*inv[i])%mod;
    assert(inv[0]==1);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>k;

    a.clear();a.reserve(n+2);

    a.pb(0);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }
    a.pb(a[1]);
    a[0]=a[n];

    repA(i,1,n)
        cnt+=(a[i]!=a[i-1]);

    pre(cnt);

    lli ans=0;
    repA(i,0,cnt)
    {
        lli v=1;
        v=(v*nCr(cnt,i))%mod;
        v=(v*nCr(cnt-i,i))%mod;
        v=(v*po(k-2,cnt-2*i))%mod;
        ans-=v;
        dbg(v);
    }


    ans%=mod;
    ans*=po(k,n-cnt);
    ans%=mod;
    ans+=po(k,n);
    ans%=mod;
    ans*=(mod+1)/2;
    ans%=mod;
    ans+=mod;
    ans%=mod;

    cout<<ans<<endl;

}   aryanc403();
    return 0;
}