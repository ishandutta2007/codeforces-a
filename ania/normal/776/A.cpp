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

string a,b,c,d;
int n;

int main() {
	cin >> a>> b>>n;
	cout << a << " " << b << "\n";
	FOR(i,n) {
		cin >> c >> d;
		if (a==c) a=d;
		else b=d;
		cout << a << " " << b << "\n";
	}
	return 0;
}