#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int a; int b;
	while(~scanf("%d%d", &a, &b)) {
		int n;
		scanf("%d", &n);
		double ans = 1e99;
		rep(i, n) {
			int x; int y;
			scanf("%d%d", &x, &y);
			int v;
			scanf("%d", &v);
			amin(ans, hypot(x - a + 0., y - b + 0.) / v);
		}
		printf("%.10f\n", ans);
	}
	return 0;
}