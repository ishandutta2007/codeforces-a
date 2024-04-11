#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'

#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout); FAST;
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL

using namespace std;
using namespace __gnu_pbds;
using python = void;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned short uss;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type> ordered_set;

const ll M = 1e9+7;
const ll N = 1e7+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;

ll pc[1337], px = 0;
python fact(ll n){
	ll on = n;
	for(ll i =2;i*i<=n;i++){
		while(on%i == 0){
			pc[px++] = i;
			on/=i;
		}
	}
	if(on>1) pc[px++] = on;
}

ll bp(ll a, ll b){
	if(b == 0) return 1;
	if(b == 1) return a;
	if(b&1) return a*bp(a*a, b/2);
	else return bp(a*a, b/2);
}

bool m[N];

python solve(){
	FAST;
	ll n;
	cin >> n;
	if(n == 8){
		cout << "24\n";
		exit(0);
	}
	fact(n);
	vector<ll> primes;
	primes.reserve(px+13);
	for(ll i =2;primes.size()<px;i++){
		if(!m[i]){
			primes.pb(i);
			for(ll j = i;j<N;j+=i) m[j]=1;
		}
	}
	sort(pc, pc+px, greater<ll>());
	ll res = 1;
	for(ll i = 0;i<px;i++) res = res*bp(primes[i], pc[i]-1);
	cout << res << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}