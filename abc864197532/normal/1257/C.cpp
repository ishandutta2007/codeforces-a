#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>


int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, tmp;
		cin >> n;
		vector <int> nums[n];
		fop (i,0,n) {
			cin >> tmp;
			nums[tmp-1].pb(i);
		}
		int minn = INT_MAX;
		fop (i,0,n) {
			if (nums[i].size() <= 1) continue;
			fop (j,1,nums[i].size()) {
				minn = min(minn, nums[i][j] - nums[i][j-1] + 1);
			}
		}
		if (minn != INT_MAX) cout << minn << endl;
		else cout << -1 << endl;
	}
}