#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 400010
#define mod 2147483647
#define int ll
int n,x,a,b,ans;
map<int,int> m;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		ans=n+1;
		m.clear();
		repeat(i,0,n){
			cin>>x;
			if(m.count(x))
				ans=min(ans,i-m[x]+1);
			m[x]=i;
		}
		if(ans==n+1)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}