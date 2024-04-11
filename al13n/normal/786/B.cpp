#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <array>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <forward_list>
#include <thread>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<short, short> pss;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
typedef pair<ld, ld> pdd;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline T parse(const string&s){T x;stringstream ss(s);ss>>x;return x;}
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
#define next asdnext
#define prev asdprev
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define MT make_tuple
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const LL LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL gcdex(LL a,LL b,LL &x,LL &y){if(!a){x=0,y=1;return b;}LL k=b/a;LL g=gcdex(b-k*a,a,y,x);x-=k*y;return g;}
LL inv(LL a,LL m){LL x,y,g;g=gcdex(a,m,x,y);return (x%(m/g)+m/g)%m/g;}
LL crt(LL a1,LL m1,LL a2,LL m2){LL a=(a2-a1%m2+m2)%m2;LL x,y,g;g=gcdex(m1,m2,x,y);if(a%g)return -1;LL m=m1/g*m2;x*=a/g;x=(x%m2+m2)%m2;LL r=(a1+x*m1)%m;assert(r%m1==a1 && r%m2==a2);return r;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
bool isprime(LL a){if(a<=1)return false;for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
LL sqrtup(LL a){if(!a)return 0;LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>=a)--x;while((x+1)*(x+1)<a)++x;return x+1;}
LL isqrt(LL a){LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>a)--x;while((x+1)*(x+1)<=a)++x;return x;}
LL sgn(LL x){return x<0?-1:x>0?1:0;}
template<class T> ostream& operator<<(ostream &s, const vector<T> &v);
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p);
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m);
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a);
template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t);
template<class T> ostream& operator<<(ostream &s, const vector<T> &v){s<<'[';forv(i,v){if(i)s<<',';s<<v[i];}s<<']';return s;}
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p){s<<"("<<p.X<<","<<p.Y<<")";return s;}
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it.X<<": "<<it.Y;}s<<"}";return s;}
template<class T> ostream& operator<<(ostream &s, const set<T> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it;}s<<"}";return s;}
template<class T> ostream& operator<<(ostream &s, const multiset<T> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it;}s<<"}";return s;}
template<class T,class V,class C> ostream& operator<<(ostream &s, const priority_queue<T,V,C> &q) {auto a=q;s<<"{";bool f=false;while(!a.empty()){if(f)s<<",";f=true;s<<a.top();a.pop();}return s<<"}";}
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a){s<<'[';forv(i,a){if(i)s<<',';s<<a[i];}s<<']';return s;}
template<size_t n,class... T> struct put1 { static ostream& put(ostream &s, const tuple<T...> &t){s<<get<sizeof...(T)-n>(t);if(n>1)s<<',';return put1<n-1,T...>::put(s,t);} };
template<class... T> struct put1<0,T...> { static ostream& put(ostream &s, const tuple<T...> &t){return s;} };
template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t){s<<"(";put1<sizeof...(T),T...>::put(s,t);s<<")";return s;}
ostream& put2(ostream &s, const tuple<> &t){return s;}
template<class U> ostream& put2(ostream &s, const tuple<U> &t){return s<<get<0>(t);}
template<class U,class V,class... T> ostream& put2(ostream &s, const tuple<U,V,T...> &t){return s<<t;}
#ifdef __ASD__
auto asdqwet0 = chrono::steady_clock::now();
#define dbg(...) do { \
ios::fmtflags asdqwef=cerr.flags();cerr.setf(ios::fixed,ios::floatfield);cerr.precision(6);double asdqwet = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - asdqwet0).count();cerr << '[' << __LINE__ << ' ' << asdqwet << "] " << #__VA_ARGS__ << " = "; put2(cerr, make_tuple(__VA_ARGS__)); cerr << endl;cerr.flags(asdqwef); }while(false)
#include "draw.h"
#define draw(x) dr::get().add(x)
#define drawc(x) dr::get().x
#else
#define dbg(...) do{}while(false)
#define draw(...) do{}while(false)
#define drawc(...) do{}while(false)
#endif

vector<vector<pll>> G;

int doit0(int p,int a,int b,int k){
  if(b==a+1)
    return k;
  int c=(a+b)/2;
  if(p<c)
    return doit0(p,a,c,k*2+1);
  else
    return doit0(p,c,b,k*2+2);
}

int upv(int a){
  return a*2;
}
int downv(int a){
  return a*2+1;
}

void doit1(int a,int b,int k){
  if(b==a+1){
    G[downv(k)].pb(mp(upv(k),0));
    return;
  }
  int c=(a+b)/2;
  G[downv(k)].pb(mp(downv(k*2+1),0));
  G[downv(k)].pb(mp(downv(k*2+2),0));
  G[upv(k*2+1)].pb(mp(upv(k),0));
  G[upv(k*2+2)].pb(mp(upv(k),0));
  doit1(a,c,k*2+1);
  doit1(c,b,k*2+2);
}

void doit2(int k0,LL w,bool up,int l,int r,int a,int b,int k){
  if(l>=b || r<=a)
    return;
  if(l<=a && r>=b){
    if(up)
      G[upv(k)].pb(mp(k0,w));
    else
      G[k0].pb(mp(downv(k),w));
    return;
  }
  int c=(a+b)/2;
  doit2(k0,w,up,l,r,a,c,k*2+1);
  doit2(k0,w,up,l,r,c,b,k*2+2);
}

int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

  int n,q,S;
  cin>>n>>q>>S;
  --S;
  G.resize(n*8);
  vector<LL> D(n*8,LINF);
  doit1(0,n,0);
  forn(i,q){
    int t;
    cin>>t;
    int v,a,b,w;
    if(t==1){
      cin>>v>>a>>w;
      b=a;
    }else{
      cin>>v>>a>>b>>w;
    }
    --a;
    --v;
    v=doit0(v,0,n,0);
    if(t==3)
      doit2(downv(v),w,true,a,b,0,n,0);
    else
      doit2(upv(v),w,false,a,b,0,n,0);
  }
  dbg(G);

  priority_queue<pll> qu;
  int v0=downv(doit0(S,0,n,0));
  D[v0]=0;
  qu.push(mp(-D[v0],v0));
  while(!qu.empty()){
    LL d=-qu.top().X;
    int v=qu.top().Y;
    qu.pop();
    if(d!=D[v])
      continue;
    for(pll q:G[v]){
      LL dd=d+q.Y;
      if(dd<D[q.X]){
        D[q.X]=dd;
        qu.push(mp(-dd,q.X));
      }
    }
  }
  forn(i,n){
    LL d=D[downv(doit0(i,0,n,0))];
    if(d==LINF)
      cout<<"-1 ";
    else
      cout<<d<<' ';
  }

  return 0;
}