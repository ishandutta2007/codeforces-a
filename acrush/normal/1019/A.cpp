#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

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

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		vector<int> p(n);
		vector<int64> c(n);
		REP(i,n) { cin>>p[i]>>c[i]; --p[i]; }
		int w=0;
		vector<vector<int64>> a(m);
		REP(i,n) 
			if (p[i]==0) w++;
			else a[p[i]].push_back(c[i]);
		REP(i,m) sort(ALL(a[i]));
		int64 ret=1LL<<60;
		FOR(k,1,n+1) if (k+(k-1)*(n-1)>=n)
		{
			vector<int64> b;
			int64 s=0;
			int c=0;
			REP(i,m) 
				if (SIZE(a[i])<k)
					for (int p:a[i]) b.push_back(p);
				else
				{
					REP(j,SIZE(a[i])-(k-1)) s+=a[i][j],++c;
					FOR(j,SIZE(a[i])-(k-1),SIZE(a[i])) b.push_back(a[i][j]);
				}
			int zcnt=k-(w+c);
			if (zcnt>0)
			{
				sort(ALL(b));
				REP(j,zcnt) s+=b[j];
			}
			ckmin(ret,s);
		}
		cout<<ret<<endl;
#ifndef _MSC_VER
			break;
#endif
	}
	return 0;
}