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

int64 lcp(const string& s,const string& t)
{
	int k=0;
	for (;k<LENGTH(s) && k<LENGTH(t) && s[k]==t[k];++k);
	return k;
}
void dfs(const string& s,const string& t,vector<int64>& cnt,int depth,int ps,int pt)
{
	int n=LENGTH(s);
	if (ps && pt) { ++cnt[n-depth]; return; }
	if (depth>=n) return;
	for (char c='a';c<='b';c++)
	{
		if (!ps && c<s[depth]) continue;
		if (!pt && c>t[depth]) continue;
		dfs(s,t,cnt,depth+1,ps|(int)(c>s[depth]),pt|(int)(c<t[depth]));
	}
}
int64 solve(int n,int64 m,const string& s,const string& t)
{
	if (m==1) return n;
	m-=2;
	int64 ret=n+n-lcp(s,t);
	vector<int64> c(n+1);
	dfs(s,t,c,0,0,0);
	int64 w=0;
	for (int i=n;i>=0;i--)
	{
		int64 d=c[i]+w;
		if (i==0)
			ret+=min(m,d);
		else
		{
			int64 e=min(m,d);
			m-=e;
			ret+=e*(i+1);
			w=min(m,w+e);
		}
	}
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	int64 m;
	while (cin>>n>>m)
	{
		string s,t;
		cin>>s>>t;
		int64 ret=solve(n,m,s,t);
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}