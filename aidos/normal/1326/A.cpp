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

const int inf = (1 << 29) - 1;
const int maxn = (int)1e3 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int n, k;
void solve(){
	cin >> n;
	if(n == 1) {
		cout << "-1\n";
		return;
	}
	if((n-1) % 3 == 0) cout << 4;
	else cout << 2;
	for(int i = 2; i < n; i++) {
		cout << 2;
	}
	cout << 3 << "\n";

}
int main () {

	int t = 1;
   scanf("%d", &t);
    for(int i=1; i<=t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}