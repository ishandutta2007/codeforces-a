#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int t[100100];
int q[100100];

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) {
		scanf("%d", &t[i]);
		q[t[i]]++;
	}
	FORI(i,1010) if (q[i] && q[i+1] && q[i+2]) {
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}