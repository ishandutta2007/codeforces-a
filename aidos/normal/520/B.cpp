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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int mod = 1000000007;
int n, m;
int used[100100];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n >> m;


    for(int i = 0; i <= 100000; i++)
    	used[i] = inf;
   	queue < int > q;
   	q.push(n);
   	used[n] = 0;
   	while(q.size() > 0){
   		int x = q.front();
   		q.pop();
   		if( x * 2 < 100000 && used[x * 2] > used[x] + 1) {
   			q.push(x * 2);
   			used[x * 2] = used[x] + 1;	
   		}
   		if( x > 1 && used[x-1] > used[x] + 1) {
   			q.push(x - 1);
   			used[x-1] = used[x] + 1;
   		}
   	}
   	cout << used[m] << endl;










    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}