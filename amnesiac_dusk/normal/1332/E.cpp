/*
sekai no hate sae bokura wa shiranai
kanashi mazu ikiru sube mo mottenai
mezasu kono saki ni matteru yuuki
sore wo te ni shitara owaru yume wo mita
*/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

const int in2=powm(2,mod-2);
pii holve(int a, int b, int n) {
	return {(((powm(a+b,n)+powm(b-a,n))*in2)%mod),(((powm(a+b,n)-powm(b-a,n))*in2)%mod)};
}
void solve() {
	int n,m,l,r;
	cin>>n>>m>>l>>r;
	r=r-l+1;
	int odds=(r+1)/2,evens=r/2;
	int one=(n*m+1)/2,two=(n*m)/2;
	pii a=holve(odds,evens,one);
	pii b=holve(odds,evens,two);
	if((n*m)&1) {
		a.fi+=a.se;
		a.se=0;
		b.fi+=b.se;
		b.se=0;
	}
	cout<<((a.fi*b.fi+a.se*b.se)%mod+mod)%mod<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}