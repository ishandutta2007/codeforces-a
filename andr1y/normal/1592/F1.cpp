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
const ll N = 505;
char a[N][N];
ll b[N][N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	ll s=0;
	for(ll i = 0;i<n;i++){
		for(ll j = 0;j<m;j++){
			cin >> a[i][j];
		}
	}
	for(ll i = 0;i<n;i++){
		for(ll j = 0;j<m;j++){
			ll x = (a[i][j]=='B'?1:0)+(a[i][j+1]=='B'?1:0)+(a[i+1][j]=='B'?1:0)+(a[i+1][j+1]=='B'?1:0);
			x%=2;
			b[i][j] = x;
			s+=x;
		}
	}
	bool f=0;
	for(ll i = 0;i+1<n;i++){
		for(ll j=0;j+1<m;j++){
			if(b[i][j]&&b[n-1][j]&&b[i][m-1]&&b[n-1][m-1]){
				f=1;
			}
		}
	}
	if(f)--s;
	cout<<s;
}