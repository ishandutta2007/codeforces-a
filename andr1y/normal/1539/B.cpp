//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 1e5+18;
ll a[N], pf[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, q;string s;
	cin >> n >> q >> s;
	for(ll i = 0;i<n;i++){
		a[i] = (s[i]-'a'+1);
		pf[i]=a[i];
		if(i) pf[i]+=pf[i-1];
	}
	while(q--){
		ll l, r;cin >> l >> r;--l, r--;
		ll rs = pf[r] - (l?pf[l-1]:0);
		cout<<rs<<'\n';
	}
}