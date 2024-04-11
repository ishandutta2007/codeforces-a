#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 

using namespace std; 

typedef unsigned int uint; 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef unsigned short ushort; 
typedef unsigned char uchar; 
typedef pair<int,int> ipair; 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi=acos(-1.0); 
const double eps=1e-11; 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()

template<class T> T sqr(const T &x) { return x*x; } 
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; } 
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); } 
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; } 

const int maxn=(1<<20);

int n,m;
int s[maxn],t[maxn];
vector<int> g[maxn];
int q[maxn],d[maxn];

bool solve(int cnt)
{
	REP(i,n) g[i].clear();
	REP(i,n) d[i]=0;
	REP(i,cnt) { g[s[i]].push_back(t[i]); d[t[i]]++; }
	int sizeq=0;
	REP(i,n) if (d[i]==0) q[sizeq++]=i;
	REP(cl,sizeq) 
	{
		int k=q[cl];
		for (int p:g[k]) if ((--d[p])==0) q[sizeq++]=p;
	}
	if (sizeq!=n) return false;
	REP(cl,sizeq-1)
	{
		int k=q[cl];
		bool ok=false;
		for (int p:g[k]) if (p==q[cl+1]) ok=true;
		if (!ok) return false;
	}
	return true;
}
int main()
{
#ifdef _MSC_VER
	freopen("d.in","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m;
	REP(i,m) { cin>>s[i]>>t[i]; s[i]--; t[i]--; }
	int low=0,high=m+1;
	for (;low+1<high;)
	{
		int mid=(low+high)/2;
		if (solve(mid))
			high=mid;
		else
			low=mid;
	}
	if (high>m) high=-1;
	printf("%d\n",high);
	return 0;
}