#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int t;
	cin >> t;
	while (t--) {
		int n,k=0;
		cin >> n;
		int a[n];
		fop (i,0,n) cin >> a[i];
		int min=a[n-1];
		for (int i=n-2;i>=0;--i) {
			if (a[i]>min) {
				k++;
			} else {
				min=a[i];
			}
		}
		cout << k << endl;
	}
}