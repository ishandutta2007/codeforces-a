#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int t, n, a[100015], cnt[111];
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		rep(i, 0, 100) cnt[i] = 0;
		rep(i, 1, n) scanf("%d", &a[i]), cnt[abs(a[i])]++;
		int ans = 0;
		rep(i, 0, 100) ans += i > 0 ? min(2, cnt[i]) : min(1, cnt[i]);
		printf("%d\n", ans);
	}
	return 0;
}