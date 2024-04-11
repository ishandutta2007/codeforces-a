#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int n;
	while (~scanf("%d", &n)) {
		char s[200001];
		scanf("%s", s);
		int mask = 0;
		int ans = 0;
		rep(i, n) {
			const char *dirs = "LRUD";
			int d = (int)(strchr(dirs, s[i]) - dirs);
			mask |= 1 << d;
			if ((mask & 3) == 3 || (mask & 12) == 12) {
				++ans;
				mask = 1 << d;
			}
		}
		++ans;
		printf("%d\n", ans);
	}
	return 0;
}