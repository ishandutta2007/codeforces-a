#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    int c = 0;
    fop (i,0,n) cin >> a[i];
    while (true) {
    	lli aa = 0;
    	fop (i,1,n) {
    		if (a[i] >= a[0]) {
    			aa += a[i] - a[0] + 1;
			}
		}
		if (aa <= c) {
			break;
		}
		c++;
		a[0]++;
	}
	cout << c << endl;
}