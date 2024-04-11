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
int n, k;
string s, t;
void solve(){
	cin >> s >> t;
	int cur=0;
	for(int i = 0; i < t.size(); i++) {
		cur += t[i] - '0';
		cur -= s[i] - '0';
	}
	int ans = 0;
	if(cur % 2 == 0) ans += 1;
	for(int i = t.size(); i < s.size(); i++) {
		cur += s[i-t.size()] - '0';
		cur -= s[i] - '0';
		if(cur % 2 == 0) ans += 1;
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