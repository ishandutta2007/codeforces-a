#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
ll pow(ll a,ll b,ll c){ll w=1;while(b){if(b&1)w=(w*a)%c;b/=2;a=(a*a)%c;}return w;}
void solve() {
	int n;
	cin >> n;
	ll T[n];
	rep(i, n) cin >> T[i];
	ll ans=0;
	rep(i, n-1) {
		ans=max(ans, T[i]*T[i+1]);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}