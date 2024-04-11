#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 17LL;

int n;
int l[N], r[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &l[i], &r[i]);
	
	sort(l + 1, l + n + 1);
	sort(r + 1, r + n + 1);
	
	LL res = n;
	for(int i = 1; i <= n; ++i)
		res += max(l[i], r[i]);
	printf("%lld\n", res);
	return 0;
}