//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll q, a, b;
	cin >> q;
	while(q--){
		cin >> a >> b;
		cout << (b-a%b)%b << '\n';
	}
}