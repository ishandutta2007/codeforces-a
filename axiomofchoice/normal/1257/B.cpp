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
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>a>>b;
		if(a==1)ans=b==1;
		else if(a<=3)ans=b<=3;
		else ans=1;
		if(ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}