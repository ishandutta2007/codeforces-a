#include <bits/stdc++.h>
using namespace std; using namespace rel_ops;
/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;*/
#define lll __int128
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
typedef double lf; typedef long double llf; const lf err=1e-11; const lf pi=acos(-1);
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cout<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}
#define fi first
#define se second
inline ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
inline lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
template<typename _> inline _ sqr(_ x){return x*x;}
ostream &operator<<(ostream &o,const pii &x){return o<<'('<<x.fi<<','<<x.se<<')';}
mt19937 rnd(time(0));
//tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t; //
const int N=70;
const int mod=(0?1000000007:998244353);
#define int ll
int T,n,m,x;
int cnt[N];
int find(int i){
	repeat(j,i,63)
	if(cnt[j])
		return j;
	return -1;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		mst(cnt,0);
		repeat(i,0,m){
			cin>>x;
			int p=__builtin_ctz(x);
			cnt[p]++;
		}
		int ans=0,f=1;
		repeat(i,0,63){
			int t=1ll<<i;
			if(n&t){
				int w=find(i);
				if(w==-1){
					f=0;
					break;
				}
				repeat_back(j,i,w){
					cnt[j+1]--;
					cnt[j]+=2;
					ans++;
				}
				cnt[i]--;
				n^=t;
			}
			cnt[i+1]+=cnt[i]/2;
		}
		if(!f)ans=-1;
		cout<<ans<<endl;
	}
	return 0;
}