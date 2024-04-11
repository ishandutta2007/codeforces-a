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
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
string s, t;
int a[200200];
void solve(){
	cin >> n >> m >> s >> t;
	reverse(all(t));
	reverse(all(s));
	for(int i = 0; i < m; i++) {
		if(t[i] == '1') {
			a[i]++;
		}
	}
	for(int i = m-1; i >= 0; i--) {
		a[i] += a[i+1];
	}
	int cur = 1;
	int ans = 0;
	int mod = 998244353;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			ans = (ans + cur * 1ll * a[i]) % mod;
		}
		cur = (cur * 2ll) % mod;
	}
	cout << ans << "\n";
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