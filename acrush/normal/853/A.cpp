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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

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
int n,k;
int a[maxn];
int r[maxn];

void out(int64 n)
{
	if (n>=10) out(n/10);
	printf("%d",(int)(n%10));
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n>>k) 
	{		
		REP(i,n) cin>>a[i];
		int p=0;
		int64 ret=0;
		int64 s=0;
		priority_queue<ipair> heap;
		FOR(i,k,k+n)
		{
			for (;p<n && p<=i;++p) { ret+=(int64)a[p]*(i-p); s+=a[p]; heap.push(MP(a[p],p)); }
			s-=heap.top().first;
			r[heap.top().second]=i;
			heap.pop();
			ret+=s;
		}
		out(ret);
		printf("\n");
		REP(i,n) 
		{
			if (i>0) printf(" ");
			printf("%d",r[i]+1);
		}
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}