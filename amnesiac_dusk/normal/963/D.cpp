#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef long long ll;
typedef float f80;
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
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b, int mod) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

/**
 * Description: Suffix Automaton
 * Source: https://cp-algorithms.com/string/suffix-automaton.html
 * Verification: https://www.spoj.com/problems/SUBLEX/
 */

template<int SZ> struct sa {
	struct state {
		int len,link,fpos=-1;
		map<char, int> next;
	};

	state st[SZ*2];
	int sz,last;
	ll ans[SZ*2]; // number of distinct substrings from current pos
	vi gra[SZ*2];

	void extend(char c) {
		int cur=sz++;
		st[cur].len=st[last].len+1;
		st[cur].fpos=st[cur].len-1;
		int p=last;
		while(p!=-1&&!st[p].next.count(c)) {
			st[p].next[c]=cur;
			p=st[p].link;
		}
		if(p==-1) {
			st[cur].link=0;
		} else {
			int q=st[p].next[c];
			if(st[p].len+1==st[q].len) {
				st[cur].link=q;
			} else {
				int clone=sz++;
				st[clone]=st[q];
				st[clone].fpos=-1;
				st[clone].len=st[p].len+1;
				while(p!=-1&&st[p].next[c]==q) {
					st[p].next[c]=clone;
					p=st[p].link;
				}
				st[q].link=st[cur].link=clone;
			}
		}
		last=cur;
	}

	void init(string s) {
		st[0].len=0,st[0].link=-1;
		sz++;
		last=0;
		trav(x,s) extend(x);
	}

	void computelinkgraph() {
		rep(i,1,sz) {
			gra[st[i].link].pb(i);
		}
	}
	void getalloccurences(int state, vi &occur) {
		if(st[state].fpos!=-1)
			occur.pb(st[state].fpos);
		for(int i:gra[state])
			getalloccurences(i,occur);
	}
};



sa<200005> au;
void solve() {
	string s;
	cin>>s;
	au.init(s);
	au.computelinkgraph();
	int n;
	cin>>n;
	fr(i,1,n) {
		int k;
		string m;
		cin>>k>>m;
		int at=0,j=0;
		while(j<sz(m)&&au.st[at].next.find(m[j])!=au.st[at].next.end()) {
			at=au.st[at].next[m[j]];
			j++;
		}
		vi occur;
		if(j==sz(m)) {
			au.getalloccurences(at, occur);
			sort(all(occur));
			if(sz(occur)<k) {
				cout<<-1<<endl;
				continue;
			}
			ll ans=sz(s);
			for(int i=0; i+k-1<sz(occur); i++) {
				ans=min(ans,occur[i+k-1]+sz(m)-occur[i]);
			}
			cout<<ans<<endl;
		} else
			cout<<-1<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
	{
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}