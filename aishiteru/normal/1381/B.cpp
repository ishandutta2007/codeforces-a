#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db
namespace io{
	il char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
	}
	template <class I> 
	il void fr(I &num){
		num=0;register char c=nc();it p=1;
		while(c<'0'||c>'9') c=='-'?p=-1,c=nc():c=nc();
		while(c>='0'&&c<='9') num=num*10+c-'0',c=nc();
		num*=p;
	} 
	template <class I> 
	il I Max(I p,I q){return p>q?p:q;}
	template <class I> 
	il I Min(I p,I q){return p<q?p:q;}
	template <class I> 
	il I A(I x){return x<0?-x:x;}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
const int N=1000005;
int a[N],n,T,b[N],cnt,f[N];
int main(){ 
	scanf("%d",&T);it i,j;
	while(T--){
		scanf("%d",&n),n<<=1,cnt=0;
		for(i=1;i<=n;++i) scanf("%d",&a[i]),f[i]=0;
		for(i=1;i<=n;i=j){
			for(j=i+1;a[j]<a[i]&&j<=n;++j); 
		//	printf("j=%d a[j]=%d i=%d a[i]=%d\n",j,i,a[j],a[i]);
			b[++cnt]=j-i;
		}
	//	for(i=1;i<=cnt;++i) printf("%d ",len[i]);puts("");
		f[0]=1;
		for(i=1;i<=cnt;++i)
			for(j=n;j>=b[i];--j) f[j]|=f[j-b[i]];
		f[n>>1]?puts("YES"):puts("NO");
	}
	return 0;
}