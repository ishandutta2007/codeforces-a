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
#include <bitset>

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
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int a[1010];
int u[1010];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		int k = -1;
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if(u[j]) continue;
			if(k == -1 || a[j] > a[k]) {
				k = j;
				cnt += 1;
				u[j] = 1;
			}
		}
		if(cnt==0) break;
		ans += cnt-1;
	}
	cout<<ans << "\n";
}
int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}