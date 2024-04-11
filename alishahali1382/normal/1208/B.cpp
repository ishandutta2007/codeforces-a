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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
map<int, int> mp;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], mp[A[i]]++;
	
	bool f=1;
	for (pii p:mp) if (p.second>1) f=0;
	if (f) kill(0)
	
	ans=n-1;
	for (int i=0; i<n; i++){
		bool f=1;
		mp.clear();
		for (int j=1; j<=i; j++) if (mp[A[j]]++) f=0;
		if (!f) break ;
		int j=n;
		while (!mp[A[j]] && j>i){
			mp[A[j--]]++;
		}
		//debug2(i, j)
		ans=min(ans, j-i);
	}
	cout<<ans<<'\n';
	
	return 0;
}