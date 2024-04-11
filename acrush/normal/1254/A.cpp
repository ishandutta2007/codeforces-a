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
using VS=vector<string>;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		int n,m,c;
		cin>>n>>m>>c;
		VS a(n);
		REP(i,n) cin>>a[i];

		int cnt=0;
		REP(i,n) REP(j,m) cnt+=(int)(a[i][j]=='R');
		VI gc(c);
		REP(i,c) gc[i]=cnt/(c-i),cnt-=gc[i];

		for (int i=1;i<n;i+=2) reverse(ALL(a[i]));

		string estr;
		for (char c='0';c<='9';c++) estr+=c;
		for (char c='A';c<='Z';c++) estr+=c;
		for (char c='a';c<='z';c++) estr+=c;

		int left=gc[0];
		int idx=0;
		REP(i,n) REP(j,m) 
		{
			if (a[i][j]=='R')
			{
				if (left==0) left=gc[++idx];
				--left;
			}
			a[i][j]=estr[idx];
		}
		for (int i=1;i<n;i+=2) reverse(ALL(a[i]));
		REP(i,n) printf("%s\n",a[i].c_str());
	}
	return 0;
}