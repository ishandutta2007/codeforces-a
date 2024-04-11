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

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
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

int a[100005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	vi avl(n);
	iota(all(avl),1LL);
	reverse(all(avl));
	vector<pii> ans,avl3;
	queue<pii> avl2;
	int latom=0,la;
	int troll=n;
	for(int i=n; i>0; i--) {
		if(a[i]==1) {
			ans.pb({i,avl.back()});
			avl2.push({i,avl.back()});
			avl.pop_back();
		} else if(a[i]==2) {
//			trace(avl2);
			if(avl2.empty()) {
				cout<<-1<<endl;
				return;
			}
			ans.pb({i,avl2.front().se});
			avl2.pop();
			latom=i;
			la=ans.back().se;
		} else if(a[i]==3) {
			if(latom==0) {
//				trace(latom,avl2);
				if(avl2.empty()) {
					cout<<-1<<endl;
					return;
				}
				ans.pb({i,++troll});
				ans.pb({avl2.front().fi,troll});
				avl2.pop();
				latom=i;
				la=ans.back().se;
			} else {
				ans.pb({latom,++troll});
				ans.pb({i,troll});
				latom=i;
				la=ans.back().se;
			}
		}
	}
	vi comp;
	for(auto i:ans)
		comp.pb(i.se);
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	cout<<sz(ans)<<endl;
	vector<pii> ans2;
	for(auto i:ans) {
		i.se=n+1-(upper_bound(all(comp),i.se)-comp.begin());
//		cout<<i.se<<" "<<i.fi<<endl;
		ans2.pb({i.se,i.fi});
	}
	sort(all(ans2));
	for(auto i:ans2)
		cout<<i.fi<<" "<<i.se<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}