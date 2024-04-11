#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 310, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int C[MAXN];
int L[MAXN];
map<int, int> dist;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>L[i];
	for (int i=1; i<=n; i++) cin>>C[i];
	pq.push({dist[0]=0, 0});
	while (!pq.empty()){
		int v=pq.top().second;
		pq.pop();
		for (int i=1; i<=n; i++){
			int x=__gcd(v, L[i]);
			if (!dist.count(x) || dist[x]>dist[v]+C[i]) pq.push({dist[x]=dist[v]+C[i], x});
		}
	}
	if (!dist.count(1)) dist[1]=-1;
	cout<<dist[1]<<'\n';
	
	return 0;
}