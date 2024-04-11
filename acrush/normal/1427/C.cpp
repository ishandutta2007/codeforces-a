#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;

int solve()
{
	int m,n;
	if (!(cin>>m>>n)) return -1;
	n++;
	VI x(n),y(n),t(n);
	t[0]=0;
	x[0]=y[0]=1;
	FOR(i,1,n) cin>>t[i]>>x[i]>>y[i];
	VI f(n);
	f[0]=n+1;
	FOR(k,1,n)
		for (int i=max(0,k-m*4);i<k;i++)
			if (t[i]+abs(x[i]-x[k])+abs(y[i]-y[k])<=t[k])
				ckmax(f[k],f[i]+1);
	return *max_element(ALL(f))-(n+1);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (1)
	{
		int ret=solve();
		if (ret<0) break;
		printf("%d\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}