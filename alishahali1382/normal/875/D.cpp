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
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN], L[MAXN], R[MAXN];

bool sub1(int x, int y){ return (x|y)==y;}
bool sub2(int x, int y){ return x!=y && sub1(x, y);}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) for (L[i]=i-1; L[i] && sub1(A[L[i]], A[i]); L[i]=L[L[i]]);
	for (int i=n; i; i--) for (R[i]=i+1; R[i]<=n && sub2(A[R[i]], A[i]); R[i]=R[R[i]]);
	//for (int i=1; i<=n; i++) debug2(i, L[i])
	for (int i=1; i<=n; i++) ans+=(i-L[i])*(R[i]-i);
	ans=n*(n+1)/2-ans;
	cout<<ans<<'\n';
	
	
	return 0;
}