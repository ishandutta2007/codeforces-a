#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using VI=vector<int>;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		int n,m;
		cin>>n>>m;
		VI a(n*3);
		VI c;
		REP(i,m)
		{
			int x,y;
			cin>>x>>y;
			--x; --y;
			if (a[x] || a[y]) continue;
			c.push_back(i);
			a[x]=a[y]=1;
		}
		if (SIZE(c)>=n)
		{
			printf("Matching\n");
			REP(i,n) printf("%d ",c[i]+1);
			printf("\n");
		}
		else
		{
			printf("IndSet\n");
			VI p;
			REP(i,n*3) if (!a[i]) p.push_back(i);
			REP(i,n) printf("%d ",p[i]+1);
			printf("\n");
		}
	}
	return 0;
}