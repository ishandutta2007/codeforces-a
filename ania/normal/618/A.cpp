#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

int t[100100];

void test() {
	int n,q=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		t[q]=1;
		q++;
		while (q>=2 && t[q-1]==t[q-2]) {
			t[q-2]++;
			q--;
		}
	}
	FOR(i,q) printf("%d ", t[i]);
	printf("\n");
}

int main() {
	test();
	return 0;
}