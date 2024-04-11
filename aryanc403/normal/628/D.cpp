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
const lli maxN = 2000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y,d;
    lli m;
    string s;
    vi a;
    lli dp[2][maxN+5][maxN+5];//tight,pos,mod
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli sol(bool fl,lli i,lli rem)
{
    if(i==(lli)s.size())
        return rem==0;
    lli &ans=dp[fl][i][rem];
    if(ans!=-1)
        return ans;
    ans=0;
    lli lim=9;
    if(fl)
        lim=s[i]-'0';

    if(i%2)
    {
        if(lim>=d)
            return ans=sol((lim==d)&&fl,i+1, (rem*10+d)%m );
        else
            return ans=0;
    }

    for(lli x=0;x<=lim;++x)
    {
        if(x==d)
            continue;
        ans+=sol((lim==x)&&fl,i+1,(rem*10+x)%m);
    }
    ans%=mod;
    return ans;
}

bool chk(string s,lli d,lli m)
{
    lli r=0,i,n=(lli)s.size();
    fo(i,n)
    {
        if(i%2&&s[i]-'0'!=d)
            return false;
        if(i%2==0&&s[i]-'0'==d)
            return false;
        r=(r*10+s[i]-'0')%m;
    }
    return r==0;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>m>>d;
    lli ans=0;

    cin>>s;
    memset(dp,-1,2*(maxN+5)*(maxN+5)*sizeof(lli));
    ans-=sol(true,0,0);
    dbg(ans);
    ans+=chk(s,d,m);

    cin>>s;
    memset(dp,-1,2*(maxN+5)*(maxN+5)*sizeof(lli));
    ans+=sol(true,0,0);
    ans%=mod;
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}