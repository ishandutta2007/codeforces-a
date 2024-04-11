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
const LL INF = 1e18 + 9LL;

int n;
char s[N];
int cnt[N];

int main(){
	scanf("%d %s", &n, s + 1);
	for(int i = 1; i <= n; ++i)
		cnt[s[i]]++;
	
	if(n == 1){
		puts("Yes");
		return 0;
	}
	
	for(int i = 'a'; i <= 'z'; ++i)
		if(cnt[i] > 1){
			puts("Yes");
			return 0;
		}
	
	puts("No");
	return 0;
}