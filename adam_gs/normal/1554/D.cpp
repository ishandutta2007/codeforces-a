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
	if(n<26) {
		rep(i, n) cout << char('a'+i);
		cout << '\n';
		return;
	}
	rep(i, n/2-1) {
		cout << 'a';
	}
	cout << 'b';
	rep(i, n/2) {
		cout << 'a';
	}
	if(n%2==1) {
		cout << 'c';
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}