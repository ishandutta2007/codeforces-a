#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
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
#include <stack>
#include <queue>
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
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
inline LL parse(const string & s) { stringstream ss(s); LL x; ss >> x; return x; }
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
#define next asdnext
#define prev asdprev
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
#define hash asdhash
#define move asdmove
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const LL LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
bool isprime(LL a){for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
#define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}

void nope(){
  cout<<"No";
  exit(0);
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);

  int n,m;
  cin>>n>>m;
  LL pl,pr;
  cin>>pl>>pr;
  if(pl>pr)
    nope();
  vector<pair<pll,int>> evs;
  forn(i,n-1){
    LL l,r;
    cin>>l>>r;
    if(l>r)
      nope();
    evs.pb(mp(mp(l-pr,r-pl),i));
    pl=l;
    pr=r;
  }
  forn(i,m){
    LL a;
    cin>>a;
    evs.pb(mp(mp(a,LINF*4),i));
  }
  vector<int> res(n-1);
  set<pll> S;
  sort(all(evs));
  for(auto e:evs){
    LL a=e.X.X;
    LL b=e.X.Y;
    int i=e.Y;
    //cerr<<a<<' '<<b<<' '<<i<<endl;
    if(b==LINF*4){
      auto it=S.begin();
      if(it==S.end())
	continue;
      if(it->X<a)
	nope();
      res[it->Y]=i;
      S.erase(it);
    }else{
      S.insert(mp(b,i));
    }
  }
  if(sz(S))
    nope();
  cout<<"Yes\n";
  forv(i,res){
    cout<<res[i]+1<<' ';
  }
    
  return 0;
}