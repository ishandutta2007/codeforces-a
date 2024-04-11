#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define ssize(x) int(x.size())
template<class A,class B>auto&operator<<(ostream&o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<class T>auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<(", ")+2*!i++<<e;return o<<'}';}
#ifdef DEBUG
#define debug(x...) cerr<<"["#x"]: ",[](auto...$){((cerr<<$<<"; "),...)<<'\n';}(x)
#else
#define debug(...) {}
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tests;
	cin >> tests;
	REP (test, tests) {
		int n, k;
		cin >> n >> k;
		map<char, int> mp;
		REP (i, n) {
			char c;
			cin >> c;
			mp[c]++;
		}
		REP(i, k) {
			int ile = n / k;
			FOR (j, 'a', 'z') {
				if (!ile || !mp[char(j)]) {
					cout << char(j);
					break;
				}
				--ile;
				--mp[char(j)];
			}
		}
		cout << endl;
	}
}