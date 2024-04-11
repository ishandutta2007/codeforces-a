#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1000010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans=-INF;
ll A[MAXN];
ll B[MAXN];
ll seg[MAXN<<2], lazy[MAXN<<2];
vector<pii> vec[MAXN];

void add_lazy(int id, ll val){
	seg[id]+=val;
	lazy[id]+=val;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void Add(int id, int tl, int tr, int l, int r, ll val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(A, 31, sizeof(A));
	memset(B, 31, sizeof(B));
	cin>>n>>m>>k;
	while (n--){
		cin>>a>>x;
		A[a]=min(A[a], x);
	}
	while (m--){
		cin>>b>>x;
		B[b]=min(B[b], x);
	}
	while (k--){
		cin>>x>>y>>a;
		vec[x].pb({y, a});
	}
	
	for (int i=0; i<MAXN; i++) Add(1, 0, MAXN, i, i+1, -B[i]);
	for (int i=0; i<MAXN; i++){
		ans=max(ans, seg[1]-A[i]);
		for (pii p:vec[i]) Add(1, 0, MAXN, p.first+1, MAXN, p.second);
	}
	cout<<ans<<'\n';
	
	return 0;
}