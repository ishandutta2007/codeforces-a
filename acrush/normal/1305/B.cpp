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

void solve(string s)
{
	int n=LENGTH(s);
	int l1=0;
	for (;l1<n && s[l1]==')';l1++);
	int l2=0;
	for (;l2<n && s[n-1-l2]=='(';l2++);
	if (l1+l2==n)
	{
		printf("0\n");
		return;
	}
	VI r;
	int c=0,d=0;
	REP(i,n) if (s[i]==')') ++d;
	REP(i,n)
	{
		if (s[i]=='(') ++c;
		else --d;
		if (c==d)
		{
			printf("1\n");
			REP(j,i+1) if (s[j]=='(') r.push_back(j);
			FOR(j,i+1,n) if (s[j]==')') r.push_back(j);
			printf("%d\n",SIZE(r));
			REP(i,SIZE(r)) printf("%d ",r[i]+1);
			printf("\n");
			return;
		}
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	string s;
	while (cin>>s)
	{
		solve(s);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}