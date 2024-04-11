#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, sum;
ll cnt[MAXN][2];
string S;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S>>x>>y;
	if (x<y){
		swap(x, y);
		for (char &c:S) if (c!='?') c='0'+'1'-c;
	}
	n=S.size();
	S="#"+S;
	for (int i=1; i<=n; i++){
		cnt[i][0]=cnt[i-1][0];
		cnt[i][1]=cnt[i-1][1];
		if (S[i]=='1') sum+=(cnt[i-1][0]+t)*x;
		else sum+=cnt[i-1][1]*y;
		if (S[i]!='?') cnt[i][S[i]-'0']++;
		else t++;
	}
	ans=sum;
//	debug(sum)
	ll ted=0;
	for (int i=1; i<=n; i++) if (S[i]=='?'){
		sum-=y*(cnt[i-1][1]+ted) + x*(cnt[n][1]-cnt[i][1]);
//		debug(sum)
		sum+=x*(cnt[i-1][0]) + y*(cnt[n][0]-cnt[i][0]+t-ted-1);
		ted++;
		ans=min(ans, sum);
	}
	cout<<ans<<"\n";
	
	return 0;
}