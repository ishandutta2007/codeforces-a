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

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		VI a(n);
		REP(i,n) cin>>a[i];
		int64 ret1=0;
		int ret2=0;
		unordered_map<int,int> g;
		VI w(1<<20);
		REP(bit,30)
		{
			g.clear();
			vector<int64> r(2);
			if (bit>=10) fill(ALL(w),0);
			REP(k,n)
			{
				int current=(a[k]>>bit);
				if (bit>=10)
				{
					r[current&1]+=w[current^1];
					++w[current];
				}
				else
				{
					auto it=g.find(current^1);
					if (it!=g.end()) r[current&1]+=(it->second);
					++g[current];
				}
			}
			ret1+=min(r[0],r[1]);
			if (r[0]>r[1]) ret2|=(1<<bit);
		}
		printf("%lld %d\n",ret1,ret2);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}