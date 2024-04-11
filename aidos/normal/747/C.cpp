#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int n, q;
int t[111];
void solve(){
	scanf("%d%d", &n, &q);
	for(int i = 0, a, b, c; i < q; i++){
		scanf("%d%d%d", &a, &b, &c);
		int cnt =0;
		for(int j = 0; j < n; j++){
			if(t[j] <= a) cnt++;
		}
		if(cnt < b) {
			printf("-1\n");
			continue;
		}
		int sum = 0;
		for(int j = 0; j < n; j++){
			if(b== 0) break;
			if(t[j] <= a){
				t[j] = a + c;
				sum += j + 1;
				b--;
			}
		}
		printf("%d\n", sum);
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}