#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
ll s;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		s=0;
		for(ri i=1;i<=n;++i)scanf("%d",a+i),s+=a[i];
		if(s%n){puts("-1");continue;}
		s/=n;
		ri cnt1=0,cnt2=0;
		for(ri i=1;i<=n;++i)if(a[i]>s)++cnt1;
		printf("%d\n",cnt1);
	}
	return 0;
}