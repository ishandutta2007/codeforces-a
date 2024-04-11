#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
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
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<int, lng> PLL;
typedef pair<lng, int> PLI;
typedef pair<ld, ld> PDD;
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
#define pow10 asdpow10
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

int n;
lng V;
lng A[310],B[310];
lng bal[310];
vector<int> gr[310];
bool was[310];
vector<pair<PII,lng> > ans;

void getbal(int v){
	was[v]=true;
	bal[v]=B[v]-A[v];
	for(int i=sz(gr[v])-1;i>=0;--i){
		int p=gr[v][i];
		if(was[p]){
			gr[v].erase(gr[v].begin()+i);
			continue;
		}
		getbal(p);
		bal[v]+=bal[p];
	}
}

void push(int v,int p,int down){
	if(p==-1)
		return;
	lng a=bal[v];
	if(a*down<=0)
		return;
	if(down==1)
		a=min(a,min(A[p],V-A[v]));
	else
		a=-min(-a,min(V-A[p],A[v]));
	if(!a)
		return;
	if(down==1)
		ans.pb(mp(mp(p,v),a));
	else
		ans.pb(mp(mp(v,p),-a));
	A[v]+=a;
	A[p]-=a;
	bal[v]-=a;
}

void flow(int v,int pr){
	push(v,pr,1);
	forv(i,gr[v]){
		int p=gr[v][i];
		flow(p,v);
	}
	push(v,pr,-1);
}

bool docomp(int v0){
	if(was[v0])
		return true;
	getbal(v0);
	if(bal[v0])
		return false;
	
	while(true){
		int s0=sz(ans);
		flow(v0,-1);
		if(sz(ans)==s0)
			break;
	}
	
	return true;
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	int m;
	cin>>n>>V>>m;
	forn(i,n){
		cin>>A[i];
	}
	forn(i,n){
		cin>>B[i];
	}
	forn(i,m){
		int a,b;
		cin>>a>>b;
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	
	forn(i,n){
		if(!docomp(i)){
			cout<<"NO";
			return 0;
		}
	}
	
	cout<<sz(ans)<<'\n';
	forv(i,ans){
		cout<<ans[i].X.X+1<<' '<<ans[i].X.Y+1<<' '<<ans[i].Y<<'\n';
	}
	
	return 0;
}