#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pr make_pair
#define pb push_back
#define st first
#define nd second
const int LIM=1e5+7;
const ll MOD=1e9+7;
ll sil[LIM], osil[LIM];
ll pot(ll a,ll b){ll w=1;while(b)if(b%2){w=w*a%MOD;--b;}else{a=a*a%MOD;b/=2;}return w;}
void li(){sil[0]=osil[0]=1;rep(i,LIM-1){sil[i+1]=sil[i]*(i+1)%MOD;osil[i+1]=pot(sil[i+1],MOD-2);}}
ll C(ll n,ll k){if(k>n)return 0;return sil[n]*osil[k]%MOD*osil[n-k]%MOD;}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string x;
		cin >> x;
		int n=x.size(), ans=0;
		x+="XD";
		rep(i, n) if(x[i]!='A') {
			if(x[i]==x[i+1]) {
				++ans;
				x[i+1]='A';
			}
			if(x[i]==x[i+2]) {
				++ans;
				x[i+2]='A';
			}
		}
		cout << ans << '\n';
	}
}