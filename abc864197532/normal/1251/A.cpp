#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		set <char> cc;
		fop (i,0,s.length()) {
			if (s[i] == s[i+1] && i + 1 < s.length()) {
				i++;
			} else {
				cc.insert(s[i]);
			}
		}
		for (auto c : cc) {
			cout << c;
		}
		cout << endl;
	}
}